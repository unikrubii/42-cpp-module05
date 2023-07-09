#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string	_name;
		bool		_isSign;
		int			_signedGrade;
		int			_execGrade;

		// Member Functions
		void	checkGrade( int signedGrade, int execGrade );

	public:
		// Constructor
		Form( void );
		Form( const Form &src );
		Form( const std::string &name, int signedGrade, int execGrade );

		// assigned operator overload
		Form	&operator=( const Form &rhs );

		// Destructor
		~Form( void ) {};

		// Getters
		bool				isSigned() const;
		int					getSignedGrade() const;
		int					getExecGrade() const;
		const std::string	&getName() const;

		// Member Functions
		void	beSigned( const Bureaucrat &b );

		// exceptions
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
		
};

// ostream overload
std::ostream	&operator<<( std::ostream &o, Form &f );

#endif