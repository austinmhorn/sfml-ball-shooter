//
//  Assets.hpp
//  LockedInside
//
//  Created by Austin Horn on 9/30/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef Assets_hpp
#define Assets_hpp

#include <SFML/Graphics.hpp>

#include <cstdint>
#include <iostream>
#include <cmath>
#include <map>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>
#include <filesystem>
#include <fstream>
#include <random>

#define _USE_MATH_DEFINES

#include "Containers/Templates.hpp"
#pragma once

#include "../UI/Toggle.hpp"
#pragma once

#include "../Entity/Base/Animation.hpp"
#pragma once

#include "../Entity/Base/ParticleEmitter.hpp"
#pragma once


namespace Font {

static const std::string __filepath_TimesNewRoman = "src/Assets/TimesNewRoman.otf";
static const std::string __filepath_Zorque = "src/Assets/Zorque.otf";
static const sf::Font __init_TimesNewRoman() {
    static sf::Font font;
    if(!font.loadFromFile(__filepath_TimesNewRoman))
        throw std::runtime_error("Failed loading asset " + __filepath_TimesNewRoman);
    return font;
}
static const sf::Font __init_Zorque() {
    static sf::Font font;
    if(!font.loadFromFile(__filepath_Zorque))
        throw std::runtime_error("Failed loading asset " + __filepath_Zorque);
    return font;
}
} // End of namespace 'Font'

namespace Texture {
    
} // End of namespace 'Texture'

namespace Cursors {
static const void __init_ArrowCursor() {
    sf::Cursor cursor;
    if (!cursor.loadFromSystem(sf::Cursor::Arrow))
        throw std::runtime_error("Failed loading system cursor type <Cursor::Arrow>");
}
static const void __init_TextCursor() {
    sf::Cursor cursor;
    if (!cursor.loadFromSystem(sf::Cursor::Text))
        throw std::runtime_error("Failed loading system cursor type <Cursor::Text>");
}
static const void __init_HandCursor() {
    sf::Cursor cursor;
    if (!cursor.loadFromSystem(sf::Cursor::Hand))
        throw std::runtime_error("Failed loading system cursor type <Cursor::Hand>");
}
static const void __init_CrossCursor() {
    sf::Cursor cursor;
    if (!cursor.loadFromSystem(sf::Cursor::Cross))
        throw std::runtime_error("Failed loading system cursor type <Cursor::Cross>");
}
static const void __init_HelpCursor() {
    sf::Cursor cursor;
    if (!cursor.loadFromSystem(sf::Cursor::Help))
        throw std::runtime_error("Failed loading system cursor type <Cursor::Help>");
}
} // End of namespace 'Cursor'

namespace Saves {

static void __import_save_file() {
    //std::ifstream inFS (save_file, std::ios_base::in);
    
    //inFS.close();
}

static void __export_save_file() {
    //std::ofstream outFS (save_file, std::ios_base::in);
    
    //outFS.close();
}

} // End of namespace 'Saves'

class Settings {
public: // Functions
    
    inline constexpr Settings() = default;
    
    friend struct Resources;
    
    static inline void setSoundIsOn(bool is_on) { __s_sound_is_on = is_on; }
    static inline void setMusicIsOn(bool is_on) { __s_music_is_on = is_on; }
    static inline void setBallsMulticolorIsOn(bool is_on) { __s_balls_multicolor_is_on = is_on; }
    static inline void setNumPlayers(unsigned int num) { __s_number_of_players = num; }
    
    static inline bool getSoundIsOn() { return __s_sound_is_on; }
    static inline bool getMusicIsOn() { return __s_music_is_on; }
    static inline bool getBallsMulticolorIsOn() { return __s_balls_multicolor_is_on; }
    static inline bool getNumPlayers() { return __s_number_of_players; }
    
private: // Members
    
    static bool __s_sound_is_on;
    static bool __s_music_is_on;
    static bool __s_balls_multicolor_is_on;
    static unsigned int __s_number_of_players;
};

struct Resources {
    // Fonts
    static sf::Font TimesNewRoman;
    static sf::Font Zorque;
    
    // Colors
    static sf::Color Gray;
    static sf::Color DarkGreen;
    static sf::Color DarkRed;
    static sf::Color DarkPurple;
    static sf::Color LightBlue;
    static sf::Color Seafoam;
    static sf::Color LightGreen;
    static sf::Color Peach;
    static sf::Color Tan;
    static sf::Color Pink;
    static sf::Color LightPurple;
    static sf::Color Orange;
    static sf::Color DarkBlue;
    
    static Settings settings;
    
    //static const bool __load_cursors();
};







namespace Helpers
{

    ///
    template <typename T>
    struct map_init_helper {
        T& m_data;
        map_init_helper(T& data) : m_data(data) {}
        /// Overloaded function call operator for pairing process
        map_init_helper& operator() (typename T::key_type const& key, typename T::mapped_type const& value)
        {
            m_data[key] = value;
            return *this;
        }
    };

    /// Template function for 'pairing'
    template<typename T>
    map_init_helper<T> map_init(T& item) {
        return map_init_helper<T>(item);
    }

}

#undef _USE_MATH_DEFINES


#endif /* Assets_hpp */
