//
// Created by gggxbbb on 2023-07-03.
//

#include "Metrics.h"

void Label::set(string labelName, string labelValue) {
    this->name = std::move(labelName);
    this->value = std::move(labelValue);
}

string Label::get() const {
    return this->name + "=\"" + this->value + "\"";
}


void Metrics::set(string metricsName, double metricsValue, Label metricsLabels[]) {
    this->name = std::move(metricsName);
    this->value = metricsValue;
    for (int i = 0; i < 16; ++i) {
        this->labels[i] = metricsLabels[i];
    }
}

void Metrics::set(string metricsName, double metricsValue) {
    this->name = std::move(metricsName);
    this->value = metricsValue;
}

void Metrics::addLabel(const Label& newLabel) {
    this->labels.push_back(newLabel);
}

void Metrics::addLabel(string labelName, string labelValue) {
    Label newLabel;
    newLabel.set(std::move(labelName), std::move(labelValue));
    this->addLabel(newLabel);
}

string Metrics::get() {
    string result = "bds_" + this->name;
    if(!this->labels.empty()){
        result += "{";
        for (const auto& i : this->labels) {
            result += i.get();
            if (i.name != this->labels.back().name) {
                result += ",";
            }
        }
        result += "}";
    }
    result += " " + to_string(this->value);
    return result;
}

void MetricsManager::addMetrics(const Metrics& newMetrics) {
    this->metrics.push_back(newMetrics);
}

string MetricsManager::buildMetrics() {
    string result;
    for (auto & metric : this->metrics) {
        result += metric.get() + "\n";
    }
    return result;
}