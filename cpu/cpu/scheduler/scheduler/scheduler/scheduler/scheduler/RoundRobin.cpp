#include "Scheduler.h"
#include <queue>

class RoundRobinScheduler : public Scheduler {
private:
    std::queue<Process*> ready_queue;
    int time_quantum;

public:
    RoundRobinScheduler(int tq = 2) : time_quantum(tq) {}

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

    int getTimeQuantum() const {
        return time_quantum;
    }
};