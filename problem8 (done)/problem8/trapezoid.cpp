#define _USE_MATH_DEFINES
#include <trapezoid.hpp>
#include <math.h>
#include <iostream>

namespace ssh 
{
	Trapezoid::Trapezoid(){}

	Trapezoid::Trapezoid(Point A, Point B, double angle) {
		m_A = A;
		m_B = B;
		m_angle = angle;
		if (angle > 1) {
			std::cout << "wrong data. the anlge must belong to the segment from 0 to pi" << std::endl;
			std::cout << "angle is now equal pi/2" << std::endl;
			m_angle = 1 / 2;
		}
	}

	Trapezoid:: ~Trapezoid(){}

	void Trapezoid::SetA(Point A) {
		m_A.x = A.x;
		m_A.y = A.y;
	}

	void Trapezoid::SetB(Point B) {
		m_B.x = B.x;
		m_B.y = B.y;
	}

	void Trapezoid::SetAngle(double angle) {
		m_angle = angle;
		if (angle > M_PI / 2) {
			std::cout << "wrong data. the anlge must belong to the segment from 0 to pi/2" << std::endl;
		}
	}

	void Trapezoid::GetSquare() {
		if (m_angle > M_PI / 2)
			std::cout << "no square and perimeter sorry" << std::endl; else
			std::cout << abs((m_A.x - m_B.x) * (m_A.y - m_B.y)) << std::endl;
	}

	void Trapezoid::GetPerimeter() {
		if (m_angle <= M_PI / 2)
			std::cout << 2 * (abs(m_A.x - m_B.x) + abs((m_A.y - m_B.y) / sin(m_angle * M_PI))) << std::endl;
	}
}