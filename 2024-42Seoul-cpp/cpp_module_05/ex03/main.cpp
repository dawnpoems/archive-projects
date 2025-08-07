#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	Bureaucrat bureaucrat("bureaucrat", 1);

	std::cout << "----------shrubberyCreationForm----------" << std::endl;
	AForm* shrubbery;
	shrubbery = someRandomIntern.makeForm("shrubbery creation", "Bender");
	bureaucrat.signForm(*shrubbery);
	bureaucrat.executeForm(*shrubbery);
	delete shrubbery;

	std::cout << "\n----------robotomyRequestForm----------" << std::endl;
	AForm* robotomy;
	robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
	bureaucrat.signForm(*robotomy);
	bureaucrat.executeForm(*robotomy);
	delete robotomy;

	std::cout << "\n----------presidentialPardonForm----------" << std::endl;
	AForm* presidential;
	presidential = someRandomIntern.makeForm("presidential pardon", "Bender");
	bureaucrat.signForm(*presidential);
	bureaucrat.executeForm(*presidential);
	delete presidential;

	std::cout << "\n----------formNameNotFound----------" << std::endl;
	AForm* formNameNotFound;
	formNameNotFound = someRandomIntern.makeForm("form name not found", "Bender");
	if (formNameNotFound)
		delete formNameNotFound;

	return 0;
}