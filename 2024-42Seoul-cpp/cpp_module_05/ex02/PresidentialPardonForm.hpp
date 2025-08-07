#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
	PresidentialPardonForm();

public:
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &presidentialPardonForm);
	~PresidentialPardonForm();

	void execute(Bureaucrat const &executor) const;
};

#endif // PRESIDENTIALPARDONFORM_HPP