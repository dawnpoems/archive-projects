#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& src) {
  *this = src;
}

Intern& Intern::operator=(const Intern& src) {
  (void)src;
  return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string formName, std::string target) {
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	AForm* (Intern::*formCreators[3])(std::string target) = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	for (int i = 0; i < 3; i++) {
		if (formNames[i] == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formCreators[i])(target);
		}
	}
	std::cout << "Form name not found" << std::endl;
	return NULL;
}

AForm* Intern::createShrubberyCreationForm(std::string target) {
  return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string target) {
  return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
  return new PresidentialPardonForm(target);
}