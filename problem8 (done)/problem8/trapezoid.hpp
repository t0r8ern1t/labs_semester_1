#pragma once
#include <iostream>
#define pi acos(-1)

namespace ssh {
	
	struct Point {
		double x, y;
	};

	class Trapezoid {
	private:
			Point m_A;
			Point m_B;
			double m_angle = 1/2;
	public:
		Trapezoid::Trapezoid(Point A, Point B, double angle);
		Trapezoid::Trapezoid();
		Trapezoid:: ~Trapezoid();
		void Trapezoid::SetA(Point A);
		void Trapezoid::SetB(Point B);
		void Trapezoid::SetAngle(double angle);
		void Trapezoid::GetSquare();
		void Trapezoid::GetPerimeter();	
	};
}