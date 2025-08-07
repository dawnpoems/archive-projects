#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string target;
	ShrubberyCreationForm();

public:
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &shrubberyCreationForm);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &shrubberyCreationForm);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const &executor) const;

};

#endif // SHRUBBERYCREATIONFORM_HPP