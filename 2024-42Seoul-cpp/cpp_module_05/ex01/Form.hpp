#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
	std::string const name;
	bool sign;
	int const gradeToSign;
	int const gradeToExecute;

public:
	Form();
	Form(std::string const &name, int gradeToSign, int gradeToExecute);
	Form(Form const &form);
	Form &operator=(Form const &form);
	~Form();

	std::string const &getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat const &bureaucrat);

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

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif // FORM_HPP