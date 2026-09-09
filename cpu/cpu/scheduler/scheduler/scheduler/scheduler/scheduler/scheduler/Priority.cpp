#include "Scheduler.h"
#include <queue>

struct ComparePriority {
    bool operator()(const Process* a, const Process* b) {
        if (a->priority == b->priority)
            return a->arrival_time > b->arrival_time;
        return a->priority > b->priority;
    }
};

class PriorityScheduler : public Scheduler {
private:
    std::priority_queue<Process*, std::vector<Process*>, ComparePriority> ready_queue;
    bool preemptive;

public:
    PriorityScheduler(bool is_preemptive = false) : preemptive(is_preemptive) {}

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
        return preemptive;
    }
};