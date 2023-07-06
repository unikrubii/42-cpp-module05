#include "RobotomyRequestForm.hpp"

// Constructor
RobotomyRequestForm::RobotomyRequestForm( void ): AForm("RobotomyRequestForm_Default", 72, 45), _target("None") {
	// std::cout << "RobotomyRequestForm name: \'" << this->getName() << "\' signedGrade: " << std::to_string( this->getSignedGrade() ) << " execGrade: " << std::to_string( this->getExecGrade() ) << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src ): AForm(src), _target(src._target) {
	// std::cout << "RobotomyRequestForm name: \'" << this->getName() << "\' signedGrade: " << std::to_string( this->getSignedGrade() ) << " execGrade: " << std::to_string( this->getExecGrade() ) << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string &target ): AForm("RobotomyRequestForm", 72, 45), _target(target) {
	// std::cout << "RobotomyRequestForm name: \'" << this->getName() << "\' signedGrade: " << std::to_string( this->getSignedGrade() ) << " execGrade: " << std::to_string( this->getExecGrade() ) << std::endl;
}

// assigned operator overload
RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm &rhs ) {
	if ( this == &rhs ) {
		return *this;
	}

	this->_target = rhs._target;
	return *this;
}

// Methods
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	// validate grade
	if ( executor.getGrade() > this->getExecGrade() ) {
		throw( RobotomyRequestForm::GradeTooLowException() );
	}
	if ( executor.getGrade() < 1) {
		throw( RobotomyRequestForm::GradeTooHighException() );
	}

	// validate form
	if ( this->isSigned() == false ) {
		throw( RobotomyRequestForm::FormNotSignedException() );
	}

	std::cout << this->_target << " has been robotomized by " << executor.getName() << std::endl;
	std::cout << "   ** drilling noises ***" << std::endl;
	srand(time(NULL));
	if ( rand() % 2 == 0 ) {
		std::cout << "     Result: Success!!" << std::endl;
	} else {
		std::cout << "     Result: Failed!!" << std::endl;
	}
}
