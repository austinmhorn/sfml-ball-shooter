//
//  State.cpp
//  LockedInside
//
//  Created by Austin Horn on 9/30/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#include "State.hpp"

State::State(sf::RenderWindow& window, Resources& resources)
: m_window{ window }
, m_resources{ resources } {
    
}

std::unique_ptr<State> State::run()
{
    const auto clock = sf::Clock{};
    auto last_frame_time = sf::Time{};

    while (m_next == nullptr && m_window.isOpen())
    {
        const auto delta_time = clock.getElapsedTime() - last_frame_time;
        last_frame_time = clock.getElapsedTime();

        update(delta_time);
        render();
    }

    return std::move(m_next);
}
