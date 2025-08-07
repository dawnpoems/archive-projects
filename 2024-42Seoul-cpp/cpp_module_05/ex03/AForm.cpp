#include "AForm.hpp"

AForm::AForm() : name("default"), sign(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const &form) : name(form.name), sign(form.sign), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute)
{
}

AForm &AForm::operator=(AForm const &form)
{
	if (this == &form)
		return *this;
	sign = form.sign;
	return *this;
}

AForm::~AForm()
{
}

std::string const &AForm::getName() const
{
	return name;
}

bool AForm::isSigned() const
{
	return sign;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	sign = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!sign)
		throw FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed";
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.isSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
	return out;
}