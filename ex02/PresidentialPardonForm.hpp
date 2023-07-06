#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	public:
		// Constructor
		PresidentialPardonForm( void );
		PresidentialPardonForm( const PresidentialPardonForm &src );
		PresidentialPardonForm( const std::string &target );

		// Destructor
		~PresidentialPardonForm( void ) {};

		// assigned operator overload
		PresidentialPardonForm	&operator=( const PresidentialPardonForm &rhs );

		// Member Functions
		void	execute(Bureaucrat const &executor) const;

	private:
		std::string	_target;
};

// ostream overload
std::ostream	&operator<<( std::ostream &out, const PresidentialPardonForm &f );

#endif