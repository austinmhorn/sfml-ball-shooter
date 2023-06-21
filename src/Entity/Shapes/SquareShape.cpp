//
//  SquareShape.cpp
//  App
//
//  Created by Austin Horn on 10/12/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#include "SquareShape.hpp"

sf::SquareShape::SquareShape(float sideLength) {
    m_size = sf::Vector2f(sideLength, sideLength);
    Shape::update();
}

void sf::SquareShape::setSize(const float& sideLength) {
    m_size = sf::Vector2f(sideLength, sideLength);
    Shape::update();
}

void sf::SquareShape::setTranslucent(const bool &translucent) {
    (translucent) ? setFillColor({getFillColor().r, getFillColor().g, getFillColor().b, 150})
                  : setFillColor({getFillColor().r, getFillColor().g, getFillColor().b, 255});
}

const sf::Vector2f& sf::SquareShape::getSize() const {
    return m_size;
}

std::size_t sf::SquareShape::getPointCount() const {
    return 4;
}

sf::Vector2f sf::SquareShape::getPoint(std::size_t index) const {
    switch (index)
        {
            default:
            case 0: return Vector2f(0, 0);
            case 1: return Vector2f(m_size.x, 0);
            case 2: return Vector2f(m_size.x, m_size.y);
            case 3: return Vector2f(0, m_size.y);
        }
}
