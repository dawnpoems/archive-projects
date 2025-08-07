#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm) : AForm(robotomyRequestForm), target(robotomyRequestForm.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &robotomyRequestForm)
{
	if (this == &robotomyRequestForm)
		return *this;
	AForm::operator=(robotomyRequestForm);
	target = robotomyRequestForm.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << "*drilling noises* ";
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << target << " robotomization failed" << std::endl;
}