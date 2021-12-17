#pragma once
#include <SFML/Graphics.hpp>

namespace ssh {
    class Circle {
    private:
        float m_x, m_y, m_r; // x, y - центр
        float m_vx, m_vy;
        sf::Texture m_texture;
        sf::Sprite* m_circle = nullptr;

    public:
        Circle(float x, float y, float r, float vx, float vy);
        ~Circle();
        bool Setup();
        sf::Sprite* Get();
        void SetXVelocity(float vx);
        void SetYVelocity(float vy);
        float GetXVelocity();
        float GetYVelocity();
        void Move();
        float GetX();
        float GetY();
        void SetX(float x);
        void SetY(float y);
    };
}