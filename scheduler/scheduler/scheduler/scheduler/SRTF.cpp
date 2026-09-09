#include "Scheduler.h"
#include <queue>

struct CompareSRTF {
    bool operator()(const Process* a, const Process* b) {
        if (a->remaining_time == b->remaining_time)
            return a->arrival_time > b->arrival_time;
        return a->remaining_time > b->remaining_time;
    }
};

class SRTFScheduler : public Scheduler {
private:
    std::priority_queue<Process*, std::vector<Process*>, CompareSRTF> ready_queue;

public:
    void addProcess(Process* p) override {
        ready_queue.push(p);
    }

    Process* getNextProcess() override {
        if (ready_queue.empty()) return nullptr;
        Process* p = ready_queue.top();
        ready_queue.pop();
        return p;
    }

    bool isEmpty() const override {
        return ready_queue.empty();
    }

    bool isPreemptive() const override {
        return true;
    }
};