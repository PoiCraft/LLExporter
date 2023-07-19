//
// Created by gggxbbb on 2023-07-04.
//

#ifndef PLUGIN_LABEL_H
#define PLUGIN_LABEL_H

#include <string>
#include <vector>

using namespace std;

/**
 * @brief A label is a key-value pair that is attached to a metric or a time series.
 * @see https://prometheus.io/docs/concepts/data_model/#labels
 * @param name The label name
 * @param value The label value
 */
class Label {
public:
    string name;
    string value;

    void set(string labelName, string labelValue);

    [[nodiscard]] string get() const;
};

#endif //PLUGIN_LABEL_H
