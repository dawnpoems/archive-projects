#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
private:
  AForm* createShrubberyCreationForm(std::string target);
  AForm* createRobotomyRequestForm(std::string target);
  AForm* createPresidentialPardonForm(std::string target);

public:
  Intern();
  Intern(const Intern& src);
  Intern& operator=(const Intern& src);
  ~Intern();

  AForm* makeForm(std::string formName, std::string target);
};

#endif  // INTERN_HPP