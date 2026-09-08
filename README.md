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

```
## WHY I BUILD THIS PROJECT
 I understand the scheduling algorithms like `FCFS`, `SJF`, `SRTF`, `Round Robin`, and `Priority` theoretically using static 4–5 process examples. But i don't know how to do internally in the system so, I built a CPU scheduling simulator in `C++` that allows different scheduling policies to be tested against a configurable workload of processes.

My goal is to observe :
* **Queue Dynamics:** How ready queues evolve when **2,500+ tasks** compete across multiple CPU cores.
* **Preemption Overhead:** How preemptive scheduling impacts **tail latency** versus average waiting time.
* **Hardware Footprint:** How algorithmic decisions translate to physical CPU metrics using Linux `perf`—such as **IPC (Instructions Per Cycle)**, branch prediction accuracy, and $L_1$ cache hits.
  
## Core Idea of the Simulator

The simulator models a multi-core CPU scheduler using a **discrete time-step simulation engine**. At every simulated clock tick ($\Delta t = 1$), the event loop executes the following sequence:

1. **Task Arrival:** Newly arrived processes are transferred to the `Ready Queue`.
2. **Core Allocation:** Each available CPU core selects a process according to the active scheduling policy.
3. **Execution Tick:** Active processes execute on assigned cores for one unit of burst time.
4. **State Update:** Remaining burst times and process state structures are updated in memory.
5. **Preemption Handling:** Preemptive schedulers evaluate active tasks on cores, returning preempted processes back to the `Ready Queue` if a higher-priority task arrives.
6. **Completion Telemetry:** Upon task completion, metrics such as Waiting Time ($\text{WT}$), Turnaround Time ($\text{TAT}$), and Response Time ($\text{RT}$) are recorded.

## ⚙️ Multi-Core Simulation Model

The simulator logically models an $N$-core hardware environment within a single deterministic thread. Each physical CPU core is represented as an execution slot inside a contiguous container:

```cpp
std::vector<Process*> running(cores_);
```
For a 4-core configuration (cores_ = 4), active execution slots are mapped sequentially:
* running[0] $\rightarrow$ Core 0running[1] $\rightarrow$ Core 1running[2] $\rightarrow$ Core 2running[3] $\rightarrow$ Core 3
for (int core = 0; core < cores_; ++core) {
    // 1. Dispatch process from Ready Queue to IDLE core
    // 2. Execute process for 1 time unit
    // 3. Update remaining burst time & core state
    // 4. Handle process termination or preemption triggers
}
