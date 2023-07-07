#include "server.h"
#include <llapi/LoggerAPI.h>

#include <llapi/ServerAPI.h>
#include <llapi/AllowListAPI.h>
#include <llapi/PlayerInfoAPI.h>
#include <llapi/mc/Level.hpp>
#include <llapi/mc/Actor.hpp>

#include "event.h"

#include <ctime>

extern Logger logger;
extern EventCounter eventCounter;
extern int tick_per_second;
extern int legal_tick_per_second;
extern size_t up_time;
//extern double ms_per_tick;

int startServer() {
    httplib::Server svr;

    svr.Get("/metrics", [](const httplib::Request &req, httplib::Response &res) {

        MetricsManager mm;

        loadLLServerApi(mm);
        loadLLAllowListApi(mm);
        loadEventCounterMetrics(mm);
        loadLLPLayerInfoApi(mm);
        loadLevelData(mm);
        loadTPS(mm);
        loadUpTime(mm);

        res.set_content(mm.build(), "text/plain");
    });

    svr.listen("0.0.0.0", 10009);
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

void loadTPS(MetricsManager &mm) {
    mm.newMetrics("tps", tick_per_second);
    mm.newMetrics("legal_tps", legal_tick_per_second);
    //mm.newMetrics("mspt", ms_per_tick);
}

void loadLevelData(MetricsManager &mm) {
    auto all_players = Level::getAllPlayers();
    mm.newMetrics("level_player", all_players.size());

    auto all_entities = Level::getAllEntities();
    mm.newMetrics("level_entities", all_entities.size());

    map<string, size_t> all_entities_detail;
    for (auto &entity: all_entities) {
        string type_name = entity->getTypeName();
        if (all_entities_detail.find(type_name) == all_entities_detail.end()) {
            all_entities_detail[type_name] = 1;
        } else {
            all_entities_detail[type_name] += 1;
        }
    }
    for (auto &entity: all_entities_detail) {
        mm.newMetrics("level_entities", entity.second)
                ->label("type", entity.first);
    }
}

void loadUpTime(MetricsManager &mm) {
    mm.newMetrics("up_time", up_time);
    size_t now = time(nullptr);
    mm.newMetrics("now_time", now);
}