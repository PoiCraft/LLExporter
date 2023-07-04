//
// Created by gggxbbb on 2023-07-03.
//

#ifndef PLUGIN_METRICS_H
#define PLUGIN_METRICS_H

#include <string>
#include <vector>

using namespace std;

class Label {
public:
    string name;
    string value;

    void set(string labelName, string labelValue);

    [[nodiscard]] string get() const;
};

template<typename T>
class Metrics {
public:
    string name;
    T value;
    vector<Label> labels;

    Metrics(const string &name, T value);

    void set(const string& metricsName, T metricsValue);

    void update(T metricsValue);

    void addLabel(string labelName, string labelValue);

    [[nodiscard]]string get();
};

class MetricsManager {
private:
    vector<Metrics<int>> metricsInt;
    vector<Metrics<double>> metricsDouble;
public:
    template<typename T>
    void addMetrics(const Metrics<T> &newMetrics);

    [[nodiscard]] string buildMetrics();
};


#endif //PLUGIN_METRICS_H
