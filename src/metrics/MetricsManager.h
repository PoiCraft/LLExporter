//
// Created by gggxbbb on 2023-07-04.
//

#ifndef PLUGIN_METRICSMANAGER_H
#define PLUGIN_METRICSMANAGER_H

#include <string>
#include <vector>
#include "Metrics.h"

class MetricsManager {
private:
    vector<IntMetrics> intMetrics;
    vector<DoubleMetrics> doubleMetrics;
    vector<SizeMetrics> sizeMetrics;
public:

    IntMetrics *newMetrics(const string &metricsName, int metricsValue);

    DoubleMetrics *newMetrics(const string &metricsName, double metricsValue);

    SizeMetrics *newMetrics(const string &metricsName, size_t metricsValue);

    string build();
};

#endif //PLUGIN_METRICSMANAGER_H
