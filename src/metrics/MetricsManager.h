//
// Created by gggxbbb on 2023-07-04.
//

#ifndef PLUGIN_METRICSMANAGER_H
#define PLUGIN_METRICSMANAGER_H

#include <string>
#include <vector>
#include "Metrics.h"

/**
 * @brief A metrics manager is used to manage all metrics
 */
class MetricsManager {
private:
    vector<IntMetrics> intMetrics;
    vector<DoubleMetrics> doubleMetrics;
    vector<SizeMetrics> sizeMetrics;
public:

    /**
     * @brief Create a new metric
     * @param metricsName The name of the metrics
     * @param metricsValue The value of the metrics
     */
    IntMetrics *newMetrics(const string &metricsName, int metricsValue);

    /**
     * @brief Create a new metric
     * @param metricsName The name of the metrics
     * @param metricsValue The value of the metrics
     */
    DoubleMetrics *newMetrics(const string &metricsName, double metricsValue);

    /**
     * @brief Create a new metric
     * @param metricsName The name of the metrics
     * @param metricsValue The value of the metrics
     */
    SizeMetrics *newMetrics(const string &metricsName, size_t metricsValue);

    /**
     * @brief Build all metrics into a string, which is the format of Prometheus
     * @return the string
     */
    string build();
};

#endif //PLUGIN_METRICSMANAGER_H
