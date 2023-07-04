#include "server.h"
#include "metrics/Metrics.h"
#include <llapi/LoggerAPI.h>
extern MetricsManager<int> mmi;
extern MetricsManager<double> mmd;
extern Logger logger;
extern Metrics<double> testDouble;
extern Metrics<int> testInt;
int startServer() {
    httplib::Server svr;

    svr.Get("/metrics", [](const httplib::Request &req, httplib::Response &res) {

        logger.info("Metrics requested!");


        //for test int

        testInt.addLabel("test_label", "test_value_int");
        mmi.addMetrics(testInt);

        //for test double

        testDouble.addLabel("test_label", "test_value_double");
        mmd.addMetrics(testDouble);
        res.set_content(mmd.buildMetrics(), "text/plain");
        logger.info("Metrics sent!");
        res.set_content(mmi.buildMetrics(), "text/plain");
        logger.info("Metrics sent!");
    });

    svr.listen("0.0.0.0", 10010);
    return 0;
}