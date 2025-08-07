#include "Form.hpp"

Form::Form() : name("default"), sign(false), gradeToSign(150), gradeToExecute(150)
{
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &form) : name(form.name), sign(form.sign), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute)
{
}

Form &Form::operator=(Form const &form)
{
	if (this == &form)
		return *this;
	sign = form.sign;
	return *this;
}

Form::~Form()
{
}

std::string const &Form::getName() const
{
	return name;
}

bool Form::isSigned() const
{
	return sign;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	sign = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *Form::FormNotSignedException::what() const throw()
{
	return "Form not signed";
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.isSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
	return out;
}