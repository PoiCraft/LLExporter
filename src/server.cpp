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
        mm.newMetrics("player_pre_join_event;_count", eventCounter.player_pre_join_event);
        mm.newMetrics("player_join_event_count", eventCounter.player_join_event);
        mm.newMetrics("player_left_event_count", eventCounter.player_left_event);
        mm.newMetrics("player_respawn_event_count", eventCounter.player_respawn_event);
        mm.newMetrics("player_use_item_event_count", eventCounter.player_use_item_event);
        mm.newMetrics("player_use_item_on_event_count", eventCounter.player_use_item_on_event);
        mm.newMetrics("player_pull_fishing_pool_event_count", eventCounter.player_pull_fishing_pool_event);
        mm.newMetrics("player_use_bucket_event_count", eventCounter.player_use_bucket_event);
        mm.newMetrics("player_chat_event_count", eventCounter.player_chat_event);
        mm.newMetrics("player_change_dim_event_count", eventCounter.player_change_dim_event);
        mm.newMetrics("player_jump_event_count", eventCounter.player_jump_event);
        mm.newMetrics("player_sneak_event_count", eventCounter.player_sneak_event);
        mm.newMetrics("player_swing_event_count", eventCounter.player_swing_event);
        mm.newMetrics("player_attack_event_count", eventCounter.player_attack_event);
        mm.newMetrics("player_attack_block_event_count", eventCounter.player_attack_block_event);
        mm.newMetrics("player_die_event_count", eventCounter.player_die_event);
        mm.newMetrics("player_pickup_item_event_count", eventCounter.player_pickup_item_event);
        mm.newMetrics("player_drop_item_event_count", eventCounter.player_drop_item_event);
        mm.newMetrics("player_eat_event_count", eventCounter.player_eat_event);
        mm.newMetrics("player_ate_event_count", eventCounter.player_ate_event);
        mm.newMetrics("player_consume_totem_event_count", eventCounter.player_consume_totem_event);
        mm.newMetrics("player_cmd_event_count", eventCounter.player_cmd_event);
        mm.newMetrics("player_effect_changed_event_count", eventCounter.player_effect_changed_event);
        mm.newMetrics("player_start_destroy_block_event_count", eventCounter.player_start_destroy_block_event);
        mm.newMetrics("player_destroy_block_event_count", eventCounter.player_destroy_block_event);
        mm.newMetrics("player_place_block_event_count", eventCounter.player_place_block_event);
        mm.newMetrics("block_placed_by_player_event_count", eventCounter.block_placed_by_player_event);
        mm.newMetrics("player_open_container_event_count", eventCounter.player_open_container_event);
        mm.newMetrics("player_close_container_event_count", eventCounter.player_close_container_event);
        mm.newMetrics("player_inventory_change_event_count", eventCounter.player_inventory_change_event);
        mm.newMetrics("player_sprint_event_count", eventCounter.player_sprint_event);
        mm.newMetrics("player_set_armor_event_count", eventCounter.player_set_armor_event);
        mm.newMetrics("player_use_respawn_anchor_event_count", eventCounter.player_use_respawn_anchor_event);
        mm.newMetrics("player_open_container_screen_event_count", eventCounter.player_open_container_screen_event);
        mm.newMetrics("player_use_frame_block_event_count", eventCounter.player_use_frame_block_event);
        mm.newMetrics("player_score_changed_event_count", eventCounter.player_score_changed_event);
        mm.newMetrics("player_experience_add_event_count", eventCounter.player_experience_add_event);
        mm.newMetrics("player_interact_entity_event_count", eventCounter.player_interact_entity_event);
        mm.newMetrics("player_bed_enter_event_count", eventCounter.player_bed_enter_event);
        mm.newMetrics("player_open_inventory_event_count", eventCounter.player_open_inventory_event);
        mm.newMetrics("block_interacted_event_count", eventCounter.block_interacted_event);
        mm.newMetrics("block_changed_event_count", eventCounter.block_changed_event);
        mm.newMetrics("block_exploded_event_count", eventCounter.block_exploded_event);
        mm.newMetrics("fire_spread_event_count", eventCounter.fire_spread_event);
        mm.newMetrics("container_change_event_count", eventCounter.container_change_event);
        mm.newMetrics("projectile_hit_block_event_count", eventCounter.projectile_hit_block_event);
        mm.newMetrics("red_stone_update_event_count", eventCounter.red_stone_update_event);
        mm.newMetrics("hopper_search_item_event_count", eventCounter.hopper_search_item_event);
        mm.newMetrics("hopper_push_out_event_count", eventCounter.hopper_push_out_event);
        mm.newMetrics("piston_try_push_event_count", eventCounter.piston_try_push_event);
        mm.newMetrics("farm_land_decay_event_count", eventCounter.farm_land_decay_event);
        mm.newMetrics("liquid_spread_event_count", eventCounter.liquid_spread_event);
        mm.newMetrics("cmd_block_execute_event_count", eventCounter.cmd_block_execute_event);
        mm.newMetrics("block_explode_event_count", eventCounter.block_explode_event);
        mm.newMetrics("entity_explode_event_count", eventCounter.entity_explode_event);
        mm.newMetrics("mob_hurt_event_count", eventCounter.mob_hurt_event);
        mm.newMetrics("mob_die_event_count", eventCounter.mob_die_event);
        mm.newMetrics("projectile_hit_entity_event_count", eventCounter.projectile_hit_entity_event);
        mm.newMetrics("wither_boss_destroy_event_count", eventCounter.wither_boss_destroy_event);
        mm.newMetrics("ender_dragon_destroy_event_count", eventCounter.ender_dragon_destroy_event);
        mm.newMetrics("entity_ride_event_count", eventCounter.entity_ride_event);
        mm.newMetrics("entity_step_on_pressure_plate_event_count", eventCounter.entity_step_on_pressure_plate_event);
        mm.newMetrics("npc_cmd_event_count", eventCounter.npc_cmd_event);
        mm.newMetrics("projectile_spawn_event_count", eventCounter.projectile_spawn_event);
        mm.newMetrics("projectile_created_event_count", eventCounter.projectile_created_event);
        mm.newMetrics("armor_stand_change_event_count", eventCounter.armor_stand_change_event);
        mm.newMetrics("entity_transform_event_count", eventCounter.entity_transform_event);
        mm.newMetrics("mob_try_spawn_event_count", eventCounter.mob_try_spawn_event);
        mm.newMetrics("mob_spawned_event_count", eventCounter.mob_spawned_event);
        mm.newMetrics("console_output_event_count", eventCounter.console_output_event);
        mm.newMetrics("form_response_packet_event_count", eventCounter.form_response_packet_event);


        res.set_content(mm.build(), "text/plain");
    });

    svr.listen("0.0.0.0", 10010);
    return 0;
}