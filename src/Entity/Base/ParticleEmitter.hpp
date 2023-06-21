//
//  ParticleEmitter.hpp
//  App
//
//  Created by Austin Horn on 10/13/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef ParticleEmitter_hpp
#define ParticleEmitter_hpp

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/VertexArray.hpp>

#include <cmath>

#define _USE_MATH_DEFINES

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:

    ParticleSystem(unsigned int count) :
    m_particles(count),
    m_vertices(sf::Points, count),
    m_lifetime(sf::seconds(3.f)),
    m_position(0.f, 0.f)
    {
    }
    
    void setColor(sf::Color color)
    {
        for (std::size_t i = 0; i < m_particles.size(); ++i)
            m_vertices[i].color = color;
    }
    
    void setColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a)
    {
        for (std::size_t i = 0; i < m_particles.size(); ++i)
            m_vertices[i].color = {r, g, b, a};
    }
    
    void setLifetime(float lifetime)
    {
        m_lifetime = sf::seconds(lifetime);
    }

    void setPosition(sf::Vector2f position)
    {
        m_position = position;
    }
    
    void setPosition(float x, float y)
    {
        m_position.x = x;
        m_position.y = y;
    }
    
    void update(sf::Time elapsed)
    {
        for (std::size_t i = 0; i < m_particles.size(); ++i)
        {
            // update the particle lifetime
            Particle& p = m_particles[i];
            p.lifetime -= elapsed;

            // if the particle is dead, respawn it
            if (p.lifetime <= sf::Time::Zero)
                resetParticle(i);

            // update the position of the corresponding vertex
            m_vertices[i].position += p.velocity * elapsed.asSeconds();

            // update the alpha (transparency) of the particle according to its lifetime
            float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
            m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
        }
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // our particles don't use a texture
        states.texture = nullptr;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

private:

    struct Particle
    {
        sf::Vector2f velocity;
        sf::Time lifetime;
    };

    void resetParticle(std::size_t index)
    {
        // give a random velocity and lifetime to the particle
        float angle = (std::rand() % 360) * M_PI / 180.f;
        float speed = (std::rand() % 50) + 50.f;
        m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
        m_particles[index].lifetime = sf::milliseconds((std::rand() % 2000) + 1000);

        // reset the position of the corresponding vertex
        m_vertices[index].position = m_position;
    }

    std::vector<Particle> m_particles;
    sf::VertexArray m_vertices;
    sf::Time m_lifetime;
    sf::Vector2f m_position;
};

#undef _USE_MATH_DEFINES

#endif /* ParticleEmitter_hpp */
