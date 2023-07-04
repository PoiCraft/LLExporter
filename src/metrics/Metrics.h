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

template<class V>
class Metrics {
public:
    string name;
    V value;
    vector<Label> labels;
    template<typename T>
    Metrics(const string &name, T value) {
        this->name = name;
        this->value = std::move(value);
    }

    template<typename T>
    void set(const string& metricsName, T metricsValue) {
        this->name = metricsName;
        this->value = std::move(metricsValue);
    }

    template<typename T>
    void update(T metricsValue) {
        this->value = std::move(metricsValue);
    }

    void addLabel(string labelName, string labelValue){
        Label newLabel;
        newLabel.set(std::move(labelName), std::move(labelValue));
        this->labels.push_back(newLabel);
    }
    string get() {
        string result = "bds_" + this->name;
        if (!this->labels.empty()) {
            result += "{";
            for (const auto &i: this->labels) {
                result += i.get();
                if (i.name != this->labels.back().name) {
                    result += ",";
                }
            }
            result += "}";
        }
        result += " " + std::to_string(this->value);
        return result;
    }
};
template<class U>
class MetricsManager {
public:
    vector<Metrics<U>> metricsValue;
    template<typename T>
    void addMetrics(const Metrics<T> &newMetrics) {
        this->metricsValue.push_back(newMetrics);
    }
    string buildMetrics() {
        string result;
        for (auto &metric: this->metricsValue) {
            result += metric.get() + "\n";
        }
        return result;
    }
};



#endif //PLUGIN_METRICS_H
