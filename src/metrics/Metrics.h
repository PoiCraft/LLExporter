//
// Created by gggxbbb on 2023-07-03.
//

#ifndef PLUGIN_METRICS_H
#define PLUGIN_METRICS_H

#include "string"

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
    Label labels[16];

    void set(string metricsName, double metricsValue, Label metricsLabels[]);

    string get();
};

string buildMetrics(Metrics metrics[]);

#endif //PLUGIN_METRICS_H
