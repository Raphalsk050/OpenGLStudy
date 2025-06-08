
#ifndef TNT_FILAMENT_DOWNCAST_H
#define TNT_FILAMENT_DOWNCAST_H


#define FILAMENT_DOWNCAST(CLASS)                                    \
    inline F##CLASS& downcast(CLASS& that) noexcept {               \
        return static_cast<F##CLASS &>(that);                       \
    }                                                               \
    inline const F##CLASS& downcast(const CLASS& that) noexcept {   \
        return static_cast<const F##CLASS &>(that);                 \
    }                                                               \
    inline F##CLASS* downcast(CLASS* that) noexcept {               \
        return static_cast<F##CLASS *>(that);                       \
    }                                                               \
    inline F##CLASS const* downcast(CLASS const* that) noexcept {   \
        return static_cast<F##CLASS const *>(that);                 \
    }

#endif // TNT_FILAMENT_DOWNCAST_H
