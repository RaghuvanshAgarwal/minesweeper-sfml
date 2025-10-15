#pragma once
#include <SFML/Graphics.hpp>

namespace UI {
    class SplashScreenManager {
    private:
        sf::RenderWindow* game_window;
        sf::Texture logo_texture;
        sf::Sprite logo_sprite;

        const float logo_animation_duration = 2.0f;

        float elapsed_time = 0.0f;

        void initialize();
        sf::Vector2f getLogoPosition();
        void drawLogo();

    public:
        SplashScreenManager(sf::RenderWindow* window);
        ~SplashScreenManager();

        void update();
        void render();
    };
}