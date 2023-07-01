#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cstdlib>

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
		Bureaucrat( int grade );
		Bureaucrat( const std::string, int grade );
		~Bureaucrat( void ) {};

		// operator overload
		Bureaucrat	&operator=( const Bureaucrat &rhs );

		// getters
		std::string	getName( void );
		int			getGrade( void );

		// setters
		void		setGrade( int grade );

		void		incrementGrade( void );
		void		decrementGrade( void );
};

// ostream overload
std::ostream	&operator<<( std::ostream &o, Bureaucrat *b );

#endif
