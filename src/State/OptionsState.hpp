//
//  OptionsState.hpp
//  App
//
//  Created by Austin Horn on 10/9/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef OptionsState_hpp
#define OptionsState_hpp

#include "../UI/Toggle.hpp"
#pragma once
#include "../UI/Button.hpp"
#pragma once
#include "Base/State.hpp"
#pragma once
#include "../Entity/Shapes/SquareShape.hpp"
#pragma once

struct Resources;

class OptionsState final : public State {
public: // Functions
    
    explicit OptionsState(sf::RenderWindow& window, Resources& resources);
    
private: // Functions
    
    void processEvents() override;
    void update(sf::Time delta_time) override;
    void render() override;
    
    template <typename T>
    void handleButtonMouseInteraction(Button<T>&) const;
    
    void handleToggleMouseInteraction(Toggle&) const;
    
private: // Members
    
    sf::Cursor m_cursor;
    sf::Vector2f m_mouse_position;
    bool m_mouse_button_released;
    
private:
    
    sf::RectangleShape m_background;
    
    // Buttons
    Button<sf::CircleShape> m_back;
    
    // Toggles
    Toggle m_sound_toggle;
    Toggle m_music_toggle;
    Toggle m_balls_multicolor_toggle;
};


#endif /* OptionsState_hpp */
