//
//  Button.cpp
//  LockedInside
//
//  Created by Austin Horn on 9/30/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#include "Button.hpp"

/// MARK: Button<sf::StadiumShape> template instantiation
template <> void Button<sf::StadiumShape>::update() {
    m_shape.updateGeometry();
        
    m_text.setPosition(sf::Vector2f{m_shape.getGlobalBounds().left+std::round(m_shape.getGlobalBounds().width/2.f)-std::round(m_text.getGlobalBounds().width/2.f),
                                    m_shape.getGlobalBounds().top+std::round(m_shape.getGlobalBounds().height/2.6f)-std::round(m_text.getGlobalBounds().height/2.f)});
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> Button<sf::StadiumShape>::Button(const sf::StadiumShape& stadium, const sf::Text& text)
: m_shape(stadium)
, m_text(text) {
    this->update();
    m_text.setFillColor(sf::Color::Black);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Mutators
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> void Button<sf::StadiumShape>::setSize(const sf::Vector2f& size)           { m_shape.setSize(size);                 this->update(); }
template <> void Button<sf::StadiumShape>::setCornersRadius(const float& radius)       { m_shape.setCornersRadius(radius);      this->update(); }
template <> void Button<sf::StadiumShape>::setAntialiasing(const unsigned int& aa)     { m_shape.setAntialiasing(aa);           this->update(); }
template <> void Button<sf::StadiumShape>::setFillColor(const sf::Color& color)        { m_shape.setFillColor(color);                           }
template <> void Button<sf::StadiumShape>::setOutlineColor(const sf::Color& color)     { m_shape.setOutlineColor(color);                        }
template <> void Button<sf::StadiumShape>::setPosition(const sf::Vector2f& position)   { m_shape.setPosition(position);         this->update(); }
template <> void Button<sf::StadiumShape>::setPosition(const float& x, const float& y) { m_shape.setPosition(x, y);             this->update(); }
template <> void Button<sf::StadiumShape>::setString(const std::string& string)        { m_text.setString(string);              this->update(); }
template <> void Button<sf::StadiumShape>::setFont(const sf::Font& font)               { m_text.setFont(font);                  this->update(); }
template <> void Button<sf::StadiumShape>::setTextFillColor(const sf::Color& color)    { m_text.setFillColor(color);                            }
template <> void Button<sf::StadiumShape>::setTextOutlineColor(const sf::Color& color) { m_text.setOutlineColor(color);                         }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Accessors
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> const sf::Vector2f& Button<sf::StadiumShape>::getSize()   const { return m_shape.getSize();                                       }
template <> float Button<sf::StadiumShape>::getCornersRadius()        const { return m_shape.getCornersRadius();                              }
template <> sf::FloatRect Button<sf::StadiumShape>::getGlobalBounds() const { return getTransform().transformRect(m_shape.getGlobalBounds()); }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Events
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> const bool Button<sf::StadiumShape>::contains(const sf::Vector2f& point) const { return getGlobalBounds().contains(point); }
template <> void Button<sf::StadiumShape>::mouseOver() {
    m_shape.setOutlineThickness(3.f);
    m_shape.setTranslucent(true);
    m_text.setFillColor({m_text.getFillColor().r, m_text.getFillColor().g, m_text.getFillColor().b, 150});
}
template <> void Button<sf::StadiumShape>::mouseLeave() {
    m_shape.setOutlineThickness(0.f);
    m_shape.setTranslucent(false);
    m_text.setFillColor({m_text.getFillColor().r, m_text.getFillColor().g, m_text.getFillColor().b, 255});
}

template <> void Button<sf::StadiumShape>::leftClick() {
    std::cout << static_cast<std::string>(m_text.getString()) << " button was left clicked" << std::endl;
}
template <> void Button<sf::StadiumShape>::rightClick() {
    std::cout << static_cast<std::string>(m_text.getString()) << " button was right clicked" << std::endl;
}
template <> void Button<sf::StadiumShape>::update(sf::Time delta_time) {  }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Render Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> void Button<sf::StadiumShape>::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_shape, states);
    target.draw(m_text);
    sf::String string;
}

