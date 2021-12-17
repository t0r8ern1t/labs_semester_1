#include <iostream>
#include <trapezoid.hpp>

int main()
{
    ssh::Trapezoid trap;
    ssh::Point A;
    ssh::Point B;
    double angle;
    std::cout << "Enter base angle and coordinates of two opposite points" << std::endl;
    std::cin >> angle >> A.x >> A.y >> B.x >> B.y;
    trap.SetA(A);
    trap.SetB(B);
    trap.SetAngle(angle);
    trap.GetSquare();
    trap.GetPerimeter();
    return 0;
}
