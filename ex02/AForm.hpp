#ifndef AFORM_HPP
# define AFORM_HPP

# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
		AForm( void );
		AForm( const AForm &src );
		AForm( const std::string &name, int signedGrade, int execGrade );

		// assigned operator overload
		AForm	&operator=( const AForm &rhs );

		// Destructor
		virtual ~AForm( void ) {};

		// Getters
		bool			isSigned() const;
		int				getSignedGrade() const;
		int				getExecGrade() const;
		const	std::string	&getName() const;

		// Member Functions
		void			beSigned( const Bureaucrat &b );
		virtual void	execute( Bureaucrat const &executor ) const = 0;

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

		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FileOpenedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

// ostream overload
std::ostream	&operator<<( std::ostream &o, const AForm *f );

#endif