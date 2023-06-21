//
//  MenuState.hpp
//  LockedInside
//
//  Created by Austin Horn on 9/30/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef MenuState_hpp
#define MenuState_hpp

#include "../UI/Button.hpp"
#pragma once
#include "Base/State.hpp"
#pragma once
#include "../Entity/Base/ParticleEmitter.hpp"
#pragma once

struct Resources;

class MenuState final : public State {
public: // Constructors
    
    explicit MenuState(sf::RenderWindow& window, Resources& resources);
    
private: // Functions
    
    void processEvents() override;
    void update(sf::Time delta_time) override;
    void render() override;

    template <typename T>
    void handleButtonMouseInteraction(Button<T>&) const;

private: // Members
    
    sf::RectangleShape m_background;
    
    sf::Cursor m_cursor;
    sf::Vector2f m_mouse_position;
    bool m_mouse_button_released;
    
    Button<sf::StadiumShape> m_start;
    Button<sf::StadiumShape> m_options;
    Button<sf::StadiumShape> m_exit;
    
    sf::CircleShape m_ball;
    sf::Vector2f m_ball_position;
    sf::Vector2f m_ball_velocity;
    
    // create the particle system
    ParticleSystem particles = ParticleSystem(1000);
};


#endif /* MenuState_hpp */
