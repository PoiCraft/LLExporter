//
// Created by gggxbbb on 2023-07-04.
//

#ifndef PLUGIN_EVENT_H
#define PLUGIN_EVENT_H

void initEventCounter();

class EventCounter{
public:
    size_t player_pre_join_event;
    size_t player_join_event;
    size_t player_left_event;
    size_t player_respawn_event;
    size_t player_use_item_event;
    size_t player_use_item_on_event;
    size_t player_pull_fishing_pool_event;
    size_t player_use_bucket_event;
    size_t player_chat_event;
    size_t player_change_dim_event;
    size_t player_jump_event;
    size_t player_sneak_event;
    size_t player_swing_event;
    size_t player_attack_event;
    size_t player_attack_block_event;
    size_t player_die_event;
    size_t player_pickup_item_event;
    size_t player_drop_item_event;
    size_t player_eat_event;
    size_t player_ate_event;
    size_t player_consume_totem_event;
    size_t player_cmd_event;
    size_t player_effect_changed_event;
    size_t player_start_destroy_block_event;
    size_t player_destroy_block_event;
    size_t player_place_block_event;
    size_t block_placed_by_player_event;
    size_t player_open_container_event;
    size_t player_close_container_event;
    size_t player_inventory_change_event;
    size_t player_sprint_event;
    size_t player_set_armor_event;
    size_t player_use_respawn_anchor_event;
    size_t player_open_container_screen_event;
    size_t player_use_frame_block_event;
    size_t player_score_changed_event;
    size_t player_experience_add_event;
    size_t player_interact_entity_event;
    size_t player_bed_enter_event;
    size_t player_open_inventory_event;

    size_t block_interacted_event;
    size_t block_changed_event;
    size_t block_exploded_event;
    size_t fire_spread_event;
    size_t container_change_event;
    size_t projectile_hit_block_event;
    size_t red_stone_update_event;
    size_t hopper_search_item_event;
    size_t hopper_push_out_event;
    size_t piston_try_push_event;
    size_t farm_land_decay_event;
    size_t liquid_spread_event;
    size_t cmd_block_execute_event;
    size_t block_explode_event;

    size_t entity_explode_event;
    size_t mob_hurt_event;
    size_t mob_die_event;
    size_t projectile_hit_entity_event;
    size_t wither_boss_destroy_event;
    size_t ender_dragon_destroy_event;
    size_t entity_ride_event;
    size_t entity_step_on_pressure_plate_event;
    size_t npc_cmd_event;
    size_t projectile_spawn_event;
    size_t projectile_created_event;
    size_t armor_stand_change_event;
    size_t entity_transform_event;
    size_t mob_try_spawn_event;
    size_t mob_spawned_event;

    size_t console_output_event;
    size_t form_response_packet_event;
};

#endif //PLUGIN_EVENT_H
