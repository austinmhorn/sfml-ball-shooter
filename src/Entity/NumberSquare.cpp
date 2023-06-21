//
//  NumberSquare.cpp
//  App
//
//  Created by Austin Horn on 10/20/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#include "NumberSquare.hpp"
#include "../Core/Assets.hpp"

NumberSquare::NumberSquare()
{
    m_vertices.push_back( sf::Vertex(sf::Vector2f{  0.0f,  0.0f }, sf::Color::White));
    m_vertices.push_back( sf::Vertex(sf::Vector2f{ 50.0f,  0.0f }, sf::Color::White));
    m_vertices.push_back( sf::Vertex(sf::Vector2f{ 50.0f, 50.0f }, sf::Color::White));
    m_vertices.push_back( sf::Vertex(sf::Vector2f{  0.0f, 50.0f }, sf::Color::White));
    
    m_square.setFillColor(sf::Color::White);
    
    m_health = 100;
    
    m_text = sf::Text(std::to_string(m_health), Resources::Zorque, 12);
    m_text.setFillColor(sf::Color::Black);
    m_text.setOrigin(m_text.getTransform().transformRect(m_text.getGlobalBounds()).width / 2.0f,
                     m_text.getTransform().transformRect(m_text.getGlobalBounds()).height / 2.0f);
}

void NumberSquare::setSize(float sideLength)
{
    m_square.setSize(sideLength);
    
    m_text.setPosition(m_square.getPosition().x + (m_square.getSize().x / 2.0f),
                       m_square.getPosition().y + (m_square.getSize().y / 2.0f));
}

void NumberSquare::setPosition(const sf::Vector2f& position)
{
    m_square.setPosition(position);
    
    m_text.setPosition(position.x + (m_square.getSize().x / 2.0f),
                       position.y + (m_square.getSize().y / 2.0f));
}
void NumberSquare::setPosition(float x, float y)
{
    m_square.setPosition(x, y);
    
    m_text.setPosition(x + (m_square.getSize().x / 2.0f),
                       y + (m_square.getSize().y / 2.0f));
}

void NumberSquare::setFillColor(sf::Color color)
{
    m_square.setFillColor(color);
}

///
sf::FloatRect NumberSquare::getGlobalBounds() const
{
    return m_square.getGlobalBounds();
}
sf::Vector2f NumberSquare::getSize() const
{
    return m_square.getSize();
}
sf::Vector2f NumberSquare::getPosition() const
{
    return m_square.getPosition();
}

bool NumberSquare::intersects(const sf::FloatRect& rectangle) const
{
    return m_square.getGlobalBounds().intersects(rectangle);
}


void NumberSquare::operator--()
{
    m_health -= 1;
    m_text.setString(std::to_string(m_health));
}

void NumberSquare::operator++()
{
    m_health += 1;
    m_text.setString(std::to_string(m_health));
}

void NumberSquare::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = nullptr;
    target.draw(m_square);
    target.draw(m_text);
}
