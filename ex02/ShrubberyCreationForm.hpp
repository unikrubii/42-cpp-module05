#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
	public:
		// Constructor
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm &src );
		ShrubberyCreationForm( const std::string &target );

		// Destructor
		~ShrubberyCreationForm( void ) {};

		// assigned operator overload
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &rhs );

		// Member Functions
		void	execute(Bureaucrat const &executor) const;

	private:
		std::string	_target;
};

// ostream overload
std::ostream	&operator<<( std::ostream &out, const ShrubberyCreationForm &f );

#endif