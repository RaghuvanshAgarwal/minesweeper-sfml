//
// Created by Raghuvansh Agarwal on 08/10/25.
//

#include "../../header/Assets/AssetManager.h"

namespace Asset {
    std::string AssetManager::Fonts::bubble_bobble_font_path_ = std::string(PROJECT_ROOT) + "assets/fonts/bubbleBobble.ttf";
    std::string AssetManager::Fonts::ds_digib_font_path_ = std::string(PROJECT_ROOT) + "assets/fonts/DS_DIGIB.TTF";
    std::string AssetManager::Fonts::roboto_font_path_ = std::string(PROJECT_ROOT) + "assets/fonts/roboto.ttf";

    std::string AssetManager::Sounds::background_music_path_ = std::string(PROJECT_ROOT) + "assets/sounds/background_music.mp3";
    std::string AssetManager::Sounds::button_click_sound_path_ = std::string(PROJECT_ROOT) + "assets/sounds/button_click_sound.wav";
    std::string AssetManager::Sounds::explosion_sound_path_ = std::string(PROJECT_ROOT) + "assets/sounds/explosion_sound.wav";
    std::string AssetManager::Sounds::flag_sound_path_ = std::string(PROJECT_ROOT) + "assets/sounds/flag_sound.wav";
    std::string AssetManager::Sounds::game_won_sound_path_ = std::string(PROJECT_ROOT) + "assets/sounds/game_won_sound.wav";

    std::string AssetManager::Textures::board_texture_path_ = std::string(PROJECT_ROOT) + "assets/textures/board.png";
    std::string AssetManager::Textures::cell_texture_path_ = std::string(PROJECT_ROOT) + "assets/textures/cells.jpeg";
    std::string AssetManager::Textures::instructions_texture_path_ = std::string(PROJECT_ROOT) + "assets/textures/instructions_button.png";
    std::string AssetManager::Textures::menu_button_texture_path_ = std::string(PROJECT_ROOT) + "assets/textures/menu_button.png";
    std::string AssetManager::Textures::minesweeper_bg_texture_path_ = std::string(PROJECT_ROOT) + "assets/textures/minesweeper_bg.png";
    std::string AssetManager::Textures::outscal_logo_texture_path_ = std::string(PROJECT_ROOT) + "assets/textures/outscal_logo.png";
    std::string AssetManager::Textures::play_button_texture_path_ = std::string(PROJECT_ROOT) + "assets/textures/play_button.png";
    std::string AssetManager::Textures::quit_button_texture_path_ = std::string(PROJECT_ROOT) + "assets/textures/quit_button.png";
    std::string AssetManager::Textures::restart_button_texture_path_ = std::string(PROJECT_ROOT) + "assets/textures/restart_button.png";
} // Asset