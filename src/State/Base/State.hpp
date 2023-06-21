//
//  State.hpp
//  LockedInside
//
//  Created by Austin Horn on 9/30/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

struct Resources;

class State {
protected:
    
    virtual void processEvents() = 0;
    virtual void update(sf::Time delta_time) = 0;
    virtual void render() = 0;

    sf::RenderWindow& m_window;
    Resources& m_resources;

    std::unique_ptr<State> m_next;
    
public:
    
    explicit State(sf::RenderWindow& window, Resources& resources);
    virtual ~State() = default;

    State(const State&) = delete;
    State& operator=(const State&) = delete;

    State(State&&) = default;

    std::unique_ptr<State> run();
};

#include <memory>

#endif /* State_hpp */
