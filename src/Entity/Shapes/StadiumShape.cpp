//
//  StadiumShape.cpp
//  App
//
//  Created by Austin Horn on 10/7/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#include "StadiumShape.hpp"

#include <cmath>

#define _USE_MATH_DEFINES

////////////////////////////////////////////////////////////
/// \brief Default constructor
///
/// \param radius Radius for each rounded corner
////////////////////////////////////////////////////////////
sf::StadiumShape::StadiumShape(float radius)
: m_size(300.0f, 60.0f)
, m_radius(radius)
, m_antialiasing(8)
{
    updateGeometry();
}

////////////////////////////////////////////////////////////
/// \brief Calls private Shape function Shape::update()
///
/// \see sf::Shape::update()
////////////////////////////////////////////////////////////
void sf::StadiumShape::updateGeometry()
{
    Shape::update();
}

////////////////////////////////////////////////////////////
/// \brief Set the size of the rounded rectangle
///
/// \param size New size of the rounded rectangle
///
/// \see getSize
////////////////////////////////////////////////////////////
void sf::StadiumShape::setSize(const sf::Vector2f& size)
{
    m_size = size;
    updateGeometry();
}

////////////////////////////////////////////////////////////
/// \brief Set the radius of the rounded corners
///
/// \param radius Radius of the rounded corners
///
/// \see getCornersRadius
////////////////////////////////////////////////////////////
void sf::StadiumShape::setCornersRadius(float radius)
{
    m_radius = radius;
    updateGeometry();
}

////////////////////////////////////////////////////////////
/// \brief Set the number of points of each corner
///
/// \param antialiasing New number of points of the rounded rectangle
///
/// \see getPointCount
////////////////////////////////////////////////////////////
void sf::StadiumShape::setAntialiasing(unsigned int antialiasing)
{
    m_antialiasing = antialiasing;
    updateGeometry();
}

////////////////////////////////////////////////////////////
/// \brief Adjusts shape's alpha value to appear translucent
///
/// \param translucent Indicates if shape will be translucent
////////////////////////////////////////////////////////////
void sf::StadiumShape::setTranslucent(const bool &translucent)
{
    (translucent) ? setFillColor({getFillColor().r, getFillColor().g, getFillColor().b, 150})
                  : setFillColor({getFillColor().r, getFillColor().g, getFillColor().b, 255});
}

////////////////////////////////////////////////////////////
/// \brief Get the size of the rounded rectangle
///
/// \return Size of the rounded rectangle
///
/// \see setSize
////////////////////////////////////////////////////////////
const sf::Vector2f& sf::StadiumShape::getSize() const
{
    return m_size;
}

////////////////////////////////////////////////////////////
/// \brief Get the radius of the rounded corners
///
/// \return Radius of the rounded corners
///
/// \see setCornersRadius
////////////////////////////////////////////////////////////
float sf::StadiumShape::getCornersRadius() const
{
    return m_radius;
}

////////////////////////////////////////////////////////////
/// \brief Get the number of points defining the rounded rectangle
///
/// \return Number of points of the rounded rectangle
////////////////////////////////////////////////////////////
std::size_t sf::StadiumShape::getPointCount() const
{
    return m_antialiasing*4;
}

////////////////////////////////////////////////////////////
/// \brief Get a point of the rounded rectangle
///
/// The result is undefined if \a index is out of the valid range.
///
/// \param index Index of the point to get, in range [0 .. GetPointCount() - 1]
///
/// \return Index-th point of the shape
////////////////////////////////////////////////////////////
sf::Vector2f sf::StadiumShape::getPoint(std::size_t index) const
{
    if(index >= m_antialiasing*4) { return sf::Vector2f(0,0); }

    float deltaAngle = 90.f/(m_antialiasing-1);
    sf::Vector2f center;
    unsigned int centerIndex = index/m_antialiasing;

    switch(centerIndex) {
        case 0: center.x = m_size.x - m_radius; center.y = m_radius;            break;
        case 1: center.x = m_radius;            center.y = m_radius;            break;
        case 2: center.x = m_radius;            center.y = m_size.y - m_radius; break;
        case 3: center.x = m_size.x - m_radius; center.y = m_size.y - m_radius; break;
    }

    return sf::Vector2f(m_radius*std::cos(deltaAngle*(index-centerIndex)*M_PI/180)+center.x,
                       -m_radius*std::sin(deltaAngle*(index-centerIndex)*M_PI/180)+center.y);
}

#undef _USE_MATH_DEFINES
