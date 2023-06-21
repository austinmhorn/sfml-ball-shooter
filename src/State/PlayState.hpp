//
//  PlayState.hpp
//  App
//
//  Created by Austin Horn on 10/12/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef PlayState_hpp
#define PlayState_hpp

#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>

#include "Base/State.hpp"

#include "../Entity/Cannon.hpp"

#include "../Entity/NumberSquare.hpp"

struct Resources;

class PlayState final : public State {
public: // Functions
    
    explicit PlayState(sf::RenderWindow& window, Resources& resources);
    
private: // Functions
    
    void handleProjectileNumberSquareInteraction(Projectile* p, NumberSquare* s);
    
    void processEvents() override;
    void update(sf::Time delta_time) override;
    void render() override;
    
    
private: // Members
    sf::RectangleShape m_background;
    
    sf::Cursor m_cursor;
    sf::Vector2f m_mouse_position;
    bool m_mouse_button_released;
    
    
    Cannon m_cannon;
    
    std::queue<Projectile> m_unfired_proj;
    std::vector<Projectile> m_fired_proj;
    
    NumberSquare m_number_square;
    
};

#endif /* PlayState_hpp */
