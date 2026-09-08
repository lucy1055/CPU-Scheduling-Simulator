# Multi-Core CPU Scheduling Simulator

A high-performance C++ simulator designed to model, analyze, and visualize preemptive and non-preemptive Priority CPU scheduling algorithms across multi-core architectures.

---

## 📌 Project Overview
This project simulates how Operating System kernels schedule processes across multiple CPU cores. It provides a modular framework to evaluate execution behavior, process preemption, and calculate critical OS telemetry metrics in real time.

## ✨ Key Features
* **Multi-Core Scheduling:** Supports execution across $N$ dynamic CPU cores.
* **Preemptive & Non-Preemptive Modes:** Simulates real-time process preemption based on priority weights.
* **OS Telemetry & Performance Analytics:** Computes key performance indicators:
  * Turnaround Time (TAT)
  * Waiting Time (WT)
  * Response Time (RT)
  * CPU Utilization (%)
  * System Throughput
* **Gantt Chart Visualization:** Generates tick-by-tick visual timelines of core utilization and process assignment.
* **Decoupled Architecture:** Clean separation between scheduling logic, hardware core management, telemetry, and CLI interface.

---

## 🛠️ Tech Stack
* **Language:** C++ (C++11 / C++17)
* **Build Tool:** `g++` / CMake
* **Version Control:** Git & GitHub

---

## ⚙️ How It Works (Workflow)

1. **Process Ingestion:** Processes enter with assigned `Arrival Time`, `Burst Time`, and `Priority`.
2. **Ready Queue Management:** Unassigned ready processes are organized into a priority queue.
3. **Core Allocation & Preemption:**
   * **Non-Preemptive:** Idle cores pull the highest-priority process.
   * **Preemptive:** Active cores evaluate running tasks against higher-priority incoming processes at each clock tick ($t \to t+1$).
4. **Telemetry Calculation:** Once all processes complete, performance metrics are derived using standard OS formulas.

---

## 🚀 Getting Started

### Prerequisites
Make sure you have `g++` compiler installed.

```bash
g++ --version
