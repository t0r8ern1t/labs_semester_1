#include "Square.hpp"

namespace ssh
{
        Square::Square(float x, float y, float a, float velocity) {
            m_x = x;
            m_y = y;
            m_a = a;
            m_velocity = velocity;
            m_shape = new sf::RectangleShape(sf::Vector2f(m_a, m_a));
            m_shape->setOrigin(m_a / 2, m_a / 2);
            m_shape->setFillColor(sf::Color::Yellow);
            m_shape->setPosition(m_x, m_y);
        }

        Square::~Square() {
            delete m_shape;
        }

        sf::RectangleShape* Square::Get() {
            return m_shape;
        }

        void Square::SetVelocity(float velocity) {
            m_velocity = velocity;
        }

        void Square::Move() {
            m_x -= m_velocity;
            m_shape->setPosition(m_x, m_y);
        }

        float Square::GetX() {
            return m_x;
        }

        void Square::SetX(float x) {
            m_x = x;
            m_shape->setPosition(m_x, m_y);
        }
}