#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	// exceptions
	public:
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	protected:
		std::string	_name;
		int			_grade;

	public:
		Bureaucrat( void );
		Bureaucrat( const Bureaucrat &src );
		Bureaucrat( int grade );
		Bureaucrat( const std::string, int grade );
		~Bureaucrat( void );

		// operator overload
		Bureaucrat	&operator=( const Bureaucrat &rhs );

		// getters
		const std::string	&getName( void ) const;
		int					getGrade( void ) const;

		// setters
		void	setGrade( int grade );

		// Member Functions
		void	incrementGrade( void );
		void	decrementGrade( void );
		void	signForm( AForm &Aform ) const;
		void	executeForm( AForm const & form );
};

// ostream overload
std::ostream	&operator<<( std::ostream &o, Bureaucrat *b );

#endif
