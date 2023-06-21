//
//  Entity.hpp
//  LockedInside
//
//  Created by Austin Horn on 9/30/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <SFML/Graphics.hpp>
#pragma once


///////////////////////////////////////////////////////////////////////////
/// \class Entity
/// \ingroup Entity
///
/// \brief Base class representing drawable entities (sf::Shape, sf::Sprite, etc.)
///
///
///////////////////////////////////////////////////////////////////////////
class Entity : public sf::Transformable, public sf::Drawable {
protected:
    
    sf::Transformable m_transformable;
    
    Entity() = default;
    ~Entity() override = default;
    
    Entity(const Entity&) = default;
    Entity& operator=(const Entity&) = default;
    
    Entity(Entity&&) noexcept = default;
    Entity& operator=(Entity&&) noexcept = default;
    
private:
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
    
public:
    
    sf::FloatRect getGlobalBounds() const { return m_transformable.getTransform().transformRect(getGlobalBounds()); }

};








///////////////////////////////////////////////////////////////////////////
/// \class Clickable
/// \ingroup Entity
///
///
///
///
///////////////////////////////////////////////////////////////////////////
class Clickable {
protected:
    
    bool m_clicked;
    
    Clickable() : m_clicked(false) { }
    
    ~Clickable() = default;
    
    Clickable(const Clickable&) = default;
    Clickable& operator=(const Clickable&) = default;
    
    Clickable(Clickable&&) noexcept = default;
    Clickable& operator=(Clickable&&) noexcept = default;
    
public:
    // Mutators
    void setClicked(const bool& clicked) { m_clicked = clicked; }
    
    // Accessors
    bool getClicked() const { return m_clicked; }
    
    virtual const bool contains(const sf::Vector2f&) const = 0;
    virtual void mouseOver() = 0;
    virtual void mouseLeave() = 0;
    virtual void leftClick() = 0;
    virtual void rightClick() = 0;
    virtual void update(sf::Time delta_time) = 0;
};

/*
///////////////////////////////////////////////////////////////////////////
/// \class Clickable
/// \ingroup Entity
///
///
///
///
///////////////////////////////////////////////////////////////////////////
class Controllable {
protected:
    
    sf::FloatRect m_rect;
    
    Controllable(sf::FloatRect rect) : m_rect(rect) { }
    
    ~Controllable() = default;
    
    Controllable(const Controllable&) = default;
    Controllable& operator=(const Controllable&) = default;
    
    Controllable(Controllable&&) noexcept = default;
    Controllable& operator=(Controllable&&) noexcept = default;
    
public:
    
    
    inline bool contains(const sf::Vector2f& point) const { return m_rect.contains(point); }
    inline bool contains(float x, float y) const { return m_rect.contains(x, y); }
    
    inline bool intersects(const sf::Rect<float>& rect) const { return m_rect.intersects(rect); }
    
    
    
    virtual void update(sf::Time delta_time) = 0;
};
*/


// MARK: class Kinetic

#endif /* Entity_hpp */
