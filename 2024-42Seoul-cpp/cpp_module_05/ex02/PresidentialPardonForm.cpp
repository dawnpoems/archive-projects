#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm) : AForm(presidentialPardonForm), target(presidentialPardonForm.target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &presidentialPardonForm)
{
	if (this == &presidentialPardonForm)
		return *this;
	AForm::operator=(presidentialPardonForm);
	target = presidentialPardonForm.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}