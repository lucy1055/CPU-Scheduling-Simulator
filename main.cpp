#include <iostream>
#include <vector>
#include <algorithm>
#include "process/Process.h"
#include "cpu/CPU.h"
#include "scheduler/Scheduler.h"
#include "scheduler/FCFS.cpp"
#include "metrics/Metrics.h"
#include "workload/WorkloadGenerator.cpp"

int main() {
    int num_cores = 4;
    int process_count = 2500;

    std::cout << "Initializing Multi-Core CPU Scheduling Simulator...\n";
    std::vector<Process> processes = WorkloadGenerator::generateRandomWorkload(process_count);

    std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrival_time < b.arrival_time;
    });

    FCFSScheduler scheduler;
    std::vector<CPU> cores;
    for (int i = 0; i < num_cores; ++i) {
        cores.emplace_back(i);
    }

    int current_tick = 0;
    size_t completed_count = 0;
    size_t arrival_idx = 0;

    while (completed_count < processes.size()) {
        // 1. Task Arrival
        while (arrival_idx < processes.size() && processes[arrival_idx].arrival_time <= current_tick) {
            scheduler.addProcess(&processes[arrival_idx]);
            arrival_idx++;
        }

        // 2. Dispatching
        for (auto& core : cores) {
            if (!core.is_busy && !scheduler.isEmpty()) {
                Process* p = scheduler.getNextProcess();
                core.assignProcess(p);
                p->state = ProcessState::RUNNING;

                if (p->start_time == -1) {
                    p->start_time = current_tick;
                }
            }
        }

        // 3. Tick Execution
        for (auto& core : cores) {
            if (core.is_busy) {
                core.current_process->remaining_time--;
                core.total_active_ticks++;

                if (core.current_process->remaining_time == 0) {
                    core.current_process->finish_time = current_tick + 1;
                    core.current_process->turnaround_time = core.current_process->finish_time - core.current_process->arrival_time;
                    core.current_process->waiting_time = core.current_process->turnaround_time - core.current_process->burst_time;
                    core.current_process->response_time = core.current_process->start_time - core.current_process->arrival_time;
                    core.current_process->state = ProcessState::COMPLETED;

                    core.releaseProcess();
                    completed_count++;
                }
            }
        }
        current_tick++;
    }

    Metrics::printSummary(processes, current_tick, num_cores);
    return 0;
}