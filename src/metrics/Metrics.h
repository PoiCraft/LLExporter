//
// Created by gggxbbb on 2023-07-03.
//

#ifndef PLUGIN_METRICS_H
#define PLUGIN_METRICS_H

#include <string>
#include <vector>
#include "Label.h"

using namespace std;

class IntMetrics {
public:
    string name;
    int value;
    vector<Label> labels;

    IntMetrics(const string &name, int value);

    void set(const string &metricsName, int metricsValue);

    void update(int metricsValue);

    IntMetrics *label(string labelName, string labelValue);

    void addLabel(string labelName, string labelValue);

    string get();
};

class DoubleMetrics {
public:
    string name;
    double value;
    vector<Label> labels;

    DoubleMetrics(const string &name, double value);

    void set(const string &metricsName, double metricsValue);

    void update(double metricsValue);

    DoubleMetrics *label(string labelName, string labelValue);

    void addLabel(string labelName, string labelValue);

    string get();
};

#endif //PLUGIN_METRICS_H
