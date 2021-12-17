#include <platform.hpp>
#include <windows.h>
#include <math.h>

namespace ssh
{
    const int width = 800;
    const int height = 600;

    Platform::Platform(float x, float y, int a, int b, int velocity) {
        m_x = x;
        m_y = y;
        m_a = a;
        m_b = b;
        m_velocity = velocity;
        m_shape = new sf::RectangleShape(sf::Vector2f(m_a, m_b));
        m_shape->setOrigin(m_a / 2, m_b / 2);
        m_shape->setFillColor(sf::Color::Red);
        m_shape->setPosition(m_x, m_y);
    }

    Platform::~Platform() {
        delete m_shape;
    }

    sf::RectangleShape* Platform::Get() {
        return m_shape;
    }

    float Platform::GetX() {
        return m_x;
    }

    float Platform::GetY() {
        return m_y;
    }

    int Platform::GetVelocity() {
        return m_velocity;
    }

    void Platform::SetVelocity(float velocity) {
        m_velocity = velocity;
    }

    void Platform::Move(bool minus) {
        if ((minus == 1) && (m_x < width - m_a / 2))
            m_x += m_velocity;
        else if ((minus == 0) && (m_x > m_a / 2))
            m_x -= m_velocity;
        m_shape->setPosition(m_x, m_y);
    }
 
    int Platform::IfTangent(float x0, float y0, int r) {
        float l = (x0 - GetX()) * (x0 - GetX()) + (y0 - GetY()) * (y0 - GetY());
        if ((abs(GetY() - y0 <= m_b / 2 + 2*r))&&(abs(GetX() - x0) > m_a / 2) && ((GetX() - x0) * (GetX() - x0) + (GetY() - y0) * (GetY() - y0) < (2*r + m_a) * (2*r + m_a)))
            return 2; //файналли эта формула работает
        if ((abs(GetX() - x0) <= m_a / 2) && (abs(GetY() - y0) == m_b / 2 + 2*r))
            return 1;
        else return 0;
    }

    void Platform::SetX(float x) {
        m_x = x;
        m_shape->setPosition(m_x, m_y);
    }

}