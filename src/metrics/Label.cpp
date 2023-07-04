//
// Created by gggxbbb on 2023-07-04.
//

#include "Label.h"

void Label::set(string labelName, string labelValue) {
    this->name = std::move(labelName);
    this->value = std::move(labelValue);
}

string Label::get() const {
    return this->name + "=\"" + this->value + "\"";
}