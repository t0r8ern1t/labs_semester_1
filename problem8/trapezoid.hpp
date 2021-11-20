#pragma once
#include <iostream>
# define PI acos(-1)

namespace ssh {
	
	struct Point {
		int x, y;
	};

	class Trapezoid {
	private:
			Point m_A;
			Point m_B;
			double m_angle;
	public:
		Trapezoid::Trapezoid(Point A, Point B, double angle);
		Trapezoid::Trapezoid();
		Trapezoid:: ~Trapezoid();
		void Trapezoid::SetA(Point A);
		void Trapezoid::SetB(Point B);
		void Trapezoid::SetAngle(double angle);
		double Trapezoid::GetSquare();
		double Trapezoid::GetPerimeter();	
	};
}