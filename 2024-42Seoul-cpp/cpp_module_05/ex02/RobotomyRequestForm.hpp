#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
	RobotomyRequestForm();

public:
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &robotomyRequestForm);
	~RobotomyRequestForm();

	void execute(Bureaucrat const &executor) const;
};

#endif // ROBOTOMYREQUESTFORM_HPP