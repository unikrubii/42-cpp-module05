#include "PresidentialPardonForm.hpp"

// Constructor
PresidentialPardonForm::PresidentialPardonForm( void ): AForm("PresidentialPardonForm_Default", 72, 45), _target("None") {
	// std::cout << "PresidentialPardonForm name: \'" << this->getName() << "\' signedGrade: " << std::to_string( this->getSignedGrade() ) << " execGrade: " << std::to_string( this->getExecGrade() ) << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src ): AForm(src), _target(src._target) {
	// std::cout << "PresidentialPardonForm name: \'" << this->getName() << "\' signedGrade: " << std::to_string( this->getSignedGrade() ) << " execGrade: " << std::to_string( this->getExecGrade() ) << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string &target ): AForm("PresidentialPardonForm", 72, 45), _target(target) {
	// std::cout << "PresidentialPardonForm name: \'" << this->getName() << "\' signedGrade: " << std::to_string( this->getSignedGrade() ) << " execGrade: " << std::to_string( this->getExecGrade() ) << std::endl;
}

// assigned operator overload
PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm &rhs ) {
	if ( this == &rhs ) {
		return *this;
	}

	this->_target = rhs._target;
	return *this;
}

// Methods
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	// validate grade
	if ( executor.getGrade() > this->getExecGrade() ) {
		throw( PresidentialPardonForm::GradeTooLowException() );
	}
	if ( executor.getGrade() < 1 ) {
		throw( PresidentialPardonForm::GradeTooHighException() );
	}

	// validate form
	if ( this->isSigned() == false ) {
		throw( PresidentialPardonForm::FormNotSignedException() );
	}

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
