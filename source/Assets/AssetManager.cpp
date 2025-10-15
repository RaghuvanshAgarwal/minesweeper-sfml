//
// Created by Raghuvansh Agarwal on 08/10/25.
//

#include "../../header/Assets/AssetManager.h"

namespace Asset {
    std::unordered_map<SoundType, std::string> AssetManager::sounds = {
        {SoundType::Background, "assets/sounds/background_music.mp3"},
        {SoundType::ButtonClick, "assets/sounds/button_click_sound.wav"},
        {SoundType::Explosion, "assets/sounds/explosion_sound.wav"},
        {SoundType::Flag, "assets/sounds/flag_sound.wav"},
        {SoundType::GameWon, "assets/sounds/game_won_sound.wav"}
    };

    std::unordered_map<FontType, std::string> AssetManager::fonts = {
        {FontType::BubbleBobble, "assets/fonts/bubbleBobble.ttf"},
        {FontType::DsDigib, "assets/fonts/DS_DIGIB.TTF"},
        {FontType::Roboto, "assets/fonts/roboto.ttf"}
    };

    std::unordered_map<TextureType, std::string> AssetManager::textures = {
        {TextureType::Board , "assets/textures/board.png"},
        {TextureType::Cell, "assets/textures/cells.jpeg"},
        {TextureType::Instruction, "assets/textures/instructions_button.png"},
        {TextureType::MenuButton, "assets/textures/menu_button.png"},
        {TextureType::MinesweeperBackground , "assets/textures/minesweeper_bg.png"},
        {TextureType::Logo, "assets/textures/logo.png"},
        {TextureType::PlayButton, "assets/textures/play_button.png"},
        {TextureType::QuitButton, "assets/textures/quit_button.png"},
        {TextureType::RestartButton,"assets/textures/restart_button.png"}
    };

    std::string AssetManager::getSound(SoundType p_sound) {
        return std::string(PROJECT_ROOT) + sounds[p_sound];
    }

    std::string AssetManager::getFont(FontType p_font) {
        return std::string(PROJECT_ROOT) + fonts[p_font];
    }

    std::string AssetManager::getTexture(TextureType p_texture) {
        return std::string(PROJECT_ROOT) + textures[p_texture];
    }
} // Asset