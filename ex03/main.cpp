#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main (void) {
	{
		Bureaucrat b( "B1", 20 );
		AForm *form;
		intern intern;
		try {
			form = intern.makeForm( "shrubbery creation", "home" );
			std::cout << *form << std::endl;
			std::cout << "=== SIGN FORM ===" << std::endl;
			b.signForm( *form );
			std::cout << "=== EXECUTE FORM ===" << std::endl;
			b.executeForm( *form );
		}
		catch ( std::exception &e ) {
			std::cout << e.what() << std::endl;
		}
		delete form;
	}
	std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
	{
		Bureaucrat b( "B1", 20 );
		AForm *form;
		intern intern;
		try {
			form = intern.makeForm( "robotomy request", "Bender" );
			std::cout << *form << std::endl;
			std::cout << "=== SIGN FORM ===" << std::endl;
			b.signForm( *form );
			std::cout << "=== EXECUTE FORM ===" << std::endl;
			b.executeForm( *form );
		}
		catch ( std::exception &e ) {
			std::cout << e.what() << std::endl;
		}
		delete form;
	}
	std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
	{
		Bureaucrat b( "B1", 1 );
		AForm *form;
		intern intern;
		try {
			form = intern.makeForm( "presidential pardon", "Pentagon" );
			std::cout << *form << std::endl;
			std::cout << "=== SIGN FORM ===" << std::endl;
			b.signForm( *form );
			std::cout << "=== EXECUTE FORM ===" << std::endl;
			b.executeForm( *form );
		}
		catch ( std::exception &e ) {
			std::cout << e.what() << std::endl;
		}
		delete form;
	}
	std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
	{
		Bureaucrat b( "B1", 1 );
		AForm *form;
		intern intern;
		try {
			form = intern.makeForm( "some dummy form", "Random" );
			std::cout << *form << std::endl;
			std::cout << "=== SIGN FORM ===" << std::endl;
			b.signForm( *form );
			std::cout << "=== EXECUTE FORM ===" << std::endl;
			b.executeForm( *form );
		}
		catch ( std::exception &e ) {
			std::cout << e.what() << std::endl;
		}
	}
}