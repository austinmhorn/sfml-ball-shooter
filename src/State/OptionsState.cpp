//
//  OptionsState.cpp
//  App
//
//  Created by Austin Horn on 10/9/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#include "OptionsState.hpp"
#include "MenuState.hpp"
#include "../Core/Assets.hpp"

OptionsState::OptionsState(sf::RenderWindow &window, Resources &resources)
: State{ window, resources }
, m_mouse_button_released(false)
, m_back{ sf::CircleShape{26.f, 30}, sf::Text{"Back", Resources::Zorque, 17}}
, m_sound_toggle{ m_resources.settings.getSoundIsOn() }
, m_music_toggle{ m_resources.settings.getMusicIsOn() }
, m_balls_multicolor_toggle{ m_resources.settings.getBallsMulticolorIsOn() }
{
    const sf::Vector2f window_size = sf::Vector2f{ window.getSize() };
    
    m_background.setSize(window_size);
    m_background.setFillColor(Resources::DarkBlue);
    
    m_back.setPosition({10.f, 10.f});
    
    m_sound_toggle.setPosition(10.0f, 100.0f);
    m_sound_toggle.setDescription("- Sound");
    
    m_music_toggle.setPosition(10.0f, 150.0f);
    m_music_toggle.setDescription("- Music");
    
    m_balls_multicolor_toggle.setPosition(10.0f, 200.0f);
    m_balls_multicolor_toggle.setDescription("- Multicolor Balls");
}

void OptionsState::processEvents() { 
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
                    
                default:
                    break;
            }
        }
    }
}

template <typename T>
void OptionsState::handleButtonMouseInteraction(Button<T>& button) const {
    (button.contains(m_mouse_position)) ? button.mouseOver() : button.mouseLeave();
}

void OptionsState::handleToggleMouseInteraction(Toggle& toggle) const {
    (toggle.contains(m_mouse_position)) ? toggle.mouseOver() : toggle.mouseLeave();
}

void OptionsState::update(sf::Time delta_time) { 
    processEvents();
    
    handleButtonMouseInteraction(m_back);
    handleToggleMouseInteraction(m_sound_toggle);
    handleToggleMouseInteraction(m_music_toggle);
    handleToggleMouseInteraction(m_balls_multicolor_toggle);
    
    if (m_back.contains(m_mouse_position) && m_mouse_button_released) {
        m_next = std::make_unique<MenuState>(m_window, m_resources);
    }
    if (m_sound_toggle.contains(m_mouse_position) && m_mouse_button_released) {
        m_sound_toggle.update(delta_time);
        m_resources.settings.setSoundIsOn(m_sound_toggle.getActive());
    }
    if (m_music_toggle.contains(m_mouse_position) && m_mouse_button_released) {
        m_music_toggle.update(delta_time);
        m_resources.settings.setMusicIsOn(m_music_toggle.getActive());
    }
    if (m_balls_multicolor_toggle.contains(m_mouse_position) && m_mouse_button_released) {
        m_balls_multicolor_toggle.update(delta_time);
        m_resources.settings.setBallsMulticolorIsOn(m_balls_multicolor_toggle.getActive());
    }
    
    // Prevent unwanted click events in next frame
    m_mouse_button_released = false;
}

void OptionsState::render() {
    m_window.clear();
    m_window.draw(m_background);
    m_window.draw(m_back);
    m_window.draw(m_sound_toggle);
    m_window.draw(m_music_toggle);
    m_window.draw(m_balls_multicolor_toggle);
    m_window.display();
}
