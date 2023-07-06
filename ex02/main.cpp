#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main (void) {
	{
		Bureaucrat b1( "B1", 20 );
		ShrubberyCreationForm f1( "f1" );
		std::cout << f1 << std::endl;
		try {
			std::cout << "=== EXECUTE FORM ===" << std::endl;
			b1.signForm( f1 );
			std::cout << "=== SIGN FORM ===" << std::endl;
			b1.executeForm( f1 );
		} catch ( std::exception &e ) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "---------------------" << std::endl << std::endl;
	{
		Bureaucrat b1( "b1", 140 );
		ShrubberyCreationForm f2( "f2" );
		std::cout << f2 << std::endl;
		try {
			std::cout << "=== SIGN FORM ===" << std::endl;
			b1.signForm( f2 );
			std::cout << "=== EXECUTE FORM ===" << std::endl;
			b1.executeForm( f2 );
		} catch ( std::exception &e ) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "---------------------" << std::endl << std::endl;
	{
		Bureaucrat b1( "b1", 100 );
		ShrubberyCreationForm f3( "f3" );
		std::cout << f3 << std::endl;
		try {
			std::cout << "=== EXECUTE FORM ===" << std::endl;
			b1.executeForm( f3 );
			std::cout << "=== SIGN FORM ===" << std::endl;
			b1.signForm( f3 );
		} catch ( std::exception &e ) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "---------------------" << std::endl << std::endl;
	{
		Bureaucrat b1( "b1", 140 );
		ShrubberyCreationForm f4( "f4" );
		std::cout << f4 << std::endl;
		try {
			std::cout << "=== EXECUTE FORM ===" << std::endl;
			b1.executeForm( f4 );
			std::cout << "=== SIGN FORM ===" << std::endl;
			b1.signForm( f4 );
		} catch ( std::exception &e ) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "---------------------" << std::endl << std::endl;
	{
		Bureaucrat b1( "b1", 10 );
		RobotomyRequestForm r1( "r1" );
		std::cout << r1 << std::endl;
		try {
			std::cout << "=== SIGN FORM ===" << std::endl;
			b1.signForm( r1 );
			std::cout << "=== EXECUTE FORM ===" << std::endl;
			b1.executeForm( r1 );
		} catch ( std::exception &e ) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "---------------------" << std::endl << std::endl;
	{
		Bureaucrat b1( "b1", 10 );
		PresidentialPardonForm p1( "p1" );
		std::cout << p1 << std::endl;
		try {
			std::cout << "=== SIGN FORM ===" << std::endl;
			b1.signForm( p1 );
			std::cout << "=== EXECUTE FORM ===" << std::endl;
			b1.executeForm( p1 );
		} catch ( std::exception &e ) {
			std::cout << e.what() << std::endl;
		}
	}
}