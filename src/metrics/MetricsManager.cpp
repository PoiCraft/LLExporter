//
// Created by gggxbbb on 2023-07-04.
//

#include "MetricsManager.h"

IntMetrics *MetricsManager::newMetrics(const string &metricsName, int metricsValue) {
    IntMetrics newMetrics(metricsName, metricsValue);
    this->intMetrics.push_back(newMetrics);
    return &this->intMetrics.back();
}

DoubleMetrics *MetricsManager::newMetrics(const string &metricsName, double metricsValue) {
    DoubleMetrics newMetrics(metricsName, metricsValue);
    this->doubleMetrics.push_back(newMetrics);
    return &this->doubleMetrics.back();
}

string MetricsManager::build() {
    string result;
    for (IntMetrics i: this->intMetrics) {
        result += i.get() + "\n";
    }
    for (DoubleMetrics i: this->doubleMetrics) {
        result += i.get() + "\n";
    }
    return result;
}