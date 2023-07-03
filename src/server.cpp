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

        logger.info("Metrics requested!");
        MetricsManager mm;

        //for test
        Metrics test;
        test.set("test", 1.0);
        test.addLabel("test", "test");
        mm.addMetrics(test);

        res.set_content(mm.buildMetrics(), "text/plain");
        logger.info("Metrics sent!");
    });

    svr.listen("0.0.0.0", 10010);
    return 0;
}