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

        //for test int
        Metrics<int> testInt("test_int", 1);
        testInt.addLabel("test_label", "test_value_int");
        mm.addMetrics<int>(testInt);

        //for test double
        Metrics<double> testDouble("test_double", 1.1);
        testDouble.addLabel("test_label", "test_value_double");
        mm.addMetrics<double>(testDouble);

        res.set_content(mm.buildMetrics(), "text/plain");
        logger.info("Metrics sent!");
    });

    svr.listen("0.0.0.0", 10010);
    return 0;
}