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

MetricsManager<int> mmi;
MetricsManager<double> mmd;
Metrics<double> testDouble("test_double", 1.1);
Metrics<int> testInt("test_int", 1);