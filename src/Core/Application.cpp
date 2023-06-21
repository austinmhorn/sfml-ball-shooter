//
//  Application.cpp
//  LockedInside
//
//  Created by Austin Horn on 9/30/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#include "Application.hpp"

#include "../State/MenuState.hpp"
#include "../State/PlayState.hpp"


#include <memory>

Application::Application()
: m_window{ sf::VideoMode(1024, 768), "SFML App", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings{0,0,8} } {
    //m_window.setVerticalSyncEnabled(true);
    m_window.setFramerateLimit(120);
    std::srand(std::time(nullptr));
}

void Application::run() {
    loadResources();

    // Simple state machine
    std::unique_ptr<State> state = std::make_unique<MenuState>(m_window, m_resources);

    while (state != nullptr) {
        state = state->run();
    }
}

void Application::loadResources() {
    
}
