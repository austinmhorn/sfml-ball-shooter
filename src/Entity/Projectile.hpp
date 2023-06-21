//
//  Projectile.hpp
//  App
//
//  Created by Austin Horn on 10/21/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef Projectile_hpp
#define Projectile_hpp

#include <SFML/Graphics/CircleShape.hpp>
#pragma once

#include "../Entity/Base/Entity.hpp"
#pragma once

class NumberSquare;


#include <cmath>

struct Projectile : public Entity
{
public: // Members
    
    sf::CircleShape circle;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2u bounds;
    float speed;
    float mass;
    bool m_loaded;
    bool m_shot;
    sf::Time m_lifetime;
    
    static bool s_selfCollisionEnabled;
    Projectile* collider;
    
    NumberSquare* squareCollider;
    
// Constructor
    
    Projectile(float baseRadius);
    
    // Mutators
    
    void setVelocity(float angle)
    {
        velocity = (angle >= 0)
        ? sf::Vector2f{ std::cos(angle)*speed, std::sin(angle)*speed }
        : -sf::Vector2f{ std::cos(angle)*speed, std::sin(angle)*speed };
    }
    
    void setShot(bool shot)
    {
        m_shot = shot;
    }
    void setLoaded(bool loaded)
    {
        m_loaded = loaded;
    }
    void setFillColor(sf::Color color)
    {
        circle.setFillColor(color);
    }
    void setPosition(const sf::Vector2f& pos)
    {
        position = pos;
    }
    void setBounds(const sf::Vector2u& window_size)
    {
        bounds = window_size;
    }
    void setBounds(const sf::Vector2f& window_size_v2f)
    {
        bounds.x = static_cast<float>(window_size_v2f.x);
        bounds.y = static_cast<float>(window_size_v2f.y);
    }
    static void setSelfCollisionEnabled(bool is_enabled)
    {
        s_selfCollisionEnabled = is_enabled;
    }
    
    // Accessors
    
    sf::Vector2f getPosition() const
    {
        return position;
    }
    bool getShot() const
    {
        return m_shot;
    }
    bool getLoaded() const
    {
        return m_loaded;
    }
    float getRadius() const
    {
        return circle.getRadius();
    }
    const sf::FloatRect getGlobalBounds() const
    {
        return circle.getGlobalBounds();
    }
    
    // Functions
    
    void update(sf::Time& delta_time);
    
    bool collidedWithProjectile(Projectile* rhs);
        
    void resetCollision();
    
    void processProjectileAndProjectileCollision(Projectile* b1, Projectile* b2);
    
    bool intersects(const sf::FloatRect& rectangle) const;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
private:
    
    bool intersects(Projectile* p) const
    {
        float delta_x_squared = this->position.x - p->position.x;
        delta_x_squared *= delta_x_squared;
        
        float delta_y_squared = this->position.y - p->position.y;
        delta_y_squared *= delta_y_squared;
        
        float sum_radi_squared = this->getRadius() + p->getRadius();
        sum_radi_squared *= sum_radi_squared;
        
        return (delta_x_squared + delta_y_squared <= sum_radi_squared);
    }

};

#endif /* Projectile_hpp */
