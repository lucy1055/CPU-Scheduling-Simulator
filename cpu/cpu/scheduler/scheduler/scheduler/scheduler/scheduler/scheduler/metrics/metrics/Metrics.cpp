#include "Metrics.h"
#include <iostream>
#include <numeric>
#include <algorithm>
#include <iomanip>

void Metrics::printSummary(const std::vector<Process>& processes, int total_ticks, int num_cores) {
    if (processes.empty()) return;

    double total_wt = 0, total_tat = 0, total_rt = 0, total_burst = 0;
    std::vector<int> turnaround_times;

    for (const auto& p : processes) {
        total_wt += p.waiting_time;
        total_tat += p.turnaround_time;
        total_rt += p.response_time;
        total_burst += p.burst_time;
        turnaround_times.push_back(p.turnaround_time);
    }

    std::sort(turnaround_times.begin(), turnaround_times.end());
    int p99_idx = static_cast<int>(0.99 * turnaround_times.size());
    int p99_tat = turnaround_times[std::min(p99_idx, (int)turnaround_times.size() - 1)];

    double core_utilization = (total_burst / (total_ticks * num_cores)) * 100.0;

    std::cout << "\n==========================================\n";
    std::cout << "         SIMULATION METRICS RESULT        \n";
    std::cout << "==========================================\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total Processes Simulated : " << processes.size() << "\n";
    std::cout << "Total Execution Ticks    : " << total_ticks << "\n";
    std::cout << "Average Waiting Time (WT): " << (total_wt / processes.size()) << " ticks\n";
    std::cout << "Average Turnaround (TAT) : " << (total_tat / processes.size()) << " ticks\n";
    std::cout << "Average Response Time(RT): " << (total_rt / processes.size()) << " ticks\n";
    std::cout << "P99 Turnaround Latency  : " << p99_tat << " ticks\n";
    std::cout << "Simulated Core Utilization: " << core_utilization << "%\n";
    std::cout << "==========================================\n\n";
}