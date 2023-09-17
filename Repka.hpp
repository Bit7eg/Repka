#pragma once

#include <SFML/Graphics.hpp>

class Repka: public sf::CircleShape {
public:
    int need_strength = 21;
    Repka(float radius = (0.0F), size_t pointCount = 30): sf::CircleShape(radius, pointCount) {}
};