//
// Created by gggxbbb on 2023-07-05.
//

#include "tps.h"

#include <llapi/ScheduleAPI.h>

int tick_per_second;
int legal_tick_per_second;
//double ms_per_tick;
int ticks = 0;

void initTPS() {
    Schedule::repeat([]() {
        ticks++;
    },1);
    std::thread([]{
        for (;;){
            tick_per_second = ticks;
            if (ticks > 20){
                legal_tick_per_second = 20;
            } else {
                legal_tick_per_second = ticks;
            }
            //ms_per_tick = 1000.0 / tick_per_second;
            ticks = 0;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    })
    .detach();
}