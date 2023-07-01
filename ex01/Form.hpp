#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Beruaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSign;
		const int			_signedGrade;
		const int			_execGrade;

	public:
		// Constructor
		Form( void );
		Form( const Form &src );
		Form( std::string name, int signedGrade, int execGrade );

		// assigned operator overload
		Form	&operator=( const Form &rhs );

		// Destructor
		~Form( void ) {};

		// Getters
		bool	getSignedStatus();
		const int		getSignedGrade();
		const int		getExecGrade();

		// Member Functions
		void	beSigned( Bureaucrat &b );
		void	checkGrade( const int signedGrade, const int execGrade );

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
std::ostream	&operator<<( std::ostream &o, Form *f );

#endif