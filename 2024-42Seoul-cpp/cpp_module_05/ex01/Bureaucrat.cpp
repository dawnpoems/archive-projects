#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat) : name(bureaucrat.name), grade(bureaucrat.grade)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
	if (this == &bureaucrat)
		return *this;
	this->grade = bureaucrat.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string const &Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
		std::cout << this->name << " signs " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}
