
#ifndef SRC_PROGRESS_UPDATER_H
#define SRC_PROGRESS_UPDATER_H

#include <condition_variable>
#include <functional>
#include <iomanip>
#include <iostream>
#include <thread>
#include <vector>

class ProgressUpdater {
public:
    explicit ProgressUpdater(size_t numProgressBars) : mNumBars(numProgressBars) {
    }

    void start();
    void stop();

    void update(size_t progressBarIndex, float value);
    void update(size_t progressBarIndex, size_t value, size_t max);

private:
    struct Update {
        size_t index;
        float value;
    };

    void initProgressValues();
    void printProgressBars();
    void printUpdates();
    void printUpdates(const std::vector<Update>& updates);

    size_t mNumBars;
    std::vector<float> mProgress;

    std::mutex mMutex;
    std::condition_variable mCondition;

    std::vector<Update> mUpdates;
    std::thread mThread;
    bool mExitRequested = false;
};

#endif // SRC_PROGRESS_UPDATER_H
