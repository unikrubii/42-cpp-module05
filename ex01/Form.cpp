#include "Form.hpp"

// Constructor
Form::Form( void ): _name( "DEFAULT" ), _isSign( false ), _signedGrade( 1 ), _execGrade( 1 ) {
	std::cout << "Form name: \'" << this->getName() << "\' signedGrade: " << std::to_string( this->getSignedGrade() ) << " execGrade: " << std::to_string( this->getExecGrade() ) << std::endl;

}

Form::Form( const Form &src ): _name( src._name + "_Copy" ), _isSign( src._isSign ), _signedGrade( src._signedGrade ), _execGrade( src._execGrade ) {
	Form::checkGrade( src._signedGrade, src._execGrade );
	std::cout << "Form name: \'" << this->getName() << "\' signedGrade: " << std::to_string( this->getSignedGrade() ) << " execGrade: " << std::to_string( this->getExecGrade() ) << std::endl;
}

Form::Form( const std::string &name, int signedGrade, int execGrade ): _name( name ), _isSign( false ), _signedGrade( signedGrade ), _execGrade( execGrade ) {
	Form::checkGrade( signedGrade, execGrade );
	std::cout << "Form name: \'" << this->getName() << "\' signedGrade: " << std::to_string( this->getSignedGrade() ) << " execGrade: " << std::to_string( this->getExecGrade() ) << std::endl;
}

// assigned operator overload
Form	&Form::operator=( const Form &rhs ) {
	if ( this == &rhs ) {
		return *this;
	}

	this->_isSign = rhs._isSign;
	return *this;
}

// Getters
bool Form::getSignedStatus( void ) const {
	return this->_isSign;
}

int Form::getSignedGrade( void ) const {
	return this->_signedGrade;
}

int Form::getExecGrade( void ) const {
	return this->_execGrade;
}

const std::string &Form::getName( void ) const {
	return this->_name;
}

// Methods
void Form::beSigned( const Bureaucrat &b ) {
	if ( b.getGrade() > this->_execGrade || b.getGrade() > this->_signedGrade ) {
		throw( Bureaucrat::GradeTooLowException() );
	}
	if ( this->getSignedStatus() == false ) {
		this->_isSign = true;
		std::cout << "Form \"" << this->_name << "\" is signed by " << b.getName() << std::endl;
	} else {
		std::cout << "Form \"" << this->_name << "\" is already signed" << std::endl;
	}
}

void Form::checkGrade( int signedGrade, int execGrade ) {
	if ( signedGrade < 1 || execGrade < 1 ) {
		throw( Form::GradeTooHighException() );
	} else if ( signedGrade > 150 || execGrade > 150 ) {
		throw( Form::GradeTooLowException() );
	}
}

// exceptions
const char *Form::GradeTooHighException::what( void ) const throw() {
	return "Grade too high!!";
}

const char *Form::GradeTooLowException::what( void ) const throw() {
	return "Grade too low!!";
}

// ostream overload

