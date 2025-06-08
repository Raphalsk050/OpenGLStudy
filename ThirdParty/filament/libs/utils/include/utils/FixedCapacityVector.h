
#ifndef TNT_UTILS_FIXEDCAPACITYVECTOR_H
#define TNT_UTILS_FIXEDCAPACITYVECTOR_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/compressed_pair.h"
#include "third_party/filament/libs/utils/include/utils/Panic.h"

#include <initializer_list>
#include <iterator>
#include <limits>
#include <memory>
#include <type_traits>
#include <utility>

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#ifndef NDEBUG
#define FILAMENT_FORCE_CAPACITY_CHECK true
#else
#define FILAMENT_FORCE_CAPACITY_CHECK false
#endif

namespace utils {

template<typename T, typename A = std::allocator<T>, bool CapacityCheck = true>
class UTILS_PUBLIC FixedCapacityVector {
public:
    using allocator_type = A;
    using value_type = T;
    using reference = T&;
    using const_reference = T const&;
    using size_type = uint32_t;
    using difference_type = int32_t;
    using pointer = T*;
    using const_pointer = T const*;
    using iterator = pointer;
    using const_iterator = const_pointer;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

private:
    using storage_traits = std::allocator_traits<allocator_type>;

public:
