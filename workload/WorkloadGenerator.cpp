#include "../process/Process.h"
#include <vector>
#include <random>

class WorkloadGenerator {
public:
    static std::vector<Process> generateRandomWorkload(int count) {
        std::vector<Process> processes;
        std::mt19937 rng(42); // Fixed seed for reproducible benchmarks
        std::uniform_int_distribution<int> arrival_dist(0, 100);
        std::uniform_int_distribution<int> burst_dist(1, 20);
        std::uniform_int_distribution<int> prio_dist(1, 10);

        for (int i = 1; i <= count; ++i) {
            processes.emplace_back(i, arrival_dist(rng), burst_dist(rng), prio_dist(rng));
        }
        return processes;
    }
};