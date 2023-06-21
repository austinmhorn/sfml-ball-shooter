//
//  MenuState.cpp
//  LockedInside
//
//  Created by Austin Horn on 9/30/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#include "MenuState.hpp"
#include "OptionsState.hpp"
#include "PlayState.hpp"
#include "../Core/Assets.hpp"

#include <iostream>

struct Resources;

MenuState::MenuState(sf::RenderWindow& window, Resources& resources) :
State{ window, resources },
m_start{ sf::StadiumShape{}, sf::Text{"Start", Resources::Zorque, 30} },
m_options{sf::StadiumShape{}, sf::Text{"Options", Resources::Zorque, 30} },
m_exit{ sf::StadiumShape{}, sf::Text{"Exit", Resources::Zorque, 30} },
m_mouse_button_released{ false },
m_ball{5.f, 30}
{
    const sf::Vector2f window_size = sf::Vector2f{ window.getSize() };
    
    m_background.setSize(window_size);
    m_background.setFillColor(Resources::DarkPurple);
    
    m_start.setPosition(sf::Vector2f{ window_size.x / 2.f, window_size.y / 2.f } -
                        sf::Vector2f{ std::round(m_start.getGlobalBounds().width / 2.f), std::round(m_start.getGlobalBounds().height * 2.5f) });
    
    m_options.setPosition(sf::Vector2f{ window_size.x / 2.f, window_size.y / 2.f } -
                          sf::Vector2f{ std::round(m_options.getGlobalBounds().width / 2.f), 0.f});
    
    m_exit.setPosition(sf::Vector2f{ window_size.x / 2.f, window_size.y / 2.f } +
                       sf::Vector2f{ -std::round(m_exit.getGlobalBounds().width / 2.f), std::round(m_exit.getGlobalBounds().height * 2.5f) });
    
    if (m_cursor.loadFromSystem(sf::Cursor::Hand))
        m_window.setMouseCursor(m_cursor);
    
    m_ball_position = {static_cast<float>(std::rand() % m_window.getSize().x), static_cast<float>(std::rand() % m_window.getSize().y)};
    m_ball_velocity = {3.f, 3.f};
}

void MenuState::processEvents()
{
    for (auto event = sf::Event{}; m_window.pollEvent(event);) {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
        if (event.type == sf::Event::MouseMoved)
        {
            m_mouse_position = m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
            m_mouse_button_released = (m_mouse_button_released) ? !m_mouse_button_released : m_mouse_button_released;
        }
        if (event.type == sf::Event::MouseButtonReleased)
        {
            m_mouse_position = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
            m_mouse_button_released = true;
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            m_mouse_button_released = false;
            
            switch (event.mouseButton.button)
            {
                case sf::Mouse::Left:
                    break;
                case sf::Mouse::Right:
                    break;
                default:
                    break;
            }
        }
        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code) {
                case sf::Keyboard::Key::Escape:
                    m_window.close();
                    break;
                    
                default:
                    break;
            }
        }
    }
}

template <typename T>
void MenuState::handleButtonMouseInteraction(Button<T>& button) const {
    (button.contains(m_mouse_position)) ? button.mouseOver() : button.mouseLeave();
}

void MenuState::update(const sf::Time delta_time) {
    processEvents();

    handleButtonMouseInteraction(m_start);
    handleButtonMouseInteraction(m_options);
    handleButtonMouseInteraction(m_exit);
        
    if (m_start.contains(m_mouse_position) && m_mouse_button_released) {
        m_next = std::make_unique<PlayState>(m_window, m_resources);
    }
    if (m_options.contains(m_mouse_position) && m_mouse_button_released) {
        m_next = std::make_unique<OptionsState>(m_window, m_resources);
    }
    if (m_exit.contains(m_mouse_position) && m_mouse_button_released) {
        m_window.close();
    }
    
    // Ball collided with vertical wall
    if (m_ball_position.x < 0 || m_ball_position.x > m_window.getSize().x - m_ball.getRadius()*2) {
        m_ball_velocity.x *= -1;
        m_ball.setFillColor({static_cast<sf::Uint8>(std::rand() % 256), static_cast<sf::Uint8>(std::rand() % 256), static_cast<sf::Uint8>(std::rand() % 256)});
    }
    // Ball collided with horizontal wall
    if (m_ball_position.y < 0 || m_ball_position.y > m_window.getSize().y - m_ball.getRadius()*2) {
        m_ball_velocity.y *= -1;
        m_ball.setFillColor({static_cast<sf::Uint8>(std::rand() % 256), static_cast<sf::Uint8>(std::rand() % 256), static_cast<sf::Uint8>(std::rand() % 256)});
    }
     
    m_ball_position.x += m_ball_velocity.x;
    m_ball_position.y += m_ball_velocity.y;
    m_ball.setPosition(m_ball_position);
    
    // Prevent unwanted click events in next frame
    m_mouse_button_released = false;
}

void MenuState::render() {
    m_window.clear();
    m_window.draw(m_background);
    m_window.draw(m_ball);
    m_window.draw(m_start);
    m_window.draw(m_options);
    m_window.draw(m_exit);
    m_window.display();
}
