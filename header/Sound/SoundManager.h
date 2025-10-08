#pragma once
#include <SFML/Audio.hpp>
#include <string>

namespace Sound
{
    enum class SoundType
    {
        BUTTON_CLICK,
        FLAG,
        EXPLOSION,
        GAME_WON
    };

    class SoundManager
    {
    private:
        static sf::Music backgroundMusic;
        static sf::SoundBuffer bufferButtonClick;
        static sf::SoundBuffer bufferFlagSound;
        static sf::SoundBuffer bufferExplosion;
        static sf::SoundBuffer bufferGameWon;
        static sf::Sound soundEffect;
        static float backgroundMusicVolume;

    public:
        // Initialization and loading functions
        static void Initialize();
        static void PlaySound(SoundType soundType);
        static void PlayBackgroundMusic();

    private:
        static void LoadBackgroundMusicFromFile();
        static void LoadSoundFromFile();
    };
}