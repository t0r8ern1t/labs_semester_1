#pragma once
#include <SFML/Graphics.hpp>

namespace ssh {
    class Square {
    private:
        float m_x, m_y, m_a; // x, y - центр
        float m_velocity;
        sf::RectangleShape* m_shape;

    public:
        Square(float x, float y, float a, float velocity);

        ~Square();

        sf::RectangleShape* Get();

        void SetVelocity(float velocity);

        void Move();

        float GetX();

        void SetX(float x);
    };
}