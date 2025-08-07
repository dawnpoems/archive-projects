#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form form1("form1", 150, 100);
	std::cout << form1 << std::endl;
	try
	{
		Form form2("form2", 0, 100);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form form3("form3", 151, 100);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
		try
	{
		Form form4("form4", 100, 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form form5("form5", 100, 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat bureaucrat("bureaucrat", 1);
	Form form("form", 1, 1);

	bureaucrat.signForm(form);
	bureaucrat.decrementGrade();
	bureaucrat.signForm(form);

	return 0;
}