//
//  Button.hpp
//  LockedInside
//
//  Created by Austin Horn on 9/30/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include "../Entity/Base/Entity.hpp"
#pragma once
#include "../Entity/Shapes/StadiumShape.hpp"
#pragma once

#include <iostream>
#include <cmath>

////////////////////////////////////////////////////////////
/// \class Button
/// \ingroup
///
/// \brief
///
///
///
////////////////////////////////////////////////////////////
template <typename T>
class Button : public Entity, public Clickable {
private:
    
    T m_shape;
    sf::Text m_text;

public:
    
    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    /// \param shape Shape of button
    ////////////////////////////////////////////////////////////
    explicit Button(const T& = {}, const sf::Text& = {});
    
    ////////////////////////////////////////////////////////////
    /// \brief Mutators
    ///
    /// \function setSize             : Set size of sf::Shape
    ///     \param
    /// \function setCornersRadius    : Set the radius of the corners
    /// \function setAntialiasing     : Sets smoothness of curves (1 - 10)
    /// \function setFillColor        : Set inside fill color
    /// \function setPosition         : Set position with a Vector2f
    /// \function setPosition         : Set position with float values
    /// \function setText             : Set string of text
    /// \function setFont             : Set font of text
    /// \function setTextFillColor    : Set fill color of text
    /// \function setTextOutlineColor : Set outline color of text
    ////////////////////////////////////////////////////////////
    void setSize(const sf::Vector2f&);
    void setCornersRadius(const float&);
    void setAntialiasing(const unsigned int&);
    void setFillColor(const sf::Color&);
    void setOutlineColor(const sf::Color&);
    void setPosition(const sf::Vector2f&);
    void setPosition(const float&, const float&);
    void setString(const std::string&);
    void setFont(const sf::Font&);
    void setTextFillColor(const sf::Color&);
    void setTextOutlineColor(const sf::Color&);
    
    ////////////////////////////////////////////////////////////
    /// \brief Accessors
    ///
    /// \function getCornerRadius : Get radius of corners
    ///     \return
    /// \function getSize         : Get size of button
    ///     \return
    /// \function getGlobalBounds : Get transformed sf::FloatRect
    ///     \return 
    ////////////////////////////////////////////////////////////
    float getCornersRadius() const;
    const sf::Vector2f& getSize() const;
    sf::FloatRect getGlobalBounds() const;
    
    ////////////////////////////////////////////////////////////
    /// \brief Mutators
    ///
    /// \function contains   :
    ///     \param point
    ///     \return Determines if button contains point
    /// \function mouseOver  :
    /// \function mouseLeave :
    /// \function leftClick  :
    /// \function rightClick :
    /// \function update     :
    ///     \param delta_time
    /// \function update     :
    ////////////////////////////////////////////////////////////
    virtual const bool contains(const sf::Vector2f&) const override;
    virtual void mouseOver() override;
    virtual void mouseLeave() override;
    virtual void leftClick() override;
    virtual void rightClick() override;
    virtual void update(sf::Time delta_time) override;
    void update();
    
    void setRadius(float);
    float getRadius() const;
    
    void update(const sf::Vector2f&, sf::Mouse::Button, bool);
    
    // Render functions
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};







#endif /* Button_hpp */
