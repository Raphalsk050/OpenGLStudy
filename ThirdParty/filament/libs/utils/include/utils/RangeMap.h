
#ifndef TNT_UTILS_RANGEMAP_H
#define TNT_UTILS_RANGEMAP_H

#include "third_party/filament/libs/utils/include/utils/Panic.h"
#include "third_party/filament/libs/utils/include/utils/Range.h"
#include "third_party/filament/libs/utils/include/utils/debug.h"

#include <map>
#include <utility>

#include <stddef.h>

namespace utils {

template<typename KeyType, typename ValueType>
class RangeMap {
public:
    void add(KeyType first, KeyType last, const ValueType& value) noexcept {
        // First check if an existing range contains "first".
        Iterator iter = findRange(first);
        if (iter != end()) {
            const Range<KeyType> existing = getRange(iter);
            // Check if the existing range be extended.
            if (getValue(iter) == value) {
                if (existing.last < last) {
                    wipe(existing.last, last);
                    iter = shrink(iter, existing.first, last);
                    mergeRight(iter);
                }
                return;
            }
            // Split the existing range into two ranges.
            if (last < existing.last && first > existing.first) {
                iter = shrink(iter, existing.first, first);
                insert(first, last, value);
                insert(last, existing.last, getValue(iter));
                return;
            }
            clear(first, last);
            insert(first, last, value);
            return;
        }

        // Check if an existing range contains the end of the new range.
        KeyType back = last;
        iter = findRange(--back);
        if (iter == end()) {
            wipe(first, last);
            insert(first, last, value);
            return;
        }
        const Range<KeyType> existing = getRange(iter);

        // Check if the existing range be extended.
        if (getValue(iter) == value) {
            if (existing.first > first) {
                wipe(first, existing.first);
                iter = shrink(iter, first, existing.last);
                mergeLeft(iter);
            }
            return;
        }

        // Clip the beginning of the existing range and potentially remove it.
        if (last < existing.last) {
            shrink(iter, last, existing.last);
        }
        wipe(first, last);
        insert(first, last, value);
    }

    void set(KeyType key, const ValueType& value) noexcept {
        KeyType begin = key;
        add(begin, ++key, value);
    }

    bool has(KeyType key) const noexcept {
        return findRange(key) != mMap.end();
    }

    const ValueType& get(KeyType key) const {
        ConstIterator iter = findRange(key);
        FILAMENT_CHECK_PRECONDITION(iter != end())
                << "RangeMap: No element exists at the given key.";
        return getValue(iter);
    }

    void clear(KeyType first, KeyType last) noexcept {
        // Check if an existing range contains "first".
        Iterator iter = findRange(first);
        if (iter != end()) {
            const Range<KeyType> existing = getRange(iter);
            // Split the existing range into two ranges.
            if (last < existing.last && first > existing.first) {
                iter = shrink(iter, existing.first, first);
                insert(last, existing.last, getValue(iter));
                return;
            }
            // Clip one of the ends of the existing range or remove it.
            if (first > existing.first) {
                shrink(iter, existing.first, first);
            } else if (last < existing.last) {
                shrink(iter, last, existing.last);
            } else {
                wipe(first, last);
            }
            // There might be another range that intersects the cleared range, so try again.
            clear(first, last);
            return;
        }

        // Check if an existing range contains the end of the new range.
        KeyType back = last;
        iter = findRange(--back);
        if (iter == end()) {
            wipe(first, last);
            return;
        }
        const Range<KeyType> existing = getRange(iter);

        // Clip the beginning of the existing range and potentially remove it.
        if (last < existing.last) {
            shrink(iter, last, existing.last);
        }
        wipe(first, last);
    }

    void reset(KeyType key) noexcept {
        KeyType begin = key;
        clear(begin, ++key);
    }

    size_t rangeCount() const noexcept { return mMap.size(); }

private:

    using Map = std::map<KeyType, std::pair<Range<KeyType>, ValueType>>;
    using Iterator = typename Map::iterator;
    using ConstIterator = typename Map::const_iterator;

    ConstIterator begin() const noexcept { return mMap.begin(); }
    ConstIterator end() const noexcept { return mMap.end(); }

    Iterator begin() noexcept { return mMap.begin(); }
    Iterator end() noexcept { return mMap.end(); }

