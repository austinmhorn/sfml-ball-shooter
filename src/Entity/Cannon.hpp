//
//  Cannon.hpp
//  App
//
//  Created by Austin Horn on 10/12/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef Cannon_hpp
#define Cannon_hpp

#include <vector>

#include "Base/Entity.hpp"
#pragma once

#include "Projectile.hpp"
#pragma once




class Cannon : public Entity {
public:
    
    Cannon(const sf::Vector2u& bounds);
    
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    void setSize(float radius);
    void setTimesFired(unsigned int timesFired);
    void setMaxShots(unsigned int maxShots);
    
    const sf::Vector2f& getPosition() const;
    const float getBaseRadius() const;
    unsigned int getTimesFired() const;
    unsigned int getMaxShots() const;
    float getShotAngle() const;
    
    void aim(const sf::Vector2f& point);
    
    void update(sf::Time delta_time, const sf::Vector2f& point);
    void updateCannonText();
    
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
private: // Members
    
    static sf::CircleShape m_base;
    sf::VertexArray m_aimer = sf::VertexArray(sf::PrimitiveType::Lines, 2);
    float m_angle;
    
    unsigned int m_times_fired = 0;
    unsigned int m_max_shots = 0;
    
    sf::Text m_shot_data;

};

#endif /* Cannon_hpp */
