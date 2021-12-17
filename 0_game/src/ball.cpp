#include "ball.hpp"
#include <iostream>

namespace ssh
{
    Circle::Circle(float x, float y, float r, float vx, float vy) {
        m_x = x;
        m_y = y;
        m_r = r;
        m_vx = vx;
        m_vy = vy;
    }

    bool Circle::Setup()
    {
        if (!m_texture.loadFromFile("img/fireball.png"))
        {
            std::cout << "ERROR when loading fireball.png" << std::endl;
            return false;
        }

        m_circle = new sf::Sprite();
        m_circle->setTexture(m_texture);
        m_circle->setOrigin(m_r, m_r);
        m_circle->setPosition(m_x, m_y);
        m_circle->setScale(0.1, 0.1);

        return true;
    }


    Circle::~Circle() {
        if (m_circle != nullptr)
            delete m_circle;
    }

    sf::Sprite* Circle::Get() {
        return m_circle;
    }

    void Circle::SetXVelocity(float vx) {
        m_vx = vx;
    }

    void Circle::SetYVelocity(float vy) {
        m_vy = vy;
    }

    float Circle::GetXVelocity() { return m_vx; }

    float Circle::GetYVelocity() { return m_vy; }

    void Circle::Move() {
        m_x += m_vx;
        m_y -= m_vy;
        m_circle->setPosition(m_x, m_y);
       // std::cout << m_vy;
    }

    float Circle::GetX() { return m_x; }

    float Circle::GetY() { return m_y; }

    void Circle::SetX(float x) {
        m_x = x;
        m_circle->setPosition(m_x, m_y);
    }

    void Circle::SetY(float y) {
        m_y = y;
        m_circle->setPosition(m_x, m_y);
    }
}