    Range<KeyType>& getRange(Iterator iter) const { return iter->second.first; }
    ValueType& getValue(Iterator iter) const { return iter->second.second; }

    const Range<KeyType>& getRange(ConstIterator iter) const { return iter->second.first; }
    const ValueType& getValue(ConstIterator iter) const { return iter->second.second; }

    // Private helper that assumes there is no existing range that overlaps the given range.
    void insert(KeyType first, KeyType last, const ValueType& value) noexcept {
        assert_invariant(!has(first));
        assert_invariant(!has(last - 1));

        // Check if there is an adjacent range to the left than can be extended.
        KeyType previous = first;
        if (Iterator iter = findRange(--previous); iter != end() && getValue(iter) == value) {
            getRange(iter).last = last;
            mergeRight(iter);
            return;
        }

        // Check if there is an adjacent range to the right than can be extended.
        if (Iterator iter = findRange(last); iter != end() && getValue(iter) == value) {
            getRange(iter).first = first;
            return;
        }

        mMap[first] = {Range<KeyType> { first, last }, value};
    }

    // Private helper that erases all intervals that are wholly contained within the given range.
    // Note that this is quite different from the public "clear" method.
    void wipe(KeyType first, KeyType last) noexcept {
        // Find the first range whose beginning is greater than or equal to "first".
        Iterator iter = mMap.lower_bound(first);
        while (iter != end() && getRange(iter).first < last) {
            KeyType existing_last = getRange(iter).last;
            if (existing_last > last) {
                break;
            }
            iter = mMap.erase(iter);
        }
    }

    // Checks if there is range to the right that touches the given range.
    // If so, erases it, extends the given range rightwards, and returns true.
    bool mergeRight(Iterator iter) {
        Iterator next = iter;
        if (++next == end() || getValue(next) != getValue(iter)) {
            return false;
        }
        if (getRange(next).first != getRange(iter).last) {
            return false;
        }
        getRange(iter).last = getRange(next).last;
        mMap.erase(next);
        return true;
    }

    // Checks if there is range to the left that touches the given range.
    // If so, erases it, extends the given range leftwards, and returns true.
    bool mergeLeft(Iterator iter) {
        Iterator prev = iter;
        if (--prev == end() || getValue(prev) != getValue(iter)) {
            return false;
        }
        if (getRange(prev).last != getRange(iter).first) {
            return false;
        }
        getRange(iter).first = getRange(prev).first;
        mMap.erase(prev);
        return true;
    }

    // Private helper that clips one end of an existing range.
    Iterator shrink(Iterator iter, KeyType first, KeyType last) {
        assert_invariant(first < last);
        assert_invariant(getRange(iter).first == first || getRange(iter).last == last);
        std::pair<utils::Range<KeyType>, ValueType> value = {{first, last}, iter->second.second};
        mMap.erase(iter);
        return mMap.insert({first, value}).first;
    }

    // If the given key is encompassed by an existing range, returns an iterator for that range.
    // If no encompassing range exists, returns end().
    ConstIterator findRange(KeyType key) const noexcept {
        return findRangeT<ConstIterator>(*this, key);
    }

    // If the given key is encompassed by an existing range, returns an iterator for that range.
    // If no encompassing range exists, returns end().
    Iterator findRange(KeyType key) noexcept {
        return findRangeT<Iterator>(*this, key);
    }

    // This template method allows us to avoid code duplication for const and non-const variants of
    // findRange.  C++17 has "std::as_const()" but that would not be helpful here, as we would still
    // need to convert a const iterator to a non-const iterator.
    template<typename IteratorType, typename SelfType>
    static IteratorType findRangeT(SelfType& instance, KeyType key) noexcept {
        // Find the first range whose beginning is greater than or equal to the given key.
        IteratorType iter = instance.mMap.lower_bound(key);
        if (iter != instance.end() && instance.getRange(iter).contains(key)) {
            return iter;
        }
        // If that was the first range, or if the map is empty, return false.
        if (iter == instance.begin()) {
            return instance.end();
        }
        // Check the range immediately previous to the one that was found.
        return instance.getRange(--iter).contains(key) ? iter : instance.end();
    }

    // This maps from the start value of each range to the range itself.
    Map mMap;
};

} // namespace utils

#endif // TNT_UTILS_RANGEMAP_H
