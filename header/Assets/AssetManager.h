//
// Created by Raghuvansh Agarwal on 08/10/25.
//

#ifndef MINESWEEPER_SFML_ASSETMANAGER_H
#define MINESWEEPER_SFML_ASSETMANAGER_H
#include <string>
#include <unordered_map>

#include "SFML/Graphics/Texture.hpp"

namespace Asset {
    enum class SoundType {
        Background,
        ButtonClick,
        Explosion,
        Flag,
        GameWon,
    };

    enum class FontType {
        BubbleBobble,
        DsDigib,
        Roboto,
    };

    enum class TextureType {
        Board,
        Cell,
        Instruction,
        MenuButton,
        MinesweeperBackground,
        Logo,
        PlayButton,
        QuitButton,
        RestartButton,
    };

    class AssetManager {
        static std::unordered_map<SoundType, std::string> sounds;
        static std::unordered_map<FontType, std::string> fonts;
        static std::unordered_map<TextureType, std::string> textures;
    public:
        static std::string getSound(SoundType p_sound);
        static std::string getFont(FontType p_font);
        static std::string getTexture(TextureType p_texture);
    };
} // Asset

#endif //MINESWEEPER_SFML_ASSETMANAGER_H