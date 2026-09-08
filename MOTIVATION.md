# 🎯 Why I Built This Project

Textbooks describe scheduling algorithms like `FCFS`, `SJF`, `SRTF`, `Round Robin`, and `Priority` theoretically using static 4–5 process examples. However, developing practical intuition requires observing how these policies perform on **real workloads across multi-core systems**.

I built this simulator in `C++17` to observe:
* **Queue Dynamics:** How ready queues evolve when **2,500+ tasks** compete across multiple CPU cores.
* **Preemption Overhead:** How preemptive scheduling impacts **tail latency** versus average waiting time.
* **Hardware Footprint:** How algorithmic decisions translate to physical CPU metrics using Linux `perf`—such as **IPC (Instructions Per Cycle)**, branch prediction accuracy, and $L_1$ cache hits.