template <> void Button<sf::StadiumShape>::update(const sf::Vector2f& point, sf::Mouse::Button mouse_button_pressed, bool clicked) {
    (contains(point)) ? mouseOver() : mouseLeave();
    
    if (clicked) {
        switch(mouse_button_pressed) {
            case sf::Mouse::Left: break;
            case sf::Mouse::Right: break;
            default: break;
        }
    }
}








///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// MARK: sf::RectangleShape template instantiation
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> void Button<sf::RectangleShape>::update() {
    m_text.setPosition(sf::Vector2f{m_shape.getGlobalBounds().left+std::round(m_shape.getGlobalBounds().width/2.f)-std::round(m_text.getGlobalBounds().width/2.f),
                                    m_shape.getGlobalBounds().top+std::round(m_shape.getGlobalBounds().height/2.6f)-std::round(m_text.getGlobalBounds().height/2.f)});
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> Button<sf::RectangleShape>::Button(const sf::RectangleShape& rectangle, const sf::Text& text)
: m_shape(rectangle)
, m_text(text) {
    this->update();
    m_text.setFillColor(sf::Color::Black);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Mutators
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> void Button<sf::RectangleShape>::setSize(const sf::Vector2f& size)           { m_shape.setSize(size);                                 }
template <> void Button<sf::RectangleShape>::setFillColor(const sf::Color& color)        { m_shape.setFillColor(color);                           }
template <> void Button<sf::RectangleShape>::setOutlineColor(const sf::Color& color)     { m_shape.setOutlineColor(color);                        }
template <> void Button<sf::RectangleShape>::setPosition(const sf::Vector2f& position)   { m_shape.setPosition(position);         this->update(); }
template <> void Button<sf::RectangleShape>::setPosition(const float& x, const float& y) { m_shape.setPosition(x, y);             this->update(); }
template <> void Button<sf::RectangleShape>::setString(const std::string& string)        { m_text.setString(string);              this->update(); }
template <> void Button<sf::RectangleShape>::setFont(const sf::Font& font)               { m_text.setFont(font);                  this->update(); }
template <> void Button<sf::RectangleShape>::setTextFillColor(const sf::Color& color)    { m_text.setFillColor(color);                            }
template <> void Button<sf::RectangleShape>::setTextOutlineColor(const sf::Color& color) { m_text.setOutlineColor(color);                         }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Accessors
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> const sf::Vector2f& Button<sf::RectangleShape>::getSize()   const { return m_shape.getSize();                                       }
template <> sf::FloatRect Button<sf::RectangleShape>::getGlobalBounds() const { return getTransform().transformRect(m_shape.getGlobalBounds()); }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Events
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> const bool Button<sf::RectangleShape>::contains(const sf::Vector2f& point) const { return getGlobalBounds().contains(point); }
template <> void Button<sf::RectangleShape>::mouseOver() {
    m_shape.setOutlineThickness(3.f);
    m_shape.setFillColor({m_shape.getFillColor().r, m_shape.getFillColor().g, m_shape.getFillColor().b, 150});
    m_text.setFillColor({m_text.getFillColor().r, m_text.getFillColor().g, m_text.getFillColor().b, 150});
}
template <> void Button<sf::RectangleShape>::mouseLeave() {
    m_shape.setOutlineThickness(0.f);
    m_shape.setFillColor({m_shape.getFillColor().r, m_shape.getFillColor().g, m_shape.getFillColor().b, 255});
    m_text.setFillColor({m_text.getFillColor().r, m_text.getFillColor().g, m_text.getFillColor().b, 255});
}
template <> void Button<sf::RectangleShape>::leftClick() {
    std::cout << static_cast<std::string>(m_text.getString()) << " button was left clicked" << std::endl;
}
template <> void Button<sf::RectangleShape>::rightClick() {
    std::cout << static_cast<std::string>(m_text.getString()) << " button was right clicked" << std::endl;
}
template <> void Button<sf::RectangleShape>::update(sf::Time delta_time) {  }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Render Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> void Button<sf::RectangleShape>::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_shape, states);
    target.draw(m_text);
}







