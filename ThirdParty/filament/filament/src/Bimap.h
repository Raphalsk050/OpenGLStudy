
#ifndef TNT_FILAMENT_BIMAP_H
#define TNT_FILAMENT_BIMAP_H

#include "third_party/filament/libs/utils/include/utils/debug.h"

#include "robin_map/include/tsl/robin_map.h"

#include <functional>
#include <memory>
#include <utility>

#include <stddef.h>

namespace filament {

template<typename Key, typename Value,
        typename KeyHash = std::hash<Key>,
        typename ValueHash = std::hash<Value>,
        typename Allocator = std::allocator<Key>>
class Bimap {

    struct KeyDelegate {
        Key const* pKey = nullptr;
        bool operator==(KeyDelegate const& rhs) const noexcept {
            return *pKey == *rhs.pKey;
        }
    };

    // KeyWrapperHash delegates the hash computation to KeyHash
    struct KeyHasherDelegate {
        size_t operator()(KeyDelegate const& p) const noexcept {
            KeyHash const h;
            return h(*p.pKey);
        }
    };

    using ForwardMap = tsl::robin_map<KeyDelegate, Value, KeyHasherDelegate>;
    using BackwardMap = tsl::robin_map<Value, KeyDelegate, ValueHash>;

    Allocator mAllocator;
    ForwardMap mForwardMap;
    BackwardMap mBackwardMap;

public:
    Bimap() = default;
    explicit Bimap(Allocator&& allocator)
            : mAllocator(std::forward<Allocator>(allocator)) {
    }

    void reserve(size_t capacity) {
        mForwardMap.reserve(capacity);
        mBackwardMap.reserve(capacity);
    }

    bool empty() const noexcept {
        return mForwardMap.empty() && mBackwardMap.empty();
    }

    // insert a new key/value pair
    void insert(Key const& key, Value const& value) noexcept {
        Key* pKey = mAllocator.allocate(1); // allocate storage for the key
        new((void*)pKey) Key{ key }; // copy-construct the key
        mForwardMap.insert({{ pKey }, value });
        mBackwardMap.insert({ value, { pKey }});
    }

    typename ForwardMap::iterator end() { return mForwardMap.end(); }

    // Find the value iterator from the key in O(1)
    typename ForwardMap::const_iterator find(Key const& key) const {
        return mForwardMap.find(KeyDelegate{ .pKey = &key });
    }
    typename ForwardMap::iterator find(Key const& key) {
        return mForwardMap.find(KeyDelegate{ .pKey = &key });
    }

    // Find the key iterator from the value in O(1). precondition, the value must exist.
    typename BackwardMap::const_iterator find(Value const& value) const {
        auto pos = mBackwardMap.find(value);
        assert_invariant( pos != mBackwardMap.end() );
        return pos;
    }
    typename BackwardMap::iterator find(Value& value) const {
        return mBackwardMap.find(value);
    }

    // erase a key/value pair using an iterator to the value
    void erase(typename BackwardMap::const_iterator it) {
        // find the key
        Key const& key = *(it->second.pKey);
        // and its iterator
        auto pos = find(key);
        // destroy the key
        it->second.pKey->~Key();
        // free its memory
        mAllocator.deallocate(const_cast<Key *>(it->second.pKey), 1);
        // remove the entries from both maps
        mForwardMap.erase(pos);
        mBackwardMap.erase(it);
    }
};

} // namespace filament


#endif // TNT_FILAMENT_BIMAP_H
