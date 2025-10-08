#include "../../header/Sound/SoundManager.h"
#include <iostream>

#include "../../header/Assets/AssetManager.h"

namespace Sound
{

    sf::Music SoundManager::backgroundMusic;
    sf::SoundBuffer SoundManager::bufferButtonClick;
    sf::SoundBuffer SoundManager::bufferFlagSound;
    sf::SoundBuffer SoundManager::bufferExplosion;
    sf::SoundBuffer SoundManager::bufferGameWon;
    sf::Sound SoundManager::soundEffect;

    float SoundManager::backgroundMusicVolume = 8.0f;

    void SoundManager::Initialize()
    {
        LoadBackgroundMusicFromFile();
        LoadSoundFromFile();
    }

    void SoundManager::LoadBackgroundMusicFromFile()
    {
        if (!backgroundMusic.openFromFile(Asset::AssetManager::Sounds::background_music_path_))
            std::cerr << "Error loading background music file: " << std::endl;
    }

    void SoundManager::LoadSoundFromFile()
    {
        if (!bufferButtonClick.loadFromFile(Asset::AssetManager::Sounds::button_click_sound_path_))
            std::cerr << "Error loading sound file: " << std::endl;
        if (!bufferFlagSound.loadFromFile(Asset::AssetManager::Sounds::flag_sound_path_))
            std::cerr << "Error loading sound file: " << std::endl;
        if (!bufferExplosion.loadFromFile(Asset::AssetManager::Sounds::explosion_sound_path_))
            std::cerr << "Error loading sound file: " << std::endl;
        if (!bufferGameWon.loadFromFile(Asset::AssetManager::Sounds::game_won_sound_path_))
            std::cerr << "Error loading sound file: " << std::endl;
    }

    void SoundManager::PlaySound(SoundType soundType)
    {
        switch (soundType)
        {
        case SoundType::BUTTON_CLICK:
            soundEffect.setBuffer(bufferButtonClick);
            break;
        case SoundType::FLAG:
            soundEffect.setBuffer(bufferFlagSound);
            break;
        case SoundType::EXPLOSION:
            soundEffect.setBuffer(bufferExplosion);
            break;
        case SoundType::GAME_WON:
            soundEffect.setBuffer(bufferGameWon);
            break;
        default:
            std::cerr << "Invalid sound type" << std::endl;
            return;
        }

        soundEffect.play();
    }

    void SoundManager::PlayBackgroundMusic()
    {
        backgroundMusic.setLoop(true);
        backgroundMusic.setVolume(backgroundMusicVolume);
        backgroundMusic.play();
    }
}
