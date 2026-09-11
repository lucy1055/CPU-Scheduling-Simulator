//Scheduler
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "../process/Process.h"

class Scheduler {
public:
    virtual void addProcess(Process* p) = 0;
    virtual Process* getNextProcess() = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isPreemptive() const { return false; }
    virtual ~Scheduler() = default;
};

#endif