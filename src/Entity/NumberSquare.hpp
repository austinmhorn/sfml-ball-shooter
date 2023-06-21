//
//  NumberSquare.hpp
//  App
//
//  Created by Austin Horn on 10/20/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef NumberSquare_hpp
#define NumberSquare_hpp

#include "Shapes/SquareShape.hpp"
#pragma once

#include "Base/Entity.hpp"
#pragma once

////////////////////////////////////////////////////////////
/// \class NumberSquare
///
/// \brief 
////////////////////////////////////////////////////////////
class NumberSquare : public Entity {
public:
    
    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    /// \param none
    ////////////////////////////////////////////////////////////
    NumberSquare();
    
    ////////////////////////////////////////////////////////////
    /// \brief Set the size of the square
    ///
    /// \param sideLength Side length of square
    ///
    /// \see getSize
    ////////////////////////////////////////////////////////////
    void setSize(float sideLength);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    void setFillColor(sf::Color color);
    
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;
    
    bool intersects(const sf::FloatRect& rectangle) const;
        
    void operator --();
    void operator ++();
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
private:
    
    std::vector<sf::Vertex> m_vertices;
    sf::SquareShape m_square;
    unsigned int m_health;
    sf::Text m_text;
    
};

#endif /* NumberSquare_hpp */
