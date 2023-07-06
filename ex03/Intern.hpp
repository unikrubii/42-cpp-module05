#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class intern
{
	public:
		// Constructor
		intern( void );
		intern( const intern &src );

		// Destructor
		~intern( void ) {};

		// assigned operator overload
		intern	&operator=( const intern &rhs );

		// Member Functions
		AForm	*makeForm( const std::string &formName, const std::string &target );

		// Exceptions
		class FormNotFoundException: public std::exception {
			public:
				virtual const char	*what( void ) const throw();
		};
};

#endif