#include <block.hpp>

namespace ssh
{
	Block::Block(float x, float y, int a, int b)
	{
		m_a = a;
		m_b = b;
		m_x = x;
		m_y = y;
	}

	Block::~Block ()
	{
		if (m_block != nullptr)
			delete m_block;
	}

	bool Block::Setup()
	{
		if (!m_texture.loadFromFile("img/block.png"))
		{
			std::cout << "ERROR when loading block.png" << std::endl;
			return false;
		}

		m_block = new sf::Sprite();
		m_block->setTexture(m_texture);
		m_block->setOrigin(m_a/2, m_b/2);
		m_block->setPosition(m_x, m_y);
		m_block->setScale(0.26, 0.26);

		return true;
	}

	sf::Sprite* Block::Get() { return m_block; }

	int Block::GetX() { return m_x; }
	int Block::GetY() { return m_y; }
	int Block::GetA() { return m_a; }
	int Block::GetB() { return m_b; }

	int Block::IfTangent(float x0, float y0, int r) {
		float l = (x0 - GetX()) * (x0 - GetX()) + (y0 - GetY()) * (y0 - GetY());
		if ((x0 - GetX()) * (x0 - GetX()) + (y0 - GetY()) * (y0 - GetY()) == r * r)
			return 1;
		if ((abs(GetX() - x0) <= m_a / 2 + r) && (abs(GetY() - y0) <= m_b / 2 + r))
			return 1;
		else return 0;
	}

	bool Block::RandomPattern() {
		int r = rand() % 2;
		if (r == 0) return 0;
		else return 1;
	}
}