//
// Created by gggxbbb on 2023-07-03.
//

#include "server.h"
#include "metrics/Metrics.h"
#include <llapi/LoggerAPI.h>

extern Logger logger;

int startServer() {
    httplib::Server svr;

    svr.Get("/metrics", [](const httplib::Request &req, httplib::Response &res) {
        Metrics metrics[1];

        metrics[0].set("test", 1);

        res.set_content(buildMetrics(metrics), "text/plain");
    });

    svr.listen("0.0.0.0", 10010);
    return 0;
}