#include "server.h"
#include <llapi/LoggerAPI.h>

#include <llapi/ServerAPI.h>
#include <llapi/AllowListAPI.h>
#include <llapi/PlayerInfoAPI.h>

#include "event.h"

extern Logger logger;
extern EventCounter eventCounter;

int startServer() {
    httplib::Server svr;

    svr.Get("/metrics", [](const httplib::Request &req, httplib::Response &res) {

        logger.info("Metrics requested!");

        MetricsManager mm;

        loadLLServerApi(mm);
        loadLLAllowListApi(mm);
        loadEventCounterMetrics(mm);
        loadLLPLayerInfoApi(mm);

        res.set_content(mm.build(), "text/plain");
    });

    svr.listen("0.0.0.0", 10010);
    return 0;
}

void loadLLServerApi(MetricsManager &mm) {
    mm.newMetrics("server_protocol_version", ll::getServerProtocolVersion())
            ->label("version", ll::getBdsVersion());
}

void loadLLAllowListApi(MetricsManager &mm) {
    mm.newMetrics("allowlist_size", AllowListManager().size());
}

void loadLLPLayerInfoApi(MetricsManager &mm) {
    auto playerInfo = PlayerInfo::getAllPlayerInfo();
    mm.newMetrics("player_info_size", playerInfo.size());
    size_t online = eventCounter.player_join_event - eventCounter.player_left_event;
    mm.newMetrics("player_online", online);
    size_t offline = playerInfo.size() - online;
    mm.newMetrics("player_offline", offline);
}