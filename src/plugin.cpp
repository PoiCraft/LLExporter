/**
 * @file plugin.cpp
 * @brief The main file of the plugin
 */

#include <llapi/LoggerAPI.h>
#include <llapi/EventAPI.h>

#include "version.h"

#include <thread>
#include "server.h"
#include "event.h"
#include "tps.h"
#include "global.h"

//extern EventCounter eventCounter;

// We recommend using the global logger.
extern Logger logger;

/**
 * @brief The entrypoint of the plugin. DO NOT remove or rename this function.
 *        
 */
void PluginInit() {
    logger.info("Waiting for server to start...");

    Event::ServerStartedEvent::subscribe([](const Event::ServerStartedEvent &event) {

        logger.info("Starting Metrics Server...");

        setUpTime();
        initEventCounter();
        initTPS();

        std::thread serverThread(startServer);
        serverThread.detach();
        logger.info("Metrics Server started, running on port 10009!");

        return true;
    });

}
