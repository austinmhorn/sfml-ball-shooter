//
//  Application.hpp
//  LockedInside
//
//  Created by Austin Horn on 9/30/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef Application_hpp
#define Application_hpp

#include <SFML/Graphics.hpp>
#pragma once

#include "Assets.hpp"
#pragma once

class Application {
public:
    Application();

    void run();

private:
    void loadResources();

    sf::RenderWindow m_window;
    Resources m_resources;
};

#endif /* Application_hpp */
