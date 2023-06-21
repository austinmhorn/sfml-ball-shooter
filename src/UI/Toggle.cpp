//
//  Toggle.cpp
//  App
//
//  Created by Austin Horn on 10/9/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#include "Toggle.hpp"
#include "../Core/Assets.hpp"

static constexpr const float offset_slider = 2.5f;
static constexpr const float offset_status_text = 3.f;

Toggle::Toggle(bool active)
: m_background{ sf::StadiumShape{40.0f/2.f} }
, m_slider{ sf::CircleShape{(40.0f-(offset_slider*2.f))/2.f, 30} }
, m_status{ sf::Text{ (active) ? "ON" : "OFF", Resources::Zorque, 12} }
, m_description{ sf::Text{ "- \"Description of toggle switch\"", Resources::Zorque, 12} }
, m_placement(Toggle::Right)
, m_active(active)
, m_size(80.0f, 40.0f)
{
    init();
    //std::cout << "Toggle Default Constructor called" << std::endl;
}

Toggle::Toggle(Toggle& toggle) {
    m_background = toggle.m_background;
    m_slider = toggle.m_slider;
    m_status = toggle.m_status;
    m_active = toggle.m_active;
    m_description = toggle.m_description;
    m_placement = toggle.m_placement;
    //std::cout << "Toggle Copy Constructor called" << std::endl;
}

Toggle::Toggle(const Toggle& toggle) {
    m_background = toggle.m_background;
    m_slider = toggle.m_slider;
    m_status = toggle.m_status;
    m_active = toggle.m_active;
    m_description = toggle.m_description;
    m_placement = toggle.m_placement;
    //std::cout << "Toggle const qualified Copy Constructor called" << std::endl;
}

Toggle& Toggle::operator=(const Toggle &toggle) {
    if (this != &toggle) {
        m_background = toggle.m_background;
        m_slider = toggle.m_slider;
        m_status = toggle.m_status;
        m_active = toggle.m_active;
        m_description = toggle.m_description;
        m_placement = toggle.m_placement;
    }
    //std::cout << "Toggle Assignment Operator called" << std::endl;
    return *this;
}

void Toggle::init() {
        
    if (m_active) {
        m_slider.setPosition(m_background.getPosition().x + m_background.getSize().x - offset_slider,
                             m_background.getPosition().y + offset_slider );
        
        m_status.setPosition(offset_slider, offset_slider);
        
        m_background.setFillColor(Resources::LightGreen);

    }
    else {
        
        m_slider.setPosition(offset_slider, offset_slider);
        
        m_status.setPosition((m_background.getSize().x/2.f)+3.f,
                             (m_background.getSize().y/2.f)-(m_status.getGlobalBounds().height/2.f)-offset_status_text);
        
        m_background.setFillColor(Resources::Gray);
    }
    
    // Initialize background stadium shape
    m_background.setSize(m_size);
    m_background.setOutlineColor(sf::Color::White);
    m_background.setOutlineThickness(2.f);
    m_background.setPosition(0.f, 0.f);
    
    // Initialize slider circle shape
    m_slider.setFillColor(sf::Color::White);
    
    // Initialize status text
    m_status.setFillColor(sf::Color::White);

    setPosition(0.0f, 0.0f);
}

void Toggle::setPosition(const sf::Vector2f& position) {
    m_background.setPosition(position);
    
    (m_active)
    ? m_slider.setPosition(m_background.getPosition().x + m_background.getSize().x - (m_slider.getRadius()*2) - offset_slider,
                           position.y+offset_slider)
    : m_slider.setPosition(position.x+offset_slider, position.y+offset_slider);
    
    // Set position for new status text
    (m_active)
    ? m_status.setPosition(m_background.getPosition().x+(m_status.getGlobalBounds().height/2.f)+8.f,
                           m_background.getPosition().y+(m_status.getGlobalBounds().height/2.f)+8.f)
    : m_status.setPosition(m_background.getPosition().x+(m_background.getSize().x/2.f)+3.f,
                           m_background.getPosition().y+(m_background.getSize().y/2.f)-(m_status.getGlobalBounds().height/2.f)-offset_status_text);
    
    setDescriptionPlacement(m_placement);
}

void Toggle::setPosition(float x, float y) {
    m_background.setPosition(x, y);
    
    (m_active)
    ? m_slider.setPosition(m_background.getPosition().x + m_background.getSize().x - (m_slider.getRadius()*2) - offset_slider,
                           y+offset_slider)
    : m_slider.setPosition(x+offset_slider, y+offset_slider);
    
    // Set position for new status text
    (m_active)
    ? m_status.setPosition(m_background.getPosition().x+(m_status.getGlobalBounds().height/2.f)+8.f,
                           m_background.getPosition().y+(m_status.getGlobalBounds().height/2.f)+8.f)
    : m_status.setPosition(m_background.getPosition().x+(m_background.getSize().x/2.f)+3.f,
                           m_background.getPosition().y+(m_background.getSize().y/2.f)-(m_status.getGlobalBounds().height/2.f)-offset_status_text);
    
    setDescriptionPlacement(m_placement);
}

