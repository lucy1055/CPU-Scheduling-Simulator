#include "Scheduler.h"
#include <queue>

struct CompareSJF {
    bool operator()(const Process* a, const Process* b) {
        if (a->burst_time == b->burst_time)
            return a->arrival_time > b->arrival_time;
        return a->burst_time > b->burst_time;
    }
};

class SJFScheduler : public Scheduler {
private:
    std::priority_queue<Process*, std::vector<Process*>, CompareSJF> ready_queue;

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
};