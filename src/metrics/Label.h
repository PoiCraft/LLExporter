//
// Created by gggxbbb on 2023-07-04.
//

#ifndef PLUGIN_LABEL_H
#define PLUGIN_LABEL_H

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

#endif //PLUGIN_LABEL_H
