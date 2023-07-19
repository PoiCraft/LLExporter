//
// Created by gggxbbb on 2023-07-04.
//

#include "event.h"
#include "llapi/mc/HashedString.hpp"
#include <llapi/EventAPI.h>
#include <llapi/mc/Player.hpp>
#include <llapi/mc/ItemStack.hpp>
#include <llapi/mc/Block.hpp>

/**
 * @brief The global event counter
 */
EventCounter eventCounter;


void initEventCounter() {
    Event::PlayerPreJoinEvent::subscribe([](const Event::PlayerPreJoinEvent &event) {
        eventCounter.player_pre_join_event++;
        return true;
    });
    Event::PlayerJoinEvent::subscribe([](const Event::PlayerJoinEvent &event) {
        eventCounter.player_join_event++;
        return true;
    });
    Event::PlayerLeftEvent::subscribe([](const Event::PlayerLeftEvent &event) {
        eventCounter.player_left_event++;
        return true;
    });
    Event::PlayerRespawnEvent::subscribe([](const Event::PlayerRespawnEvent &event) {
        eventCounter.player_respawn_event++;
        return true;
    });
    Event::PlayerUseItemEvent::subscribe([](const Event::PlayerUseItemEvent &event) {
        eventCounter.player_use_item_event++;
        return true;
    });
    Event::PlayerUseItemOnEvent::subscribe([](const Event::PlayerUseItemOnEvent &event) {
        eventCounter.player_use_item_on_event++;
        return true;
    });
    Event::PlayerPullFishingHookEvent::subscribe([](const Event::PlayerPullFishingHookEvent &event) {
        eventCounter.player_pull_fishing_pool_event++;
        return true;
    });
    Event::PlayerUseBucketEvent::subscribe([](const Event::PlayerUseBucketEvent &event) {
        eventCounter.player_use_bucket_event++;
        return true;
    });
    Event::PlayerChatEvent::subscribe([](const Event::PlayerChatEvent &event) {
        eventCounter.player_chat_event++;
        return true;
    });
    Event::PlayerChangeDimEvent::subscribe([](const Event::PlayerChangeDimEvent &event) {
        eventCounter.player_change_dim_event++;
        return true;
    });
    Event::PlayerJumpEvent::subscribe([](const Event::PlayerJumpEvent &event) {
        eventCounter.player_jump_event++;
        return true;
    });
    Event::PlayerSneakEvent::subscribe([](const Event::PlayerSneakEvent &event) {
        eventCounter.player_sneak_event++;
        return true;
    });
    Event::PlayerSwingEvent::subscribe([](const Event::PlayerSwingEvent &event) {
        eventCounter.player_swing_event++;
        return true;
    });
    Event::PlayerAttackEvent::subscribe([](const Event::PlayerAttackEvent &event) {
        eventCounter.player_attack_event++;
        return true;
    });
    Event::PlayerAttackBlockEvent::subscribe([](const Event::PlayerAttackBlockEvent &event) {
        eventCounter.player_attack_block_event++;
        return true;
    });
    Event::PlayerDieEvent::subscribe([](const Event::PlayerDieEvent &event) {
        eventCounter.player_die_event++;
        return true;
    });
    Event::PlayerPickupItemEvent::subscribe([](const Event::PlayerPickupItemEvent &event) {
        eventCounter.player_pickup_item_event++;
        return true;
    });
    Event::PlayerDropItemEvent::subscribe([](const Event::PlayerDropItemEvent &event) {
        eventCounter.player_drop_item_event++;
        return true;
    });
    Event::PlayerEatEvent::subscribe([](const Event::PlayerEatEvent &event) {
        eventCounter.player_eat_event++;
        return true;
    });
    Event::PlayerAteEvent::subscribe([](const Event::PlayerAteEvent &event) {
        eventCounter.player_ate_event++;
        return true;
    });
    Event::PlayerConsumeTotemEvent::subscribe([](const Event::PlayerConsumeTotemEvent &event) {
        eventCounter.player_consume_totem_event++;
        return true;
    });
    Event::PlayerCmdEvent::subscribe([](const Event::PlayerCmdEvent &event) {
        eventCounter.player_cmd_event++;
        return true;
    });
    Event::PlayerEffectChangedEvent::subscribe([](const Event::PlayerEffectChangedEvent &event) {
        eventCounter.player_effect_changed_event++;
        return true;
    });
    Event::PlayerStartDestroyBlockEvent::subscribe([](const Event::PlayerStartDestroyBlockEvent &event) {
        eventCounter.player_start_destroy_block_event++;
        return true;
    });
    Event::PlayerDestroyBlockEvent::subscribe([](const Event::PlayerDestroyBlockEvent &event) {
        eventCounter.player_destroy_block_event++;
        return true;
    });
    Event::PlayerPlaceBlockEvent::subscribe([](const Event::PlayerPlaceBlockEvent &event) {
        eventCounter.player_place_block_event++;
        return true;
    });
    Event::BlockPlacedByPlayerEvent::subscribe([](const Event::BlockPlacedByPlayerEvent &event) {
        eventCounter.block_placed_by_player_event++;
        return true;
    });
    Event::PlayerOpenContainerEvent::subscribe([](const Event::PlayerOpenContainerEvent &event) {
        eventCounter.player_open_container_event++;
        return true;
    });
    Event::PlayerCloseContainerEvent::subscribe([](const Event::PlayerCloseContainerEvent &event) {
        eventCounter.player_close_container_event++;
        return true;
    });
    Event::PlayerInventoryChangeEvent::subscribe([](const Event::PlayerInventoryChangeEvent &event) {
        eventCounter.player_inventory_change_event++;
        return true;
    });
    Event::PlayerSprintEvent::subscribe([](const Event::PlayerSprintEvent &event) {
        eventCounter.player_sprint_event++;
        return true;
    });
    Event::PlayerSetArmorEvent::subscribe([](const Event::PlayerSetArmorEvent &event) {
        eventCounter.player_set_armor_event++;
        return true;
    });
    Event::PlayerUseRespawnAnchorEvent::subscribe([](const Event::PlayerUseRespawnAnchorEvent &event) {
        eventCounter.player_use_respawn_anchor_event++;
        return true;
    });
    Event::PlayerOpenContainerScreenEvent::subscribe([](const Event::PlayerOpenContainerScreenEvent &event) {
        eventCounter.player_open_container_screen_event++;
        return true;
    });
    Event::PlayerUseFrameBlockEvent::subscribe([](const Event::PlayerUseFrameBlockEvent &event) {
        eventCounter.player_use_frame_block_event++;
        return true;
    });
    Event::PlayerScoreChangedEvent::subscribe([](const Event::PlayerScoreChangedEvent &event) {
        eventCounter.player_score_changed_event++;
        return true;
    });
    Event::PlayerExperienceAddEvent::subscribe([](const Event::PlayerExperienceAddEvent &event) {
        eventCounter.player_experience_add_event++;
        return true;
    });
    Event::PlayerInteractEntityEvent::subscribe([](const Event::PlayerInteractEntityEvent &event) {
        eventCounter.player_interact_entity_event++;
        //auto mPlayer = event.mPlayer;
        return true;
    });
    Event::PlayerBedEnterEvent::subscribe([](const Event::PlayerBedEnterEvent &event) {
        eventCounter.player_bed_enter_event++;
        return true;
    });
    Event::PlayerOpenInventoryEvent::subscribe([](const Event::PlayerOpenInventoryEvent &event) {
        eventCounter.player_open_inventory_event++;
        return true;
    });

    Event::BlockInteractedEvent::subscribe([](const Event::BlockInteractedEvent &event) {
        eventCounter.block_interacted_event++;
        return true;
    });
    Event::BlockChangedEvent::subscribe([](const Event::BlockChangedEvent &event) {
        eventCounter.block_changed_event++;
        return true;
    });
    Event::BlockExplodedEvent::subscribe([](const Event::BlockExplodedEvent &event) {
        eventCounter.block_exploded_event++;
        return true;
    });
    Event::FireSpreadEvent::subscribe([](const Event::FireSpreadEvent &event) {
        eventCounter.fire_spread_event++;
        return true;
    });
    Event::ContainerChangeEvent::subscribe([](const Event::ContainerChangeEvent &event) {
        eventCounter.container_change_event++;
        return true;
    });
    Event::ProjectileHitBlockEvent::subscribe([](const Event::ProjectileHitBlockEvent &event) {
        eventCounter.projectile_hit_block_event++;
        return true;
    });
    Event::RedStoneUpdateEvent::subscribe([](const Event::RedStoneUpdateEvent &event) {
        eventCounter.red_stone_update_event++;
        return true;
    });
    Event::HopperSearchItemEvent::subscribe([](const Event::HopperSearchItemEvent &event) {
        eventCounter.hopper_search_item_event++;
        return true;
    });
    Event::HopperPushOutEvent::subscribe([](const Event::HopperPushOutEvent &event) {
        eventCounter.hopper_push_out_event++;
        return true;
    });
    Event::PistonTryPushEvent::subscribe([](const Event::PistonTryPushEvent &event) {
        eventCounter.piston_try_push_event++;
        return true;
    });
    Event::FarmLandDecayEvent::subscribe([](const Event::FarmLandDecayEvent &event) {
        eventCounter.farm_land_decay_event++;
        return true;
    });
    Event::LiquidSpreadEvent::subscribe([](const Event::LiquidSpreadEvent &event) {
        eventCounter.liquid_spread_event++;
        return true;
    });
    Event::CmdBlockExecuteEvent::subscribe([](const Event::CmdBlockExecuteEvent &event) {
        eventCounter.cmd_block_execute_event++;
        return true;
    });
    Event::BlockExplodeEvent::subscribe([](const Event::BlockExplodeEvent &event) {
        eventCounter.block_explode_event++;
        return true;
    });

    Event::EntityExplodeEvent::subscribe([](const Event::EntityExplodeEvent &event) {
        eventCounter.entity_explode_event++;
        return true;
    });
    Event::MobHurtEvent::subscribe([](const Event::MobHurtEvent &event) {
        eventCounter.mob_hurt_event++;
        return true;
    });
    Event::MobDieEvent::subscribe([](const Event::MobDieEvent &event) {
        eventCounter.mob_die_event++;
        return true;
    });
    Event::ProjectileHitEntityEvent::subscribe([](const Event::ProjectileHitEntityEvent &event) {
        eventCounter.projectile_hit_entity_event++;
        return true;
    });
    Event::EntityRideEvent::subscribe([](const Event::EntityRideEvent &event) {
        eventCounter.entity_ride_event++;
        return true;
    });
    Event::EntityStepOnPressurePlateEvent::subscribe([](const Event::EntityStepOnPressurePlateEvent &event) {
        eventCounter.entity_step_on_pressure_plate_event++;
        return true;
    });
    Event::ProjectileSpawnEvent::subscribe([](const Event::ProjectileSpawnEvent &event) {
        eventCounter.projectile_spawn_event++;
        return true;
    });
    Event::ProjectileSpawnEvent::subscribe([](const Event::ProjectileSpawnEvent &event) {
        eventCounter.projectile_spawn_event++;
        return true;
    });
    Event::ProjectileCreatedEvent::subscribe([](const Event::ProjectileCreatedEvent &event) {
        eventCounter.projectile_created_event++;
        return true;
    });
    Event::ArmorStandChangeEvent::subscribe([](const Event::ArmorStandChangeEvent &event) {
        eventCounter.armor_stand_change_event++;
        return true;
    });
    Event::EntityTransformEvent::subscribe([](const Event::EntityTransformEvent &event) {
        eventCounter.entity_transform_event++;
        return true;
    });
    Event::MobTrySpawnEvent::subscribe([](const Event::MobTrySpawnEvent &event) {
        eventCounter.mob_try_spawn_event++;
        return true;
    });
    Event::MobSpawnedEvent::subscribe([](const Event::MobSpawnedEvent &event) {
        eventCounter.mob_spawned_event++;
        return true;
    });

    Event::ConsoleOutputEvent::subscribe([](const Event::ConsoleOutputEvent &event) {
        eventCounter.console_output_event++;
        return true;
    });
    Event::FormResponsePacketEvent::subscribe([](const Event::FormResponsePacketEvent &event) {
        eventCounter.form_response_packet_event++;
        return true;
    });
}

void loadEventCounterMetrics(MetricsManager &mm) {
    mm.newMetrics("player_pre_join_event_count", eventCounter.player_pre_join_event);
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
    mm.newMetrics("entity_ride_event_count", eventCounter.entity_ride_event);
    mm.newMetrics("entity_step_on_pressure_plate_event_count", eventCounter.entity_step_on_pressure_plate_event);
    mm.newMetrics("projectile_spawn_event_count", eventCounter.projectile_spawn_event);
    mm.newMetrics("projectile_created_event_count", eventCounter.projectile_created_event);
    mm.newMetrics("armor_stand_change_event_count", eventCounter.armor_stand_change_event);
    mm.newMetrics("entity_transform_event_count", eventCounter.entity_transform_event);
    mm.newMetrics("mob_try_spawn_event_count", eventCounter.mob_try_spawn_event);
    mm.newMetrics("mob_spawned_event_count", eventCounter.mob_spawned_event);
    mm.newMetrics("console_output_event_count", eventCounter.console_output_event);
    mm.newMetrics("form_response_packet_event_count", eventCounter.form_response_packet_event);
}