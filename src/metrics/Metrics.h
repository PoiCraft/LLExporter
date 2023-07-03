//
// Created by gggxbbb on 2023-07-03.
//

#ifndef PLUGIN_METRICS_H
#define PLUGIN_METRICS_H

#include "string"
#include "vector"

using namespace std;

class Label {
public:
    string name;
    string value;

    void set(string labelName, string labelValue);

    [[nodiscard]] string get() const;
};

class Metrics {
public:
    string name;
    double value;
    vector<Label> labels;

    void set(string metricsName, double metricsValue, Label metricsLabels[]);

    void set(string metricsName, double metricsValue);

    void addLabel(const Label& newLabel);

    void addLabel(string labelName,string labelValue);

    [[nodiscard]]string get();
};

class MetricsManager {
private:
    vector <Metrics> metrics;
public:
    void addMetrics(const Metrics& newMetrics);

    [[nodiscard]] string buildMetrics();
};


#endif //PLUGIN_METRICS_H