///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// MARK: sf::CircleShape template instantiation
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> void Button<sf::CircleShape>::update() {
    m_text.setPosition(sf::Vector2f{m_shape.getGlobalBounds().left+std::round(m_shape.getGlobalBounds().width/2.f)-std::round(m_text.getGlobalBounds().width/2.f),
                                    m_shape.getGlobalBounds().top+std::round(m_shape.getGlobalBounds().height/2.6f)-std::round(m_text.getGlobalBounds().height/2.f)});
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> Button<sf::CircleShape>::Button(const sf::CircleShape& circle, const sf::Text& text)
: m_shape(circle)
, m_text(text) {
    this->update();
    m_text.setFillColor(sf::Color::Black);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Mutators
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> void Button<sf::CircleShape>::setRadius(float radius)                     { m_shape.setRadius(radius);                             }
template <> void Button<sf::CircleShape>::setFillColor(const sf::Color& color)        { m_shape.setFillColor(color);                           }
template <> void Button<sf::CircleShape>::setOutlineColor(const sf::Color& color)     { m_shape.setOutlineColor(color);                        }
template <> void Button<sf::CircleShape>::setPosition(const sf::Vector2f& position)   { m_shape.setPosition(position);         this->update(); }
template <> void Button<sf::CircleShape>::setPosition(const float& x, const float& y) { m_shape.setPosition(x, y);             this->update(); }
template <> void Button<sf::CircleShape>::setString(const std::string& string)        { m_text.setString(string);              this->update(); }
template <> void Button<sf::CircleShape>::setFont(const sf::Font& font)               { m_text.setFont(font);                  this->update(); }
template <> void Button<sf::CircleShape>::setTextFillColor(const sf::Color& color)    { m_text.setFillColor(color);                            }
template <> void Button<sf::CircleShape>::setTextOutlineColor(const sf::Color& color) { m_text.setOutlineColor(color);                         }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Accessors
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> float Button<sf::CircleShape>::getRadius() const { return m_shape.getRadius();                                       }
template <> sf::FloatRect Button<sf::CircleShape>::getGlobalBounds() const { return getTransform().transformRect(m_shape.getGlobalBounds()); }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Events
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> const bool Button<sf::CircleShape>::contains(const sf::Vector2f& point) const { return getGlobalBounds().contains(point); }
template <> void Button<sf::CircleShape>::mouseOver() {
    m_shape.setOutlineThickness(3.f);
    m_shape.setFillColor({m_shape.getFillColor().r, m_shape.getFillColor().g, m_shape.getFillColor().b, 150});
    m_text.setFillColor({m_text.getFillColor().r, m_text.getFillColor().g, m_text.getFillColor().b, 150});
}
template <> void Button<sf::CircleShape>::mouseLeave() {
    m_shape.setOutlineThickness(0.f);
    m_shape.setFillColor({m_shape.getFillColor().r, m_shape.getFillColor().g, m_shape.getFillColor().b, 255});
    m_text.setFillColor({m_text.getFillColor().r, m_text.getFillColor().g, m_text.getFillColor().b, 255});
}
template <> void Button<sf::CircleShape>::leftClick() {
    std::cout << static_cast<std::string>(m_text.getString()) << " button was left clicked" << std::endl;
}
template <> void Button<sf::CircleShape>::rightClick() {
    std::cout << static_cast<std::string>(m_text.getString()) << " button was right clicked" << std::endl;
}
template <> void Button<sf::CircleShape>::update(sf::Time delta_time) {  }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Render Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <> void Button<sf::CircleShape>::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_shape, states);
    target.draw(m_text);
}

