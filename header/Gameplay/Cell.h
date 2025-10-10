//
// Created by Raghuvansh Agarwal on 10/10/25.
//

#ifndef MINESWEEPER_SFML_CELL_H
#define MINESWEEPER_SFML_CELL_H
#include "../UI/UIElements/Button/Button.h"
#include "SFML/Graphics.hpp"

namespace Gameplay {
    enum class CellType {
        Empty,
        One,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Mine,
    };

    enum class CellState {
        Hidden,
        Opened,
        Flagged
    };

    class Cell {
        sf::Vector2i position_;
        const int tile_size_ = 128;
        const int slice_count_ = 12;
        const float cell_top_offset_ = 274.f;
        const float cell_left_offset_ = 583.f;
        UIElements::Button* button_{};
        CellState state_ = CellState::Hidden;
        CellType type_ = CellType::Empty;

        void initialize(float p_width,float p_height, sf::Vector2i p_position);
        sf::Vector2f getScreenPosition() const;
        void updateTextureRect();
        public:
        Cell(float p_width,float p_height, sf::Vector2i p_position);
        ~Cell();
        [[nodiscard]] CellType getType() const;
        [[nodiscard]] CellState getState() const;
        void setState(CellState p_state);
        void setType(CellType p_type);


        void render(sf::RenderWindow& window) const;
    };
} // Gameplay

#endif //MINESWEEPER_SFML_CELL_H