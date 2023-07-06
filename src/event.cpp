//
// Created by gggxbbb on 2023-07-04.
//

#include "event.h"
#include "llapi/mc/HashedString.hpp"
#include <llapi/EventAPI.h>
#include <llapi/mc/Player.hpp>
#include <llapi/mc/ItemStack.hpp>
#include <llapi/mc/Block.hpp>

EventCounter eventCounter;

void initEventCounter() {
    Event::PlayerPreJoinEvent::subscribe([](const Event::PlayerPreJoinEvent &event) {
        eventCounter.player_pre_join_event++;
        return true;
    });
    Event::PlayerJoinEvent::subscribe([](const Event::PlayerJoinEvent &event) {
        eventCounter.player_join_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_join_detail.find(player) == eventCounter.player_join_detail.end()) {
            eventCounter.player_join_detail[player] = 1;
        } else {
            eventCounter.player_join_detail[player]++;
        }
        return true;
    });
    Event::PlayerLeftEvent::subscribe([](const Event::PlayerLeftEvent &event) {
        eventCounter.player_left_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_left_detail.find(player) == eventCounter.player_left_detail.end()) {
            eventCounter.player_left_detail[player] = 1;
        } else {
            eventCounter.player_left_detail[player]++;
        }
        return true;
    });
    Event::PlayerRespawnEvent::subscribe([](const Event::PlayerRespawnEvent &event) {
        eventCounter.player_respawn_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_respawn_detail.find(player) == eventCounter.player_respawn_detail.end()) {
            eventCounter.player_respawn_detail[player] = 1;
        } else {
            eventCounter.player_respawn_detail[player]++;
        }
        return true;
    });
    Event::PlayerUseItemEvent::subscribe([](const Event::PlayerUseItemEvent &event) {
        eventCounter.player_use_item_event++;
        string player = event.mPlayer->getRealName();
        string item = event.mItemStack->getTypeName();
        if (eventCounter.player_use_item_detail.find(player) == eventCounter.player_use_item_detail.end()) {
            eventCounter.player_use_item_detail[player] = map<string, size_t>();
        }
        if (eventCounter.player_use_item_detail[player].find(item) ==
            eventCounter.player_use_item_detail[player].end()) {
            eventCounter.player_use_item_detail[player][item] = 1;
        } else {
            eventCounter.player_use_item_detail[player][item]++;
        }
        return true;
    });
    Event::PlayerUseItemOnEvent::subscribe([](const Event::PlayerUseItemOnEvent &event) {
        eventCounter.player_use_item_on_event++;
        string player = event.mPlayer->getRealName();
        string item = event.mItemStack->getTypeName();
        auto block = event.mBlockInstance;
        HashedString hBlockName = block.getBlock()->getName();
        const string &blockName = hBlockName.getString();
        if (eventCounter.player_use_item_on_detail.find(player) == eventCounter.player_use_item_on_detail.end()) {
            eventCounter.player_use_item_on_detail[player] = map<string, map<string, size_t>>();
        }
        if (eventCounter.player_use_item_on_detail[player].find(item) ==
            eventCounter.player_use_item_on_detail[player].end()) {
            eventCounter.player_use_item_on_detail[player][item] = map<string, size_t>();
        }
        if (eventCounter.player_use_item_on_detail[player][item].find(blockName) ==
            eventCounter.player_use_item_on_detail[player][item].end()) {
            eventCounter.player_use_item_on_detail[player][item][blockName] = 1;
        } else {
            eventCounter.player_use_item_on_detail[player][item][blockName]++;
        }
        return true;
    });
    Event::PlayerPullFishingHookEvent::subscribe([](const Event::PlayerPullFishingHookEvent &event) {
        eventCounter.player_pull_fishing_pool_event++;
        string player = event.mPlayer->getRealName();
        string item = event.mItemStack->getTypeName();
        if (eventCounter.player_pull_fishing_pool_detail.find(player) ==
            eventCounter.player_pull_fishing_pool_detail.end()) {
            eventCounter.player_pull_fishing_pool_detail[player] = map<string, size_t>();
        }
        if (eventCounter.player_pull_fishing_pool_detail[player].find(item) ==
            eventCounter.player_pull_fishing_pool_detail[player].end()) {
            eventCounter.player_pull_fishing_pool_detail[player][item] = 1;
        } else {
            eventCounter.player_pull_fishing_pool_detail[player][item]++;
        }
        return true;
    });
    Event::PlayerUseBucketEvent::subscribe([](const Event::PlayerUseBucketEvent &event) {
        eventCounter.player_use_bucket_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_use_bucket_detail.find(player) == eventCounter.player_use_bucket_detail.end()) {
            eventCounter.player_use_bucket_detail[player] = 1;
        } else {
            eventCounter.player_use_bucket_detail[player]++;
        }
        return true;
    });
    Event::PlayerChatEvent::subscribe([](const Event::PlayerChatEvent &event) {
        eventCounter.player_chat_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_chat_detail.find(player) == eventCounter.player_chat_detail.end()) {
            eventCounter.player_chat_detail[player] = 1;
        } else {
            eventCounter.player_chat_detail[player]++;
        }
        return true;
    });
    Event::PlayerChangeDimEvent::subscribe([](const Event::PlayerChangeDimEvent &event) {
        eventCounter.player_change_dim_event++;
        string player = event.mPlayer->getRealName();
        int targetDim = event.mToDimensionId;
        if (eventCounter.player_change_dim_detail.find(player) == eventCounter.player_change_dim_detail.end()) {
            eventCounter.player_change_dim_detail[player] = map<int, size_t>();
        }
        if (eventCounter.player_change_dim_detail[player].find(targetDim) ==
            eventCounter.player_change_dim_detail[player].end()) {
            eventCounter.player_change_dim_detail[player][targetDim] = 1;
        } else {
            eventCounter.player_change_dim_detail[player][targetDim]++;
        }
        return true;
    });
    Event::PlayerJumpEvent::subscribe([](const Event::PlayerJumpEvent &event) {
        eventCounter.player_jump_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_jump_detail.find(player) == eventCounter.player_jump_detail.end()) {
            eventCounter.player_jump_detail[player] = 1;
        } else {
            eventCounter.player_jump_detail[player]++;
        }
        return true;
    });
    Event::PlayerSneakEvent::subscribe([](const Event::PlayerSneakEvent &event) {
        eventCounter.player_sneak_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_sneak_detail.find(player) == eventCounter.player_sneak_detail.end()) {
            eventCounter.player_sneak_detail[player] = 1;
        } else {
            eventCounter.player_sneak_detail[player]++;
        }
        return true;
    });
    Event::PlayerSwingEvent::subscribe([](const Event::PlayerSwingEvent &event) {
        eventCounter.player_swing_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_swing_detail.find(player) == eventCounter.player_swing_detail.end()) {
            eventCounter.player_swing_detail[player] = 1;
        } else {
            eventCounter.player_swing_detail[player]++;
        }
        return true;
    });
    Event::PlayerAttackEvent::subscribe([](const Event::PlayerAttackEvent &event) {
        eventCounter.player_attack_event++;
        string player = event.mPlayer->getRealName();
        string actor = event.mTarget->getTypeName();
        if (eventCounter.player_attack_detail.find(player) == eventCounter.player_attack_detail.end()) {
            eventCounter.player_attack_detail[player] = map<string, size_t>();
        }
        if (eventCounter.player_attack_detail[player].find(actor) == eventCounter.player_attack_detail[player].end()) {
            eventCounter.player_attack_detail[player][actor] = 1;
        } else {
            eventCounter.player_attack_detail[player][actor]++;
        }
        return true;
    });
    Event::PlayerAttackBlockEvent::subscribe([](const Event::PlayerAttackBlockEvent &event) {
        eventCounter.player_attack_block_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_attack_block_detail.find(player) == eventCounter.player_attack_block_detail.end()) {
            eventCounter.player_attack_block_detail[player] = 1;
        } else {
            eventCounter.player_attack_block_detail[player]++;
        }
        return true;
    });
    Event::PlayerDieEvent::subscribe([](const Event::PlayerDieEvent &event) {
        eventCounter.player_die_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_die_detail.find(player) == eventCounter.player_die_detail.end()) {
            eventCounter.player_die_detail[player] = 1;
        } else {
            eventCounter.player_die_detail[player]++;
        }
        return true;
    });
    Event::PlayerPickupItemEvent::subscribe([](const Event::PlayerPickupItemEvent &event) {
        eventCounter.player_pickup_item_event++;
        string player = event.mPlayer->getRealName();
        string item = event.mItemEntity->getTypeName();
        if (eventCounter.player_pickup_item_detail.find(player) == eventCounter.player_pickup_item_detail.end()) {
            eventCounter.player_pickup_item_detail[player] = map<string, size_t>();
        }
        if (eventCounter.player_pickup_item_detail[player].find(item) ==
            eventCounter.player_pickup_item_detail[player].end()) {
            eventCounter.player_pickup_item_detail[player][item] = 1;
        } else {
            eventCounter.player_pickup_item_detail[player][item]++;
        }
        return true;
    });
    Event::PlayerDropItemEvent::subscribe([](const Event::PlayerDropItemEvent &event) {
        eventCounter.player_drop_item_event++;
        string player = event.mPlayer->getRealName();
        string item = event.mItemStack->getTypeName();
        if (eventCounter.player_drop_item_detail.find(player) == eventCounter.player_drop_item_detail.end()) {
            eventCounter.player_drop_item_detail[player] = map<string, size_t>();
        }
        if (eventCounter.player_drop_item_detail[player].find(item) ==
            eventCounter.player_drop_item_detail[player].end()) {
            eventCounter.player_drop_item_detail[player][item] = 1;
        } else {
            eventCounter.player_drop_item_detail[player][item]++;
        }
        return true;
    });
    Event::PlayerEatEvent::subscribe([](const Event::PlayerEatEvent &event) {
        eventCounter.player_eat_event++;
        string player = event.mPlayer->getRealName();
        string item = event.mFoodItem->getTypeName();
        if (eventCounter.player_eat_detail.find(player) == eventCounter.player_eat_detail.end()) {
            eventCounter.player_eat_detail[player] = map<string, size_t>();
        }
        if (eventCounter.player_eat_detail[player].find(item) == eventCounter.player_eat_detail[player].end()) {
            eventCounter.player_eat_detail[player][item] = 1;
        } else {
            eventCounter.player_eat_detail[player][item]++;
        }
        return true;
    });
    Event::PlayerAteEvent::subscribe([](const Event::PlayerAteEvent &event) {
        eventCounter.player_ate_event++;
        string player = event.mPlayer->getRealName();
        string item = event.mFoodItem->getTypeName();
        if (eventCounter.player_ate_detail.find(player) == eventCounter.player_ate_detail.end()) {
            eventCounter.player_ate_detail[player] = map<string, size_t>();
        }
        if (eventCounter.player_ate_detail[player].find(item) == eventCounter.player_ate_detail[player].end()) {
            eventCounter.player_ate_detail[player][item] = 1;
        } else {
            eventCounter.player_ate_detail[player][item]++;
        }
        return true;
    });
    Event::PlayerConsumeTotemEvent::subscribe([](const Event::PlayerConsumeTotemEvent &event) {
        eventCounter.player_consume_totem_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_consume_totem_detail.find(player) == eventCounter.player_consume_totem_detail.end()) {
            eventCounter.player_consume_totem_detail[player] = 1;
        } else {
            eventCounter.player_consume_totem_detail[player]++;
        }
        return true;
    });
    Event::PlayerCmdEvent::subscribe([](const Event::PlayerCmdEvent &event) {
        eventCounter.player_cmd_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_cmd_detail.find(player) == eventCounter.player_cmd_detail.end()) {
            eventCounter.player_cmd_detail[player] = 1;
        } else {
            eventCounter.player_cmd_detail[player]++;
        }
        return true;
    });
    Event::PlayerEffectChangedEvent::subscribe([](const Event::PlayerEffectChangedEvent &event) {
        eventCounter.player_effect_changed_event++;
        string player = event.mPlayer->getRealName();
        string effect = event.mEffect->getDisplayName();
        string type;
        switch (event.mEventType) {
            case Event::PlayerEffectChangedEvent::EventType::Add:
                type = "add";
                break;
            case Event::PlayerEffectChangedEvent::EventType::Remove:
                type = "remove";
                break;
            case Event::PlayerEffectChangedEvent::EventType::Update:
                type = "update";
                break;
            default:
                type = "unknown";
                break;
        }
        if (eventCounter.player_effect_changed_detail.find(player) == eventCounter.player_effect_changed_detail.end()) {
            eventCounter.player_effect_changed_detail[player] = map<string, map<string, size_t>>();
        }
        if (eventCounter.player_effect_changed_detail[player].find(effect) ==
            eventCounter.player_effect_changed_detail[player].end()) {
            eventCounter.player_effect_changed_detail[player][effect] = map<string, size_t>();
        }
        if (eventCounter.player_effect_changed_detail[player][effect].find(type) ==
            eventCounter.player_effect_changed_detail[player][effect].end()) {
            eventCounter.player_effect_changed_detail[player][effect][type] = 1;
        } else {
            eventCounter.player_effect_changed_detail[player][effect][type]++;
        }
        return true;
    });
    Event::PlayerStartDestroyBlockEvent::subscribe([](const Event::PlayerStartDestroyBlockEvent &event) {
        eventCounter.player_start_destroy_block_event++;
        string player = event.mPlayer->getRealName();
        auto block = event.mBlockInstance;
        HashedString hBlockName = block.getBlock()->getName();
        const string &blockName = hBlockName.getString();
        if (eventCounter.player_start_destroy_block_detail.find(player) ==
            eventCounter.player_start_destroy_block_detail.end()) {
            eventCounter.player_start_destroy_block_detail[player] = map<string, size_t>();
        }
        if (eventCounter.player_start_destroy_block_detail[player].find(blockName) ==
            eventCounter.player_start_destroy_block_detail[player].end()) {
            eventCounter.player_start_destroy_block_detail[player][blockName] = 1;
        } else {
            eventCounter.player_start_destroy_block_detail[player][blockName]++;
        }
        return true;
    });
    Event::PlayerDestroyBlockEvent::subscribe([](const Event::PlayerDestroyBlockEvent &event) {
        eventCounter.player_destroy_block_event++;
        string player = event.mPlayer->getRealName();
        auto block = event.mBlockInstance;
        HashedString hBlockName = block.getBlock()->getName();
        const string &blockName = hBlockName.getString();
        if (eventCounter.player_destroy_block_detail.find(player) == eventCounter.player_destroy_block_detail.end()) {
            eventCounter.player_destroy_block_detail[player] = map<string, size_t>();
        }
        if (eventCounter.player_destroy_block_detail[player].find(blockName) ==
            eventCounter.player_destroy_block_detail[player].end()) {
            eventCounter.player_destroy_block_detail[player][blockName] = 1;
        } else {
            eventCounter.player_destroy_block_detail[player][blockName]++;
        }
        return true;
    });
    Event::PlayerPlaceBlockEvent::subscribe([](const Event::PlayerPlaceBlockEvent &event) {
        eventCounter.player_place_block_event++;
        string player = event.mPlayer->getRealName();
        auto block = event.mBlockInstance;
        HashedString hBlockName = block.getBlock()->getName();
        const string &blockName = hBlockName.getString();
        if (eventCounter.player_place_block_detail.find(player) == eventCounter.player_place_block_detail.end()) {
            eventCounter.player_place_block_detail[player] = map<string, size_t>();
        }
        if (eventCounter.player_place_block_detail[player].find(blockName) ==
            eventCounter.player_place_block_detail[player].end()) {
            eventCounter.player_place_block_detail[player][blockName] = 1;
        } else {
            eventCounter.player_place_block_detail[player][blockName]++;
        }
        return true;
    });
    Event::BlockPlacedByPlayerEvent::subscribe([](const Event::BlockPlacedByPlayerEvent &event) {
        eventCounter.block_placed_by_player_event++;
        string player = event.mPlayer->getRealName();
        auto block = event.mBlockInstance;
        HashedString hBlockName = block.getBlock()->getName();
        const string &blockName = hBlockName.getString();
        if (eventCounter.block_placed_by_player_detail.find(player) ==
            eventCounter.block_placed_by_player_detail.end()) {
            eventCounter.block_placed_by_player_detail[player] = map<string, size_t>();
        }
        if (eventCounter.block_placed_by_player_detail[player].find(blockName) ==
            eventCounter.block_placed_by_player_detail[player].end()) {
            eventCounter.block_placed_by_player_detail[player][blockName] = 1;
        } else {
            eventCounter.block_placed_by_player_detail[player][blockName]++;
        }
        return true;
    });
    Event::PlayerOpenContainerEvent::subscribe([](const Event::PlayerOpenContainerEvent &event) {
        eventCounter.player_open_container_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_open_container_detail.find(player) == eventCounter.player_open_container_detail.end()) {
            eventCounter.player_open_container_detail[player] = 1;
        } else {
            eventCounter.player_open_container_detail[player]++;
        }
        return true;
    });
    Event::PlayerCloseContainerEvent::subscribe([](const Event::PlayerCloseContainerEvent &event) {
        eventCounter.player_close_container_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_close_container_detail.find(player) ==
            eventCounter.player_close_container_detail.end()) {
            eventCounter.player_close_container_detail[player] = 1;
        } else {
            eventCounter.player_close_container_detail[player]++;
        }
        return true;
    });
    Event::PlayerInventoryChangeEvent::subscribe([](const Event::PlayerInventoryChangeEvent &event) {
        eventCounter.player_inventory_change_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_inventory_change_detail.find(player) ==
            eventCounter.player_inventory_change_detail.end()) {
            eventCounter.player_inventory_change_detail[player] = 1;
        } else {
            eventCounter.player_inventory_change_detail[player]++;
        }
        return true;
    });
    Event::PlayerSprintEvent::subscribe([](const Event::PlayerSprintEvent &event) {
        eventCounter.player_sprint_event++;
        string player = event.mPlayer->getRealName();
        string isSprinting = event.mIsSprinting ? "true" : "false";
        if (eventCounter.player_sprint_detail.find(player) == eventCounter.player_sprint_detail.end()) {
            eventCounter.player_sprint_detail[player] = map<string, size_t>();
        }
        if (eventCounter.player_sprint_detail[player].find(isSprinting) ==
            eventCounter.player_sprint_detail[player].end()) {
            eventCounter.player_sprint_detail[player][isSprinting] = 1;
        } else {
            eventCounter.player_sprint_detail[player][isSprinting]++;
        }
        return true;
    });
    Event::PlayerSetArmorEvent::subscribe([](const Event::PlayerSetArmorEvent &event) {
        eventCounter.player_set_armor_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_set_armor_detail.find(player) == eventCounter.player_set_armor_detail.end()) {
            eventCounter.player_set_armor_detail[player] = 1;
        } else {
            eventCounter.player_set_armor_detail[player]++;
        }
        return true;
    });
    Event::PlayerUseRespawnAnchorEvent::subscribe([](const Event::PlayerUseRespawnAnchorEvent &event) {
        eventCounter.player_use_respawn_anchor_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_use_respawn_anchor_detail.find(player) ==
            eventCounter.player_use_respawn_anchor_detail.end()) {
            eventCounter.player_use_respawn_anchor_detail[player] = 1;
        } else {
            eventCounter.player_use_respawn_anchor_detail[player]++;
        }
        return true;
    });
    Event::PlayerOpenContainerScreenEvent::subscribe([](const Event::PlayerOpenContainerScreenEvent &event) {
        eventCounter.player_open_container_screen_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_open_container_screen_detail.find(player) ==
            eventCounter.player_open_container_screen_detail.end()) {
            eventCounter.player_open_container_screen_detail[player] = 1;
        } else {
            eventCounter.player_open_container_screen_detail[player]++;
        }
        return true;
    });
    Event::PlayerUseFrameBlockEvent::subscribe([](const Event::PlayerUseFrameBlockEvent &event) {
        eventCounter.player_use_frame_block_event++;
        string player = event.mPlayer->getRealName();
        auto block = event.mBlockInstance;
        HashedString hBlockName = block.getBlock()->getName();
        const string &blockName = hBlockName.getString();
        string type;
        switch (event.mType) {
            case Event::PlayerUseFrameBlockEvent::Type::None:
                type = "None";
                break;
            case Event::PlayerUseFrameBlockEvent::Type::Use:
                type = "Use";
                break;
            case Event::PlayerUseFrameBlockEvent::Type::Attack:
                type = "Attack";
                break;
        }
        if (eventCounter.player_use_frame_block_detail.find(player) ==
            eventCounter.player_use_frame_block_detail.end()) {
            eventCounter.player_use_frame_block_detail[player] = map<string, map<string, size_t>>();
        }
        if (eventCounter.player_use_frame_block_detail[player].find(blockName) ==
            eventCounter.player_use_frame_block_detail[player].end()) {
            eventCounter.player_use_frame_block_detail[player][blockName] = map<string, size_t>();
        }
        if (eventCounter.player_use_frame_block_detail[player][blockName].find(type) ==
            eventCounter.player_use_frame_block_detail[player][blockName].end()) {
            eventCounter.player_use_frame_block_detail[player][blockName][type] = 1;
        } else {
            eventCounter.player_use_frame_block_detail[player][blockName][type]++;
        }
        return true;
    });
    Event::PlayerScoreChangedEvent::subscribe([](const Event::PlayerScoreChangedEvent &event) {
        eventCounter.player_score_changed_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_score_changed_detail.find(player) == eventCounter.player_score_changed_detail.end()) {
            eventCounter.player_score_changed_detail[player] = 1;
        } else {
            eventCounter.player_score_changed_detail[player]++;
        }
        return true;
    });
    Event::PlayerExperienceAddEvent::subscribe([](const Event::PlayerExperienceAddEvent &event) {
        eventCounter.player_experience_add_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_experience_add_detail.find(player) == eventCounter.player_experience_add_detail.end()) {
            eventCounter.player_experience_add_detail[player] = 1;
        } else {
            eventCounter.player_experience_add_detail[player]++;
        }
        return true;
    });
    Event::PlayerInteractEntityEvent::subscribe([](const Event::PlayerInteractEntityEvent &event) {
        eventCounter.player_interact_entity_event++;
        //auto mPlayer = event.mPlayer;
        return true;
    });
    Event::PlayerBedEnterEvent::subscribe([](const Event::PlayerBedEnterEvent &event) {
        eventCounter.player_bed_enter_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_bed_enter_detail.find(player) == eventCounter.player_bed_enter_detail.end()) {
            eventCounter.player_bed_enter_detail[player] = 1;
        } else {
            eventCounter.player_bed_enter_detail[player]++;
        }
        return true;
    });
    Event::PlayerOpenInventoryEvent::subscribe([](const Event::PlayerOpenInventoryEvent &event) {
        eventCounter.player_open_inventory_event++;
        string player = event.mPlayer->getRealName();
        if (eventCounter.player_open_inventory_detail.find(player) == eventCounter.player_open_inventory_detail.end()) {
            eventCounter.player_open_inventory_detail[player] = 1;
        } else {
            eventCounter.player_open_inventory_detail[player]++;
        }
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
    for (auto &i: eventCounter.player_join_detail) {
        mm.newMetrics("player_join_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_left_event_count", eventCounter.player_left_event);
    for (auto &i: eventCounter.player_left_detail) {
        mm.newMetrics("player_left_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_respawn_event_count", eventCounter.player_respawn_event);
    for (auto &i: eventCounter.player_respawn_detail) {
        mm.newMetrics("player_respawn_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_use_item_event_count", eventCounter.player_use_item_event);
    for (auto &i: eventCounter.player_use_item_detail) {
        for (auto &j: i.second) {
            mm.newMetrics("player_use_item_event_count", j.second)
                    ->label("player", i.first)
                    ->label("item", j.first);
        }
    }
    mm.newMetrics("player_use_item_on_event_count", eventCounter.player_use_item_on_event);
    for (auto &i: eventCounter.player_use_item_on_detail) {
        for (auto &j: i.second) {
            for (auto &k: j.second) {
                mm.newMetrics("player_use_item_on_event_count", k.second)
                        ->label("player", i.first)
                        ->label("item", j.first)
                        ->label("target", k.first);
            }
        }
    }
    mm.newMetrics("player_pull_fishing_pool_event_count", eventCounter.player_pull_fishing_pool_event);
    for (auto &i: eventCounter.player_pull_fishing_pool_detail) {
        for (auto &j: i.second) {
            mm.newMetrics("player_pull_fishing_pool_event_count", j.second)
                    ->label("player", i.first)
                    ->label("item", j.first);
        }
    }
    mm.newMetrics("player_use_bucket_event_count", eventCounter.player_use_bucket_event);
    for (auto &i: eventCounter.player_use_bucket_detail) {
        mm.newMetrics("player_use_bucket_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_chat_event_count", eventCounter.player_chat_event);
    for (auto &i: eventCounter.player_chat_detail) {
        mm.newMetrics("player_chat_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_change_dim_event_count", eventCounter.player_change_dim_event);
    for (auto &i: eventCounter.player_change_dim_detail) {
        for (auto &j: i.second) {
            mm.newMetrics("player_change_dim_event_count", j.second)
                    ->label("player", i.first)
                    ->label("to", to_string(j.first));
        }
    }
    mm.newMetrics("player_jump_event_count", eventCounter.player_jump_event);
    for (auto &i: eventCounter.player_jump_detail) {
        mm.newMetrics("player_jump_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_sneak_event_count", eventCounter.player_sneak_event);
    for (auto &i: eventCounter.player_sneak_detail) {
        mm.newMetrics("player_sneak_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_swing_event_count", eventCounter.player_swing_event);
    for (auto &i: eventCounter.player_swing_detail) {
        mm.newMetrics("player_swing_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_attack_event_count", eventCounter.player_attack_event);
    for (auto &i: eventCounter.player_attack_detail) {
        for (auto &j: i.second) {
            mm.newMetrics("player_attack_event_count", j.second)
                    ->label("player", i.first)
                    ->label("target", j.first);
        }
    }
    mm.newMetrics("player_attack_block_event_count", eventCounter.player_attack_block_event);
    for (auto &i: eventCounter.player_attack_block_detail) {
        mm.newMetrics("player_attack_block_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_die_event_count", eventCounter.player_die_event);
    for (auto &i: eventCounter.player_die_detail) {
        mm.newMetrics("player_die_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_pickup_item_event_count", eventCounter.player_pickup_item_event);
    for (auto &i: eventCounter.player_pickup_item_detail) {
        for (auto &j: i.second) {
            mm.newMetrics("player_pickup_item_event_count", j.second)
                    ->label("player", i.first)
                    ->label("item", j.first);
        }
    }
    mm.newMetrics("player_drop_item_event_count", eventCounter.player_drop_item_event);
    for (auto &i: eventCounter.player_drop_item_detail) {
        for (auto &j: i.second) {
            mm.newMetrics("player_drop_item_event_count", j.second)
                    ->label("player", i.first)
                    ->label("item", j.first);
        }
    }
    mm.newMetrics("player_eat_event_count", eventCounter.player_eat_event);
    for (auto &i: eventCounter.player_eat_detail) {
        for (auto &j: i.second) {
            mm.newMetrics("player_eat_event_count", j.second)
                    ->label("player", i.first)
                    ->label("item", j.first);
        }
    }
    mm.newMetrics("player_ate_event_count", eventCounter.player_ate_event);
    for (auto &i: eventCounter.player_ate_detail) {
        for (auto &j: i.second) {
            mm.newMetrics("player_ate_event_count", j.second)
                    ->label("player", i.first)
                    ->label("item", j.first);
        }
    }
    mm.newMetrics("player_consume_totem_event_count", eventCounter.player_consume_totem_event);
    for (auto &i: eventCounter.player_consume_totem_detail) {
        mm.newMetrics("player_consume_totem_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_cmd_event_count", eventCounter.player_cmd_event);
    for (auto &i: eventCounter.player_cmd_detail) {
        mm.newMetrics("player_cmd_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_effect_changed_event_count", eventCounter.player_effect_changed_event);
    for (auto &i: eventCounter.player_effect_changed_detail) {
        for (auto &j: i.second) {
            for (auto &k: j.second) {
                mm.newMetrics("player_effect_changed_event_count", k.second)
                        ->label("player", i.first)
                        ->label("effect", j.first)
                        ->label("type", k.first);
            }
        }
    }
    mm.newMetrics("player_start_destroy_block_event_count", eventCounter.player_start_destroy_block_event);
    for (auto &i: eventCounter.player_start_destroy_block_detail) {
        for (auto &j: i.second) {
            mm.newMetrics("player_start_destroy_block_event_count", j.second)
                    ->label("player", i.first)
                    ->label("block", j.first);
        }
    }
    mm.newMetrics("player_destroy_block_event_count", eventCounter.player_destroy_block_event);
    for (auto &i: eventCounter.player_destroy_block_detail) {
        for (auto &j: i.second) {
            mm.newMetrics("player_destroy_block_event_count", j.second)
                    ->label("player", i.first)
                    ->label("block", j.first);
        }
    }
    mm.newMetrics("player_place_block_event_count", eventCounter.player_place_block_event);
    for (auto &i: eventCounter.player_place_block_detail) {
        for (auto &j: i.second) {
            mm.newMetrics("player_place_block_event_count", j.second)
                    ->label("player", i.first)
                    ->label("on_block", j.first);
        }
    }
    mm.newMetrics("block_placed_by_player_event_count", eventCounter.block_placed_by_player_event);
    for (auto &i: eventCounter.block_placed_by_player_detail) {
        for (auto &j: i.second) {
            mm.newMetrics("block_placed_by_player_event_count", j.second)
                    ->label("player", i.first)
                    ->label("block", j.first);
        }
    }
    mm.newMetrics("player_open_container_event_count", eventCounter.player_open_container_event);
    for (auto &i: eventCounter.player_open_container_detail) {
        mm.newMetrics("player_open_container_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_close_container_event_count", eventCounter.player_close_container_event);
    for (auto &i: eventCounter.player_close_container_detail) {
        mm.newMetrics("player_close_container_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_inventory_change_event_count", eventCounter.player_inventory_change_event);
    for (auto &i: eventCounter.player_inventory_change_detail) {
        mm.newMetrics("player_inventory_change_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_sprint_event_count", eventCounter.player_sprint_event);
    for (auto &i: eventCounter.player_sprint_detail) {
        for (auto &j: i.second) {
            mm.newMetrics("player_sprint_event_count", j.second)
                    ->label("player", i.first)
                    ->label("is_sprinting", j.first);
        }
    }
    mm.newMetrics("player_set_armor_event_count", eventCounter.player_set_armor_event);
    for (auto &i: eventCounter.player_set_armor_detail) {
        mm.newMetrics("player_set_armor_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_use_respawn_anchor_event_count", eventCounter.player_use_respawn_anchor_event);
    for (auto &i: eventCounter.player_use_respawn_anchor_detail) {
        mm.newMetrics("player_use_respawn_anchor_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_open_container_screen_event_count", eventCounter.player_open_container_screen_event);
    for (auto &i: eventCounter.player_open_container_screen_detail) {
        mm.newMetrics("player_open_container_screen_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_use_frame_block_event_count", eventCounter.player_use_frame_block_event);
    for (auto &i: eventCounter.player_use_frame_block_detail) {
        for (auto &j: i.second) {
            for (auto &k: j.second) {
                mm.newMetrics("player_use_frame_block_event_count", k.second)
                        ->label("player", i.first)
                        ->label("block", j.first)
                        ->label("type", k.first);
            }
        }
    }
    mm.newMetrics("player_score_changed_event_count", eventCounter.player_score_changed_event);
    for (auto &i: eventCounter.player_score_changed_detail) {
        mm.newMetrics("player_score_changed_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_experience_add_event_count", eventCounter.player_experience_add_event);
    for (auto &i: eventCounter.player_experience_add_detail) {
        mm.newMetrics("player_experience_add_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_interact_entity_event_count", eventCounter.player_interact_entity_event);
    mm.newMetrics("player_bed_enter_event_count", eventCounter.player_bed_enter_event);
    for (auto &i: eventCounter.player_bed_enter_detail) {
        mm.newMetrics("player_bed_enter_event_count", i.second)
                ->label("player", i.first);
    }
    mm.newMetrics("player_open_inventory_event_count", eventCounter.player_open_inventory_event);
    for (auto &i: eventCounter.player_open_inventory_detail) {
        mm.newMetrics("player_open_inventory_event_count", i.second)
                ->label("player", i.first);
    }
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