//
//  Toggle.hpp
//  App
//
//  Created by Austin Horn on 10/9/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef Switch_hpp
#define Switch_hpp

#include "../Entity/Base/Entity.hpp"
#pragma once
#include "../Entity/Shapes/StadiumShape.hpp"
#pragma once

class Toggle : public Entity, public Clickable {
public:
    
    enum Side {
        Top,
        Bottom,
        Left,
        Right,
        TopLeft,
        TopRight,
        BottomLeft,
        BottomRight
    };
    
private:
    
    sf::StadiumShape m_background;
    sf::CircleShape m_slider;
    sf::Text m_status;
    bool m_active;
    sf::Vector2f m_size;
    
    sf::Text m_description;
    Toggle::Side m_placement;
    
    void init();
    
public:
    
    Toggle(bool);
    ~Toggle() = default;
    Toggle(Toggle&);
    Toggle(const Toggle&);
    Toggle& operator=(const Toggle&);
    
    void setPosition(const sf::Vector2f&);
    void setPosition(float, float);
    void setDescription(const std::string&);
    void setDescriptionPlacement(Toggle::Side);
    
    sf::Vector2f getApproxSize() const;
    sf::Vector2f getExactSize() const;
    const bool& getActive() const;
    const std::string& getDescription() const;
    Toggle::Side getDescriptionPlacement() const;
    
    virtual const bool contains(const sf::Vector2f&) const override;
    virtual void mouseOver() override;
    virtual void mouseLeave() override;
    virtual void leftClick() override;
    virtual void rightClick() override;
    virtual void update(sf::Time) override;
    void updateGeometry(const sf::Vector2f&);
    
    void animate(sf::Time&);
    void animateOn(float);
    void animateOff(float);
    
    void draw(sf::RenderTarget&, sf::RenderStates) const override;
};

#endif /* Switch_hpp */
