//
//  Projectile.cpp
//  App
//
//  Created by Austin Horn on 10/21/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#include "Projectile.hpp"

bool Projectile::s_selfCollisionEnabled = false;

Projectile::Projectile(float baseRadius) :
circle({sf::CircleShape{5.f, 30}}),
position({512.0f-baseRadius, 768.0f-(circle.getRadius()*2)}),
velocity({0.0f, 0.0f}),
bounds({1024, 768}),
speed(1.75f),
mass(1.0f),
m_shot(false),
m_loaded(false),
m_lifetime(sf::seconds(5.0f)),
collider(nullptr),
squareCollider(nullptr)
{
    circle.setOrigin(circle.getRadius(), circle.getRadius());
    circle.setPosition(position);
}

void Projectile::update(sf::Time &delta_time)
{
    // Ball collided with vertical wall
    if (position.x <= 0 || position.x >= bounds.x - circle.getRadius()*2)
        velocity.x *= -1;
    
    // Ball collided with horizontal wall
    if (position.y <= 0 || position.y >= bounds.y - circle.getRadius()*2)
        velocity.y *= -1;
    
    position.x += velocity.x;
    position.y += velocity.y;
    
    circle.setPosition(position);
}

bool Projectile::collidedWithProjectile(Projectile* rhs)
{
    if ( !collider )
    {
        if ( this->intersects(rhs) )
        {
            this->collider = rhs;
            rhs->collidedWithProjectile(this->collider);
            return true;
        }
    }
    else
    {
        return false;
    }
}

void Projectile::resetCollision()
{
    this->collider = nullptr;
}

void Projectile::processProjectileAndProjectileCollision(Projectile* b1, Projectile* b2)
{
    if (b1->collidedWithProjectile(b2)) // Check if two projectiles collided
    {
        std::swap(b1->velocity, b2->velocity);
    }
}

bool Projectile::intersects(const sf::FloatRect& rectangle) const
{
    return circle.getGlobalBounds().intersects(rectangle);
}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(circle, states);
}
