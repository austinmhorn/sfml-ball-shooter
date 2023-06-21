//
//  Animation.hpp
//  App
//
//  Created by Austin Horn on 10/10/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef Animation_hpp
#define Animation_hpp

#include <SFML/Graphics/Sprite.hpp>
#pragma once

#include <iostream>
#include <vector>

struct Frame {
   sf::IntRect rect;
   float duration;
};

class Animation {
private:
    
    sf::Sprite* m_target;
    std::vector<Frame> m_frames;
    
    float m_total_length;
    float m_total_progress;
    
public:
    
    template <typename T>
    explicit Animation(T& target) {
        this->m_target = &target;
        m_total_progress = 0.0f;
    }
    
    Animation(sf::Sprite& target) {
        this->m_target = &target;
        m_total_progress = 0.0f;
    }

    void addFrame(Frame& frame) {
        m_frames.push_back(std::move(frame));
        m_total_length += frame.duration;
    }

    void update(float elapsed) {
        m_total_progress += elapsed;
    
        float progress = m_total_progress;
        for (auto frame : m_frames) {
            progress -= (frame).duration;
    
            if (progress <= 0.0f || &(frame) == &m_frames.back()) {
                this->m_target->setTextureRect((frame).rect);
                break;
            }
        }
    }
};

/*
 sf::Sprite myCharacter;
 // Load the image...
 Animation animation(myCharacter);
 animation.addFrame({sf::IntRect(x,y,w,h), 0.1});
 // do this for as many frames as you need

 // In your main loop:
 animation.update(elapsed);
 window.draw(myCharacter);
 */
    
#endif /* Animation_hpp */
