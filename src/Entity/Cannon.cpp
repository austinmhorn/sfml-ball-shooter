//
//  Cannon.cpp
//  App
//
//  Created by Austin Horn on 10/12/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#include "Cannon.hpp"

#include <iostream>
#include <cmath>

#include "../Core/Assets.hpp"

sf::CircleShape Cannon::m_base = sf::CircleShape(16.0f, 30);

Cannon::Cannon(const sf::Vector2u& bounds) : m_angle(0.0f)
{
    m_base.setFillColor(sf::Color(37,37,37,255));
    m_base.setOrigin(m_base.getRadius(), m_base.getRadius());

    m_shot_data = sf::Text(std::to_string(0), Resources::Zorque, 14);
    m_shot_data.setPosition(10.0f, bounds.y - m_shot_data.getGlobalBounds().height - 12.5f);
}

void Cannon::setPosition(const sf::Vector2f& position)
{
    m_base.setPosition(position);
    
    m_aimer[0] = sf::Vertex{ sf::Vector2f{position.x, position.y - 10.0f}, sf::Color::Blue };
    m_aimer[1] = sf::Vertex{m_aimer[0].position, sf::Color::Red};
}

void Cannon::setPosition(float x, float y)
{
    m_base.setPosition({x, y});
    
    m_aimer[0] = sf::Vertex{ sf::Vector2f{x, y - 10.0f}, sf::Color::Blue };
    m_aimer[1] = sf::Vertex{m_aimer[0].position, sf::Color::Red};
}

void Cannon::setSize(float radius)
{
    m_base.setRadius(radius);
}

void Cannon::setTimesFired(unsigned int timesFired)
{
    m_times_fired = timesFired;
}

void Cannon::setMaxShots(unsigned int maxShots)
{
    m_max_shots = maxShots;
}

const sf::Vector2f& Cannon::getPosition() const
{
    return m_base.getPosition();
}

const float Cannon::getBaseRadius() const
{
    return m_base.getRadius();
}

unsigned int Cannon::getTimesFired() const
{
    return m_times_fired;
}

unsigned int Cannon::getMaxShots() const
{
    return m_max_shots;
}

float Cannon::getShotAngle() const
{
    return m_angle;
}

void Cannon::aim(const sf::Vector2f& point) {
    
    // Find midpoint and update destination point of aim line
    m_aimer[1].position = sf::Vector2f{(m_aimer[0].position.x+point.x)/2.0f, (m_aimer[0].position.y+point.y)/2.0f};
    
    // Setup system origin relative to cannon base
    sf::Vector2f origin = {m_base.getPosition().x, m_base.getPosition().y - 10.0f};
        
    // Determine slope rise (delta y)
    float rise = origin.y - point.y;
    
    // Determine slope run (delta x)
    float run = -1.0f * (origin.x - point.x);
    
    // Calculate inverse tangent for shot angle
    m_angle = std::atan(rise/run);
    
    // Angular displacment
}

void Cannon::updateCannonText()
{
    m_shot_data.setString("Balls Remaining:\t" + std::to_string(getMaxShots()-getTimesFired()));
}

void Cannon::update(sf::Time delta_time, const sf::Vector2f& point)
{
    aim(point);
    updateCannonText();
}

void Cannon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_base);
    target.draw(m_shot_data);
    target.draw(m_aimer);
}



/*
 // Find normal unit vector
 
 // Calculate dot product of vectors
 float dot = (b1->velocity.x * b2->velocity.x) + (b1->velocity.y * b2->velocity.y);
 sf::Vector2f result = b1->velocity - b2->velocity;
 
 std::cout << dot << std::endl;
 std::cout << result.x << ", " << result.y << std::endl;
 // Obtain angle of contact
 */

/*
float dot = (b1->velocity.x * b2->velocity.x) + (b1->velocity.y * b2->velocity.y);
sf::Vector2f normal = (b1->velocity - b2->velocity) / dot;

std::cout << normal.x << ", " << normal.y << std::endl;

//sf::Vector2f v1 = b1->velocity - (normal * dot) - normal;
//sf::Vector2f v2 = b2->velocity - (normal * dot) - normal;

//b1->velocity = v1;
//b2->velocity = v2;
*/
