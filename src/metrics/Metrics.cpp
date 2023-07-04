//
// Created by gggxbbb on 2023-07-03.
//

#include "Metrics.h"

#include <utility>

void Label::set(string labelName, string labelValue) {
    this->name = std::move(labelName);
    this->value = std::move(labelValue);
}

string Label::get() const {
    return this->name + "=\"" + this->value + "\"";
}

template<class T>
Metrics<T>::Metrics(const string &name, T value) {
    this->name = name;
    this->value = std::move(value);
}

template<class T>
void Metrics<T>::set(const string& metricsName, T metricsValue) {
    this->name = metricsName;
    this->value = std::move(metricsValue);
}

template<class T>
void Metrics<T>::update(T metricsValue) {
    this->value = std::move(metricsValue);
}

template<class T>
void Metrics<T>::addLabel(string labelName, string labelValue){
    Label newLabel;
    newLabel.set(std::move(labelName), std::move(labelValue));
    this->addLabel(newLabel);
}

template<class T>
string Metrics<T>::get() {
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

template<>
void MetricsManager::addMetrics(const Metrics<int> &newMetrics) {
    this->metricsInt.push_back(newMetrics);
}

template<>
void MetricsManager::addMetrics(const Metrics<double> &newMetrics) {
    this->metricsDouble.push_back(newMetrics);
}

template<class T>
void MetricsManager::addMetrics(const Metrics<T> &newMetrics) {
    // throw error if metrics type is not int or double
    static_assert(true, "Metrics type must be int or double!");
}

string MetricsManager::buildMetrics() {
    string result;
    for (auto &metric: this->metricsInt) {
        result += metric.get() + "\n";
    }
    for (auto &metric: this->metricsDouble) {
        result += metric.get() + "\n";
    }
    return result;
}