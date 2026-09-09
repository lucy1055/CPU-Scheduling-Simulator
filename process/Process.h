#ifndef PROCESS_H
#define PROCESS_H

enum class ProcessState { READY, RUNNING, COMPLETED };

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;

    int start_time = -1;
    int finish_time = 0;
    int waiting_time = 0;
    int turnaround_time = 0;
    int response_time = 0;

    ProcessState state = ProcessState::READY;

    Process(int p_id, int arr, int burst, int prio = 0)
        : id(p_id), arrival_time(arr), burst_time(burst),
          remaining_time(burst), priority(prio) {}
};

#endif