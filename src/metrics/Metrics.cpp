//
// Created by gggxbbb on 2023-07-03.
//

#include "Metrics.h"

void Label::set(string labelName, string labelValue) {
    this->name = std::move(labelName);
    this->value = std::move(labelValue);
}

string Label::get() const {
    return this->name + "=" + this->value;
}


void Metrics::set(string metricsName, double metricsValue, Label metricsLabels[]) {
    this->name = std::move(metricsName);
    this->value = metricsValue;
    for (int i = 0; i < 16; ++i) {
        this->labels[i] = metricsLabels[i];
    }
}

string Metrics::get() {
    string result = "bds_" + this->name;
    if (!this->labels[0].name.empty()) {
        result += "{";
        for (int i = 0; i < 16; ++i) {
            if (!this->labels[i].name.empty()) {
                result += this->labels[i].get();
                if (!this->labels[i + 1].name.empty()) {
                    result += ",";
                }
            }
        }
        result += "}";
    }
    result += " " + to_string(this->value);
    return result;
}

string buildMetrics(Metrics metrics[]) {
    string result;
    for (int i = 0; i < 16; ++i) {
        if (!metrics[i].name.empty()) {
            result += metrics[i].get() + "\n";
        }
    }
    return result;
}