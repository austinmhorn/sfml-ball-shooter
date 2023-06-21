//
//  Assets.cpp
//  LockedInside
//
//  Created by Austin Horn on 9/30/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#include "Assets.hpp"

// Fonts
sf::Font Resources::TimesNewRoman = Font::__init_TimesNewRoman();
sf::Font Resources::Zorque = Font::__init_Zorque();

// Colors
sf::Color Resources::Gray        = sf::Color(  37,  37,  37, 255 );
sf::Color Resources::DarkGreen   = sf::Color(  92, 127,  99, 255 );
sf::Color Resources::DarkRed     = sf::Color( 127,  91,  92, 255 );
sf::Color Resources::DarkPurple  = sf::Color( 113,  92, 127, 255 );
sf::Color Resources::LightBlue   = sf::Color( 154, 183, 211, 255 );
sf::Color Resources::Seafoam     = sf::Color( 163, 225, 220, 255 );
sf::Color Resources::LightGreen  = sf::Color( 151, 193, 169, 255 );
sf::Color Resources::Peach       = sf::Color( 255, 218, 193, 255 );
sf::Color Resources::Tan         = sf::Color( 246, 234, 194, 255 );
sf::Color Resources::Pink        = sf::Color( 255, 200, 221, 255 );
sf::Color Resources::LightPurple = sf::Color( 223, 204, 241, 255 );
sf::Color Resources::Orange      = sf::Color( 239, 190, 125, 255 );
sf::Color Resources::DarkBlue    = sf::Color(  69,  80, 163, 255 );

bool Settings::__s_sound_is_on = false;
bool Settings::__s_music_is_on = false;
bool Settings::__s_balls_multicolor_is_on = true;
unsigned int Settings::__s_number_of_players = 1;
