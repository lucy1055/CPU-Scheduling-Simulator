#include "Scheduler.h"
#include <queue>

class FCFSScheduler : public Scheduler {
private:
    std::queue<Process*> ready_queue;

public:
    void addProcess(Process* p) override {
        ready_queue.push(p);
    }

    Process* getNextProcess() override {
        if (ready_queue.empty()) return nullptr;
        Process* p = ready_queue.front();
        ready_queue.pop();
        return p;
    }

    bool isEmpty() const override {
        return ready_queue.empty();
    }
};