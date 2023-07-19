//
// Created by gggxbbb on 2023-07-05.
//

#include "tps.h"

#include <llapi/ScheduleAPI.h>

/**
 * @brief The tick per second
 * @note The tps data here might be over 20
 */
int tick_per_second;
/**
 * @brief The legal tick per second
 * @note The tps data here will not be over 20
 */
int legal_tick_per_second;
//double ms_per_tick;
/**
 * @brief The ticks
 * @attention This variable should never be used outside this file (tps.cpp)
 */
int ticks = 0;
/**
 * @brief The total ticks
 */
size_t total_ticks = 0;

void initTPS() {
    Schedule::repeat([]() {
        ticks++;
        total_ticks++;
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