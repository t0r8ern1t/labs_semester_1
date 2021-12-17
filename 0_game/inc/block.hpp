#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

namespace ssh
{
	class Block
	{
	public:
		Block(float x, float y, int a, int b);
		~Block();
		bool Setup();
		sf::Sprite* Get();
		int GetX();
		int GetY();
		int GetA();
		int GetB();
		int IfTangent(float x0, float y0, int r);
		bool RandomPattern();

	private:
		int m_x, m_y;
		int m_a, m_b;

		sf::Texture m_texture;
		sf::Sprite* m_block = nullptr;
	};
}