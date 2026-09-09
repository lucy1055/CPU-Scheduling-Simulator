#ifndef CPU_H
#define CPU_H

#include "../process/Process.h"

class CPU {
public:
    int core_id;
    Process* current_process = nullptr;
    bool is_busy = false;
    int total_active_ticks = 0;

    CPU(int id) : core_id(id) {}
    void assignProcess(Process* p);
    void releaseProcess();
};

#endif