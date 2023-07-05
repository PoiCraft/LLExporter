#include "server.h"
#include <llapi/LoggerAPI.h>

#include <llapi/ServerAPI.h>
#include <llapi/AllowListAPI.h>

#include "metrics/MetricsManager.h"
#include "event.h"

extern Logger logger;
extern EventCounter eventCounter;

int startServer() {
    httplib::Server svr;

    svr.Get("/metrics", [](const httplib::Request &req, httplib::Response &res) {

        logger.info("Metrics requested!");

        MetricsManager mm;

        // llapi/ServerAPI
        mm.newMetrics("server_protocol_version", ll::getServerProtocolVersion())
                ->label("version", ll::getBdsVersion());

        //llapi/Allowlist
        mm.newMetrics("allowlist_size", AllowListManager().size());

        //EventCounter
        loadEventCounterMetrics(mm);


        res.set_content(mm.build(), "text/plain");
    });

    svr.listen("0.0.0.0", 10010);
    return 0;
}