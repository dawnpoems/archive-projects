#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat bureaucrat("bureaucrat", 1);

	std::cout << "----------shrubberyCreationForm----------" << std::endl;
	ShrubberyCreationForm shrubberyCreationForm("shrubberyCreationForm");	
	bureaucrat.signForm(shrubberyCreationForm);
	bureaucrat.executeForm(shrubberyCreationForm);


	std::cout << "----------robotomyRequestForm----------" << std::endl;
	RobotomyRequestForm robotomyRequestForm("robotomyRequestForm");
	bureaucrat.signForm(robotomyRequestForm);
	bureaucrat.executeForm(robotomyRequestForm);

	std::cout << "----------presidentialPardonForm----------" << std::endl;
	PresidentialPardonForm presidentialPardonForm("presidentialPardonForm");
	bureaucrat.signForm(presidentialPardonForm);
	bureaucrat.executeForm(presidentialPardonForm);

	return 0;
}