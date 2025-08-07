#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
private:
	std::string const name;
	bool sign;
	int const gradeToSign;
	int const gradeToExecute;

public:
	AForm();
	AForm(std::string const &name, int gradeToSign, int gradeToExecute);
	AForm(AForm const &form);
	AForm &operator=(AForm const &form);
	virtual ~AForm();

	std::string const &getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat const &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const;
	
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif // FORM_HPP