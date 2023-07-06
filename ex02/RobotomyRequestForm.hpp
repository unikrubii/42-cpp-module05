#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	public:
		// Constructor
		RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm &src );
		RobotomyRequestForm( const std::string &target );

		// Destructor
		~RobotomyRequestForm( void ) {};

		// assigned operator overload
		RobotomyRequestForm	&operator=( const RobotomyRequestForm &rhs );

		// Member Functions
		void	execute(Bureaucrat const &executor) const;

	private:
		std::string	_target;
};

// ostream overload
std::ostream	&operator<<( std::ostream &out, const RobotomyRequestForm &f );

#endif