void Toggle::setDescription(const std::string& string) {
    m_description.setString(string);
}

void Toggle::setDescriptionPlacement(Side side) {
    sf::Vector2f center_point = {m_background.getPosition().x + (getExactSize().x/2.f), m_background.getPosition().y + (getExactSize().y/2.f)};
        
    switch (side) {
        case Top:
            
            break;
        case Bottom:
            
            break;
        case Left:
            
            break;
        case Right:
            m_description.setPosition(center_point.x + (getExactSize().x/2.f) + 5.0f, m_status.getPosition().y);
            break;
        case TopLeft:
            
            break;
        case TopRight:
            
            break;
        case BottomLeft:
            
            break;
        case BottomRight:
            
            break;
    }
    
}

sf::Vector2f Toggle::getApproxSize() const {
    return {std::round(getTransform().transformRect(m_background.getGlobalBounds()).width - (m_background.getOutlineThickness()*2.f)),
            std::round(getTransform().transformRect(m_background.getGlobalBounds()).height - (m_background.getOutlineThickness()*2.f))};
}

sf::Vector2f Toggle::getExactSize() const {
    return {getTransform().transformRect(m_background.getGlobalBounds()).width,
            getTransform().transformRect(m_background.getGlobalBounds()).height};
}

const bool& Toggle::getActive() const {
    return m_active;
}

Toggle::Side Toggle::getDescriptionPlacement() const {
    return m_placement;
}

const bool Toggle::contains(const sf::Vector2f& point) const {
    return getTransform().transformRect(m_background.getGlobalBounds()).contains(point);
}

void Toggle::mouseOver() {
    m_slider.setFillColor({m_slider.getFillColor().r, m_slider.getFillColor().g, m_slider.getFillColor().b, 150});
}

void Toggle::mouseLeave() {
    m_slider.setFillColor({m_slider.getFillColor().r, m_slider.getFillColor().g, m_slider.getFillColor().b, 255});
}

void Toggle::leftClick() { return; }
void Toggle::rightClick() { return; }

void Toggle::update(sf::Time delta_time) {
    animate(delta_time);
}

void Toggle::updateGeometry(const sf::Vector2f& position) {
    
}

void Toggle::animate(sf::Time& delta_time) {
    sf::Time final_time = sf::seconds(1.f);
    sf::Time curr_time = sf::seconds(0.f);
    sf::Time total_time = sf::seconds(0.f);
    float x_start = m_background.getPosition().x + offset_slider;
    float x_final = m_background.getPosition().x + m_background.getSize().x - (m_slider.getRadius()*2) - offset_slider;
    float delta_x = (x_final-x_start)/10.f;
    
    sf::Clock clock;
    clock.restart();
    
    while (total_time < final_time) {
        curr_time += clock.getElapsedTime();
        if (curr_time.asSeconds() >= 0.1f) {
            
            (m_active) ? animateOff(delta_x) : animateOn(delta_x);
            
            total_time += curr_time;
            curr_time = clock.restart();
        }
    }
    
    // Set status complement
    m_active = !m_active;
    
    // Recolor background stadium shape in correspondence with current status
    (m_active) ? m_background.setFillColor(Resources::LightGreen) : m_background.setFillColor(Resources::Gray);
    // Set appropriate text for current status
    (m_active) ? m_status.setString("ON") : m_status.setString("OFF");
    // Set position for new status text
    (m_active)
    ? m_status.setPosition(m_background.getPosition().x+(m_status.getGlobalBounds().height/2.f)+8.f,
                           m_background.getPosition().y+(m_status.getGlobalBounds().height/2.f)+8.f)
    : m_status.setPosition(m_background.getPosition().x+(m_background.getSize().x/2.f)+3.f,
                           m_background.getPosition().y+(m_background.getSize().y/2.f)-(m_status.getGlobalBounds().height/2.f)-offset_status_text);
}

void Toggle::animateOn(float delta_x) {
    m_slider.move(delta_x, 0.f);
}

void Toggle::animateOff(float delta_x) {
    m_slider.move(-delta_x, 0.f);
}

void Toggle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_background, states);
    target.draw(m_status, states);
    target.draw(m_slider, states);
    target.draw(m_description, states);
}
