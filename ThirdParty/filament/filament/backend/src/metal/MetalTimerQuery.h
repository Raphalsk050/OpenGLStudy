
#ifndef TNT_FILAMENT_DRIVER_METALTIMERQUERY_H
#define TNT_FILAMENT_DRIVER_METALTIMERQUERY_H

#import <Metal/Metal.h>

#include <chrono>

namespace filament {
namespace backend {

struct MetalTimerQuery;
struct MetalContext;

class MetalTimerQueryInterface {
public:
    virtual ~MetalTimerQueryInterface();
    virtual void beginTimeElapsedQuery(MetalTimerQuery* query) = 0;
    virtual void endTimeElapsedQuery(MetalTimerQuery* query) = 0;
    virtual bool getQueryResult(MetalTimerQuery* query, uint64_t* outElapsedTime) = 0;

protected:
    using clock = std::chrono::steady_clock;
};

// Uses MTLSharedEvents to implement timer queries.
// Only available on >= iOS 12.0.
class API_AVAILABLE(ios(12.0)) MetalTimerQueryFence : public MetalTimerQueryInterface {
public:
    explicit MetalTimerQueryFence(MetalContext& context) : mContext(context) {}

    void beginTimeElapsedQuery(MetalTimerQuery* query) override;
    void endTimeElapsedQuery(MetalTimerQuery* query) override;
    bool getQueryResult(MetalTimerQuery* query, uint64_t* outElapsedTime) override;

private:
    MetalContext& mContext;
};

class TimerQueryNoop : public MetalTimerQueryInterface {
public:
    void beginTimeElapsedQuery(MetalTimerQuery* query) override {}
    void endTimeElapsedQuery(MetalTimerQuery* query) override {}
    bool getQueryResult(MetalTimerQuery* query, uint64_t* outElapsedTime) override;
};

} // namespace backend
} // namespace filament

#endif //TNT_FILAMENT_DRIVER_METALTIMERQUERY_H
