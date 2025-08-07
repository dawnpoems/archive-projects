#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {

	std::cout << "triangle - (0, 0), (4, 0), (2, 3)" << std::endl;
	std::cout << "point - (2, 1) -> inside" << std::endl;
	std::cout << (bsp(Point(0, 0), Point(4, 0), Point(2, 3), Point(2, 1)) ? "True" : "False") << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	
	std::cout << "triangle - (0, 0), (4, 0), (2, 3)" << std::endl;
	std::cout << "point - (2, 3) -> inside (boundary)" << std::endl;
	std::cout << (bsp(Point(0, 0), Point(4, 0), Point(2, 3), Point(2, 3)) ? "True" : "False") << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	std::cout << "triangle - (0, 0), (4, 0), (2, 3)" << std::endl;
	std::cout << "point - (0, 1) -> outside" << std::endl;
	std::cout << (bsp(Point(0, 0), Point(4, 0), Point(2, 3), Point(0, 1)) ? "True" : "False") << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	std::cout << "triangle - (1, 1), (3, 1), (2, 4)" << std::endl;
	std::cout << "point - (2, 2) -> inside" << std::endl;
	std::cout << (bsp(Point(1, 1), Point(3, 1), Point(2, 4), Point(2, 2)) ? "True" : "False") << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	std::cout << "triangle - (1, 1), (3, 1), (2, 4)" << std::endl;
	std::cout << "point - (2, 1) -> inside (boundary)" << std::endl;
	std::cout << (bsp(Point(1, 1), Point(3, 1), Point(2, 4), Point(2, 1)) ? "True" : "False") << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	std::cout << "triangle - (1, 1), (3, 1), (2, 4)" << std::endl;
	std::cout << "point - (2, 0) -> outside" << std::endl;
	std::cout << (bsp(Point(1, 1), Point(3, 1), Point(2, 4), Point(2, 0)) ? "True" : "False") << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	std::cout << "triangle - (-3, 0), (3, 0), (0, 5)" << std::endl;
	std::cout << "point - (0, 1) -> inside" << std::endl;
	std::cout << (bsp(Point(-3, 0), Point(3, 0), Point(0, 5), Point(0, 1)) ? "True" : "False") << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	std::cout << "triangle - (-3, 0), (3, 0), (0, 5)" << std::endl;
	std::cout << "point - (4, 1) -> outside" << std::endl;
	std::cout << (bsp(Point(-3, 0), Point(3, 0), Point(0, 5), Point(4, 1)) ? "True" : "False") << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	std::cout << "triangle - (-2, -2), (2, -2), (0, 2)" << std::endl;
	std::cout << "point - (0, -1) -> inside" << std::endl;
	std::cout << (bsp(Point(-2, -2), Point(2, -2), Point(0, 2), Point(0, -1)) ? "True" : "False") << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	std::cout << "triangle - (-2, -2), (2, -2), (0, 2)" << std::endl;
	std::cout << "point - (0, -3) -> outside" << std::endl;
	std::cout << (bsp(Point(-2, -2), Point(2, -2), Point(0, 2), Point(0, -3)) ? "True" : "False") << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	std::cout << "triangle - (39.03, 6.42), (43.99, 99.28), (88.41, 8.92)" << std::endl;
	std::cout << "point - (43.09, 42.01) -> inside" << std::endl;
	std::cout << (bsp(Point(39.03f, 6.42f), Point(43.99f, 99.28f), Point(88.41f, 8.92f), Point(43.09f, 42.01f)) ? "True" : "False") << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	std::cout << "triangle - (34.06, 46.07), (41.36, 89.90), (63.79, 5.45)" << std::endl;
	std::cout << "point - (42.48, 74.51) -> inside" << std::endl;
	std::cout << (bsp(Point(34.06f, 46.07f), Point(41.36f, 89.90f), Point(63.79f, 5.45f), Point(42.48f, 74.51f)) ? "True" : "False") << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	std::cout << "triangle - (48.61, 70.42), (59.95, 91.50), (59.89, 92.02)" << std::endl;
	std::cout << "point - (84.79, 97.49) -> outside" << std::endl;
	std::cout << (bsp(Point(48.61f, 70.42f), Point(59.95f, 91.50f), Point(59.89f, 92.02f), Point(84.79f, 97.49f)) ? "True" : "False") << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	std::cout << "triangle - (90.10, 15.03), (5.42, 79.16), (52.17, 67.04)" << std::endl;
	std::cout << "point - (41.48, 97.94) -> outside" << std::endl;
	std::cout << (bsp(Point(90.10f, 15.03f), Point(5.42f, 79.16f), Point(52.17f, 67.04f), Point(41.48f, 97.94f)) ? "True" : "False") << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	return 0;
}