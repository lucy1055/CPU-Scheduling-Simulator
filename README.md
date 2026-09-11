# CPU Scheduling Simulator (C++17)

## Overview

A modular CPU scheduling simulator implemented in clean C++17, designed to run on Linux/WSL and compiled with a single `g++` command.

---

## Features

* Support for multiple scheduling algorithms:
  * First Come First Serve (FCFS)
  * Shortest Job First (SJF)
  * Shortest Remaining Time First (SRTF)
  * Round Robin (RR)
  * Priority Scheduling (Preemptive / Non-Preemptive)
* Multi-core CPU execution model
* Synthetic workload generation for controlled experiments
* Computation of scheduling performance metrics:
  * Waiting Time
  * Turnaround Time
  * Response Time
  * CPU Utilization
  * Throughput