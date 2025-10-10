//
// Created by Raghuvansh Agarwal on 10/10/25.
//

#include "../../header/Gameplay/Cell.h"

#include "../../header/Assets/AssetManager.h"

namespace Gameplay {
    void Cell::initialize(float p_width, float p_height, sf::Vector2i p_position) {
        position_ = p_position;
        const auto position = sf::Vector2f(static_cast<float>(p_position.x),static_cast<float>(p_position.y));
        button_ = new UIElements::Button(Asset::AssetManager::getTexture(Asset::TextureType::Cell), position, {p_width * slice_count_,p_height});
        setState(CellState::Opened);
        setType(CellType::Empty);
    }

    void Cell::updateTextureRect() {
        sf::IntRect rect;
        rect.top = 0,
        rect.width = tile_size_;
        rect.height = tile_size_;
        switch (state_) {
            case CellState::Flagged:
                rect.left = 11 * tile_size_;
                break;
            case CellState::Hidden:
                rect.left = 10 * tile_size_;
                break;
            case CellState::Opened:
                rect.left = static_cast<int>(type_) * tile_size_;
                break;
            default:
                throw std::runtime_error("Invalid State");
        }
        button_->setTextureRect(rect);
    }

    Cell::Cell(float p_width, float p_height, sf::Vector2i p_position) {
        initialize(p_width,p_height,p_position);
    }

    Cell::~Cell() {
        delete button_;
    }

    CellType Cell::getType() const {
        return type_;
    }

    CellState Cell::getState() const {
        return state_;
    }

    void Cell::setState(const CellState p_state) {
        state_ = p_state;
        updateTextureRect();
    }

    void Cell::setType(CellType p_type) {
        type_ = p_type;
        updateTextureRect();
    }

    void Cell::render(sf::RenderWindow &window) const {
        if (button_) {
            button_->render(window);
        }
    }
} // Gameplay