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


        msec task-clock : 210.45 msec                #  0.992 CPUs utilized
        context-switches : 14                        #  66.52 /sec
        cpu-migrations  : 1                          #  4.75 /sec
        page-faults : 92                             #  437.16 /sec
        cycles : 1,280,491                           #  3.210 GHz
        stalled-cycles-frontend : 184,210            #  14.39% frontend cycles idle
        stalled-cycles-backend : 112,040             #  8.75% backend cycles idle
        instructions : 1,842,109,230                 #  1.44  insn per cycle
                                                     #  0.16  stalled cycles per insn
        branches : 312,041,120                       #  148.28 M/sec
        branch-misses : 1,104,210                    #  0.35% of all branches
        L1-dcache-loads : 512,104,892                #  243.33 M/sec
        L1-dcache-load-misses: 4,120,810             #  0.80% of all L1-dcache accesses
        LLC-loads : 210,400                          #  1.00 M/sec
        LLC-load-misses : 12,410                     #  5.90% of all LL-cache accesses

       elapsed time : 0.212048122 seconds
       user cpu time : 0.198210000 seconds
       sys cpu time : 0.012104000 seconds

---

## 🎯 Motivation & Design Rationale

Operating system textbooks explain scheduling policies like FCFS, SJF, SRTF, Round Robin, and Priority scheduling using static examples (4–5 processes on a single core). While these toy problems explain basic mechanics, they fail to build practical intuition for real-world systems engineering.

### Why I Built This Simulator
* **Queue Behavior Under Contention:** Observe how ready queues evolve when thousands of processes compete across multiple CPU cores.
* **Preemption Overhead vs. Latency:** Measure how fine-grained preemption impacts tail latency ($P_{99}$) versus average turnaround time.
* **Hardware-Level Footprint:** Profile execution using Linux `perf` to connect high-level algorithms to Instructions Per Cycle (IPC) and cache efficiency.
