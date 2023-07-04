/**
 * @file plugin.cpp
 * @brief The main file of the plugin
 */

#include <llapi/LoggerAPI.h>

#include "version.h"

#include <thread>
#include "server.h"

// We recommend using the global logger.
extern Logger logger;

/**
 * @brief The entrypoint of the plugin. DO NOT remove or rename this function.
 *        
 */
void PluginInit()
{
    // Your code here
    logger.info("Starting Metrics Server...");
    std::thread serverThread(startServer);
    serverThread.detach();
    logger.info("Metrics Server started, running on port 10010!");
}
