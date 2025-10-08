//
// Created by Raghuvansh Agarwal on 08/10/25.
//

#ifndef MINESWEEPER_SFML_ASSETMANAGER_H
#define MINESWEEPER_SFML_ASSETMANAGER_H
#include <string>

namespace Asset {
    class AssetManager {
    public:
        class Fonts {
        public:
            static std::string bubble_bobble_font_path_;
            static std::string ds_digib_font_path_;
            static std::string roboto_font_path_;
        };

        class Sounds {
        public:
            static std::string background_music_path_;
            static std::string button_click_sound_path_;
            static std::string explosion_sound_path_;
            static std::string flag_sound_path_;
            static std::string game_won_sound_path_;
        };

        class Textures {
        public:
            static std::string board_texture_path_;
            static std::string cell_texture_path_;
            static std::string instructions_texture_path_;
            static std::string menu_button_texture_path_;
            static std::string minesweeper_bg_texture_path_;
            static std::string outscal_logo_texture_path_;
            static std::string play_button_texture_path_;
            static std::string quit_button_texture_path_;
            static std::string restart_button_texture_path_;
        };
    };
} // Asset

#endif //MINESWEEPER_SFML_ASSETMANAGER_H