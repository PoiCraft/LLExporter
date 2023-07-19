//
// Created by gggxbbb on 2023-07-03.
//

#ifndef PLUGIN_SERVER_H
#define PLUGIN_SERVER_H

#include <httplib/httplib.h>
#include "metrics/MetricsManager.h"

using namespace std;

/**
 * @brief Start the server
 * @return
 */
int startServer();

/**
 * @brief Load the server api metrics
 * @param mm The metrics manager
 */
void loadLLServerApi(MetricsManager& mm);

/**
 * @brief Load the allowlist api metrics
 * @param mm The metrics manager
 */
void loadLLAllowListApi(MetricsManager& mm);

/**
 * @brief Load the player info api metrics
 * @param mm The metrics manager
 */
void loadLLPLayerInfoApi(MetricsManager& mm);

/**
 * @brief Load the tps metrics
 * @param mm The metrics manager
 */
void loadTPS(MetricsManager& mm);

/**
 * @brief Load the level data metrics
 * @param mm The metrics manager
 */
void loadLevelData(MetricsManager& mm);

/**
 * @brief Load the player count metrics
 * @param mm The metrics manager
 */
void loadUpTime(MetricsManager& mm);

#endif //PLUGIN_SERVER_H
