#include "CPU.h"

void CPU::assignProcess(Process* p) {
    current_process = p;
    is_busy = true;
}

void CPU::releaseProcess() {
    current_process = nullptr;
    is_busy = false;
}