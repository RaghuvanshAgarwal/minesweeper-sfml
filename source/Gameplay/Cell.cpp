//
// Created by Raghuvansh Agarwal on 10/10/25.
//

#include "../../header/Gameplay/Cell.h"

#include "../../header/Assets/AssetManager.h"

namespace Gameplay {
    void Cell::initialize(float p_width, float p_height, sf::Vector2i p_position) {
        position_ = p_position;
        const auto position = sf::Vector2f(static_cast<float>(p_position.x),static_cast<float>(p_position.y));
        button_ = new UIElements::Button(Asset::AssetManager::getTexture(Asset::TextureType::Cell), position, {p_width*slice_count_,p_height});
    }

    Cell::Cell(float p_width, float p_height, sf::Vector2i p_position) {
        initialize(p_width,p_height,p_position);
    }

    Cell::~Cell() {
        delete button_;
    }

    void Cell::render(sf::RenderWindow &window) const {
        if (button_) {
            button_->render(window);
        }
    }
} // Gameplay