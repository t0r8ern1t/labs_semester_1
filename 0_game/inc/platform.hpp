#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

namespace ssh
{
	class Platform
	{
	private:
		float m_x, m_y;
		int m_a, m_b;
		int m_velocity;
		sf::RectangleShape* m_shape;

	public:
		Platform(float x, float y, int a, int b, int velocity);
		~Platform();
		sf::RectangleShape* Get();
		float GetX();
		float GetY();
		int GetVelocity();
		void SetVelocity(float velocity);
		void Move(bool minus);
		int IfTangent(float x0, float y0, int r);
		void SetX(float x);
	};
}