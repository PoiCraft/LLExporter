//
// Created by gggxbbb on 2023-07-07.
//

#include "global.h"

#include <ctime>

size_t up_time = 0;

void setUpTime(){
    auto now = time(nullptr);
    up_time = now;
}