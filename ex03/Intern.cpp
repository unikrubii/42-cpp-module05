#include "Intern.hpp"

// Constructor
intern::intern( void ) {}

intern::intern( const intern &src ) {
	*this = src;
}

// assigned operator overload
intern	&intern::operator=( const intern &rhs ) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

// Member Functions
AForm	*intern::makeForm( const std::string &formName, const std::string &target ) {
	std::string formList[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };

	for (int i = 0; i < 3; i++) {
		if ( formName == formList[i] ) {
			std::cout << "Intern creates " << formName << std::endl;
			switch (i) {
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
			}
		}
	}
	throw AForm::FormNotFoundException();
}

