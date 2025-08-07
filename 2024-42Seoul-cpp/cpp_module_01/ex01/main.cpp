#include "Zombie.hpp"
#include <cstdlib>

int main(int argc, char **argv) {
	
	int N(0);

	if (argc != 2) {
		return 1;
	}
	N = std::atoi(argv[1]);
	Zombie *horde = zombieHorde(N, "Zombie");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	
	delete[] horde;
	return 0;
}
