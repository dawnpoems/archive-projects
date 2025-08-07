#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bureaucrat("bureaucrat", 150);
	std::cout << bureaucrat << std::endl;
	try
	{
		Bureaucrat bureaucrat("bureaucrat", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("bureaucrat", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("bureaucrat", 2);
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("bureaucrat", 149);
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;

}