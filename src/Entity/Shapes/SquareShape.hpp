//
//  SquareShape.hpp
//  App
//
//  Created by Austin Horn on 10/12/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef SquareShape_hpp
#define SquareShape_hpp

#include <SFML/Graphics/Shape.hpp>
#pragma once

namespace sf {

class SquareShape : public sf::Shape {
public:
    
    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    /// \param sideLength
    ////////////////////////////////////////////////////////////
    SquareShape(float sideLength = 0.0f);
    
    ////////////////////////////////////////////////////////////
    /// \brief Calls private Shape function Shape::update()
    ///
    /// \see sf::Shape::update()
    ////////////////////////////////////////////////////////////
    void updateGeometry();
    
    ////////////////////////////////////////////////////////////
    /// \brief Set the size of the square
    ///
    /// \param sideLength New size of the square
    ///
    /// \see getSize
    ////////////////////////////////////////////////////////////
    void setSize(const float& sideLength);
    
    ////////////////////////////////////////////////////////////
    /// \brief Adjusts square's alpha value to appear translucent
    ///
    /// \param translucent Indicates if shape will be translucent
    ////////////////////////////////////////////////////////////
    void setTranslucent(const bool& translucent);
    
    ////////////////////////////////////////////////////////////
    /// \brief Get the size of the square
    ///
    /// \return Size of the square
    ///
    /// \see setSize
    ////////////////////////////////////////////////////////////
    const sf::Vector2f& getSize() const;
    
    ////////////////////////////////////////////////////////////
    /// \brief Get the number of points defining the square
    ///
    /// \return Number of points of the square
    ////////////////////////////////////////////////////////////
    virtual std::size_t getPointCount() const override;
    
    ////////////////////////////////////////////////////////////
    /// \brief Get a point of the square
    ///
    /// The result is undefined if \a index is out of the valid range.
    ///
    /// \param index Index of the point to get, in range [0 - 3]
    ///
    /// \return Index-th point of the shape
    ////////////////////////////////////////////////////////////
    virtual sf::Vector2f getPoint(std::size_t index) const override;
    
private:
    
    sf::Vector2f m_size;
};

}

#endif /* SquareShape_hpp */
