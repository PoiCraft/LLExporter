//
// Created by gggxbbb on 2023-07-03.
//

#include "Metrics.h"

#include <utility>

IntMetrics::IntMetrics(const string &name, int value) {
    this->name = name;
    this->value = value;
}

void IntMetrics::set(const string &metricsName, int metricsValue) {
    this->name = metricsName;
    this->value = metricsValue;
}

void IntMetrics::update(int metricsValue) {
    this->value = metricsValue;
}

IntMetrics *IntMetrics::label(string labelName, string labelValue) {
    Label newLabel;
    newLabel.set(std::move(labelName), std::move(labelValue));
    this->labels.push_back(newLabel);
    return this;
}

void IntMetrics::addLabel(string labelName, string labelValue) {
    Label newLabel;
    newLabel.set(std::move(labelName), std::move(labelValue));
    this->labels.push_back(newLabel);
}

string IntMetrics::get() {
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

DoubleMetrics::DoubleMetrics(const string &name, double value) {
    this->name = name;
    this->value = value;
}

void DoubleMetrics::set(const string &metricsName, double metricsValue) {
    this->name = metricsName;
    this->value = metricsValue;
}

void DoubleMetrics::update(double metricsValue) {
    this->value = metricsValue;
}

DoubleMetrics *DoubleMetrics::label(string labelName, string labelValue) {
    Label newLabel;
    newLabel.set(std::move(labelName), std::move(labelValue));
    this->labels.push_back(newLabel);
    return this;
}

void DoubleMetrics::addLabel(string labelName, string labelValue) {
    Label newLabel;
    newLabel.set(std::move(labelName), std::move(labelValue));
    this->labels.push_back(newLabel);
}

string DoubleMetrics::get() {
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