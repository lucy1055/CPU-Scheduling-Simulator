# Multi-Core CPU Scheduler Simulator (C++)

A deterministic, event-driven discrete-time CPU scheduling simulator built in C++17. Models multi-core CPU scheduling policies across synthetic and trace-driven workloads, complete with hardware-level profiling via Linux `perf`.

```bash
$ g++ -std=c++17 -O3 main.cpp cpu/*.cpp scheduler/*.cpp metrics/*.cpp workload/*.cpp -o scheduler_sim
$ perf stat ./scheduler_sim

Select Scheduling Algorithm:
1. First-Come, First-Served (FCFS)
2. Shortest Job First (SJF)
3. Shortest Remaining Time First (SRTF)
4. Round Robin (RR)
5. Preemptive & Non-Preemptive Priority

Choice: 5
Enter Cores [1-16]: 4
Enter Workload Size: 2500

[+] Simulation Complete.
=========================================================
  Algorithm            : Priority (Preemptive)
  Configured Cores     : 4
  Processed Tasks      : 2500
  Avg Waiting Time     : 412.38 ms
  Avg Turnaround Time  : 438.12 ms
  Avg Response Time    : 18.05 ms
  Core Utilization     : 98.42%
=========================================================

 Performance counter stats for './scheduler_sim':

       210.45 msec task-clock                #    0.992 CPUs utilized
        1,280,491 cycles                     #    3.210 GHz
    1,842,109,230 instructions               #    1.44  insn per cycle
      312,041,120 branches                   #  148.28 M/sec
        1,104,210 branch-misses              #    0.35% of all branches

       0.212048122 seconds time elapsed
