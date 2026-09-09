#ifndef METRICS_H
#define METRICS_H

#include <vector>
#include "../process/Process.h"

class Metrics {
public:
    static void printSummary(const std::vector<Process>& processes, int total_ticks, int num_cores);
};

#endif