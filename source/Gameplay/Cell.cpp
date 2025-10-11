//
// Created by Raghuvansh Agarwal on 10/10/25.
//

#include "../../header/Gameplay/Cell.h"
#include "../../header/UI/UIElements/Button/Button.h"
#include "../../header/Gameplay/Board.h"

#include "../../header/Assets/AssetManager.h"

namespace Gameplay {
    void Cell::initialize(float p_width, float p_height, sf::Vector2i p_position) {
        position_ = p_position;
        cell_width_ = p_width;
        cell_height_ = p_height;
        button_ = new UIElements::Button(Asset::AssetManager::getTexture(Asset::TextureType::Cell), getScreenPosition(), {p_width * slice_count_,p_height});
        registerCellButtonCallback();
        setState(CellState::Hidden);
        setType(CellType::Empty);
    }

    sf::Vector2f Cell::getScreenPosition() const {
        float xScreenPosition = cell_left_offset_ + (position_.x * cell_width_);
        float yScreenPosition = cell_top_offset_ + (position_.y * cell_height_);
        return {xScreenPosition, yScreenPosition};
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

    void Cell::registerCellButtonCallback() const {
        button_->registerCallback([this](UIElements::MouseButtonType p_button) {
           board_->onCellButtonClick(position_, p_button);
        });
    }

    Cell::Cell(float p_width, float p_height, sf::Vector2i p_position, Board* p_board): board_(p_board) {
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
    void Cell::update(Event::EventPollingManager &event_manager, const sf::RenderWindow &window) {
        button_->handleButtonInteractions(event_manager, window);
    }

    void Cell::render(sf::RenderWindow &window) const {
        if (button_) {
            button_->render(window);
        }
    }
} // Gameplay