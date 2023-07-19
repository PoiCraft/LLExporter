//
// Created by gggxbbb on 2023-07-03.
//

#ifndef PLUGIN_METRICS_H
#define PLUGIN_METRICS_H

#include <string>
#include <vector>
#include "Label.h"

using namespace std;

/**
 * @brief A metric is a name/value pair.
 * @see https://prometheus.io/docs/concepts/data_model/#metric-names-and-labels
 * @param name The metric name
 * @param value The metric value
 */
class IntMetrics {
public:
    string name;
    int value;
    vector<Label> labels;

    IntMetrics(const string &name, int value);

    /**
     * @brief Set the metric value
     * @param metricsName The name of the metric
     * @param metricsValue The value of the metric
     */
    void set(const string &metricsName, int metricsValue);

    /**
     * @brief Update the metric value
     * @param metricsValue The new value of the metric
     */
    void update(int metricsValue);

    /**
     * @brief Add a label to the metric, in chain style
     * @param labelName The name of the label
     * @param labelValue The value of the label
     * @return the metrics itself
     */
    IntMetrics *label(string labelName, string labelValue);

    /**
     * @brief Add a label to the metric
     * @param labelName
     * @param labelValue
     */
    void addLabel(string labelName, string labelValue);

    /**
     * @brief Turn this metric into string, which is the format of Prometheus
     * @return the string
     */
    string get();
};

/**
 * @brief A metric is a name/value pair.
 * @see https://prometheus.io/docs/concepts/data_model/#metric-names-and-labels
 * @param name The metric name
 * @param value The metric value
 */
class DoubleMetrics {
public:
    string name;
    double value;
    vector<Label> labels;

    DoubleMetrics(const string &name, double value);

    /**
     * @brief Set the metric value
     * @param metricsName The name of the metric
     * @param metricsValue The value of the metric
     */
    void set(const string &metricsName, double metricsValue);

    /**
     * @brief Update the metric value
     * @param metricsValue The new value of the metric
     */
    void update(double metricsValue);

    /**
     * @brief Add a label to the metric, in chain style
     * @param labelName The name of the label
     * @param labelValue The value of the label
     * @return the metrics itself
     */
    DoubleMetrics *label(string labelName, string labelValue);

    /**
     * @brief Add a label to the metric
     * @param labelName
     * @param labelValue
     */
    void addLabel(string labelName, string labelValue);

    /**
     * @brief Turn this metric into string, which is the format of Prometheus
     * @return the string
     */
    string get();
};

/**
 * @brief A metric is a name/value pair.
 * @see https://prometheus.io/docs/concepts/data_model/#metric-names-and-labels
 * @param name The metric name
 * @param value The metric value
 */
class SizeMetrics{
public:
    string name;
    size_t value;
    vector<Label> labels;

    SizeMetrics(const string &name, size_t value);

    /**
     * @brief Set the metric value
     * @param metricsName The name of the metric
     * @param metricsValue The value of the metric
     */
    void set(const string &metricsName, size_t metricsValue);

    /**
     * @brief Update the metric value
     * @param metricsValue The new value of the metric
     */
    void update(size_t metricsValue);

    /**
     * @brief Add a label to the metric, in chain style
     * @param labelName The name of the label
     * @param labelValue The value of the label
     * @return the metrics itself
     */
    SizeMetrics *label(string labelName, string labelValue);

    /**
     * @brief Add a label to the metric
     * @param labelName
     * @param labelValue
     */
    void addLabel(string labelName, string labelValue);

    /**
     * @brief Turn this metric into string, which is the format of Prometheus
     * @return the string
     */
    string get();
};

#endif //PLUGIN_METRICS_H
