#include "server.h"
#include <llapi/LoggerAPI.h>
#include "metrics/MetricsManager.h"

extern Logger logger;

int startServer() {
    httplib::Server svr;

    svr.Get("/metrics", [](const httplib::Request &req, httplib::Response &res) {

        logger.info("Metrics requested!");

        MetricsManager mm;

        // test for int
        IntMetrics *testInt = mm.newMetrics("testInt", 1);
        testInt->addLabel("testLabel", "testValue_int");

        // test for double
        DoubleMetrics *testDouble = mm.newMetrics("testDouble", 1.0);
        testDouble->addLabel("testLabel", "testValue_double");

        mm.newMetrics("testInt", 2)
        ->label("testLabel", "testValue_int")
        ->label("testLabel2", "testValue_int2")
        ->label("testLabel3", "testValue_int3");

        res.set_content(mm.build(), "text/plain");
    });

    svr.listen("0.0.0.0", 10010);
    return 0;
}