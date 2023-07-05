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
 * @param mm
 */
void loadLLServerApi(MetricsManager& mm);

/**
 * @brief Load the allowlist api metrics
 * @param mm
 */
void loadLLAllowListApi(MetricsManager& mm);

void loadLLPLayerInfoApi(MetricsManager& mm);

void loadTPS(MetricsManager& mm);

#endif //PLUGIN_SERVER_H
