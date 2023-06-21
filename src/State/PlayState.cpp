//
//  PlayState.cpp
//  App
//
//  Created by Austin Horn on 10/12/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#include "PlayState.hpp"
#include "MenuState.hpp"

#include "../Core/Assets.hpp"

PlayState::PlayState(sf::RenderWindow &window, Resources &resources)
: State{ window, resources }
, m_cannon{ window.getSize() }
{
    const sf::Vector2f window_size_v2f = sf::Vector2f{ window.getSize() };
    
    // Init background
    m_background.setSize(window_size_v2f);
    m_background.setFillColor(sf::Color::Black);
    
    // Init cannon
    m_cannon.setPosition({(window_size_v2f.x/2.0f) - m_cannon.getBaseRadius(), window_size_v2f.y});
    
    for (int i = 0; i < 100; i++)
        m_unfired_proj.push(Projectile(16.0f));
    
    m_cannon.setMaxShots(m_unfired_proj.size());
    
    m_number_square.setSize(50.0f);
    m_number_square.setPosition({300.0f, 600.0f});
    m_number_square.setFillColor(Resources::LightBlue);
    
}

void PlayState::handleProjectileNumberSquareInteraction(Projectile* p, NumberSquare* s)
{
    if ( p->intersects(s->getGlobalBounds()) )
    {
        if ( (p->getPosition().x - p->getRadius()) <= (s->getPosition().x + s->getSize().x) || (p->getPosition().x + p->getRadius()) <= s->getPosition().x )
        {
            std::cout << "VERTICAL" << std::endl;
            p->velocity.x *= -1.0f;
        }
        if ( (p->getPosition().y - p->getRadius()) <= (s->getPosition().y + s->getSize().y) || (p->getPosition().y + p->getRadius()) <= s->getPosition().y )
        {
            std::cout << "HORIZONTAL" << std::endl;
            p->velocity.y *= -1.0f;
        }
        
        p->position.x += p->velocity.x;
        p->position.y += p->velocity.y;
        
        p->setPosition(p->getPosition());
    }
}

void PlayState::processEvents() {
    for (auto event = sf::Event{}; m_window.pollEvent(event);) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
        if (event.type == sf::Event::MouseMoved) {
            m_mouse_position = m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
            m_mouse_button_released = (m_mouse_button_released) ? !m_mouse_button_released : m_mouse_button_released;            
        }
        if (event.type == sf::Event::MouseButtonReleased) {
            m_mouse_position = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
            m_mouse_button_released = true;
            
            // Prevent bad access
            if (m_unfired_proj.size())
            {
                // Assign shot angle to projectile
                m_unfired_proj.front().setVelocity(m_cannon.getShotAngle());
                
                // Move projectile resources from queue to vector
                m_fired_proj.push_back(std::move(m_unfired_proj.front()));
                
                // Remove projectile from queue
                m_unfired_proj.pop();
                
                // Set the number of times the cannon has fired projectile(s)
                m_cannon.setTimesFired(m_fired_proj.size());
            }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            m_mouse_button_released = false;
            
            switch (event.mouseButton.button) {
                case sf::Mouse::Left:
                    break;
                case sf::Mouse::Right:
                    break;
                default:
                    break;
            }
        }
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Key::Escape:
                    m_next = std::make_unique<MenuState>(m_window, m_resources);
                    break;
                    
                case sf::Keyboard::Key::Left:
                    break;
                    
                case sf::Keyboard::Key::Right:
                    break;
                    
                default:
                    break;
            }
        }
    }
}

void PlayState::update(sf::Time delta_time) {
    processEvents();
    
    // Call update function on Cannon object
    m_cannon.update(delta_time, m_mouse_position);
    
    for (auto& p : m_fired_proj)
        p.update(delta_time);
        
    //if (m_fired_proj.size())
        //for (auto& p : m_fired_proj)
            //handleProjectileNumberSquareInteraction(&p, &m_number_square);
    
    // Prevent unwanted click events in next frame
    m_mouse_button_released = false;
    
    
}

void PlayState::render() {
    m_window.clear();
    m_window.draw(m_background);
    m_window.draw(m_cannon);
    
    for (auto& p : m_fired_proj)
        m_window.draw(p);
    
    //m_window.draw(m_number_square);
    m_window.display();
}

