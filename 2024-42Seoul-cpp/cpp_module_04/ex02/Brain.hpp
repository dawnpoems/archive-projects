#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	Brain(Brain const &brain);
	Brain &operator=(Brain const &brain);
	~Brain();

	std::string getIdea(int index) const;
	void setIdea(int index, std::string idea);
};

#endif // BRAIN_HPP