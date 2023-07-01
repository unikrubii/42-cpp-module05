#include "form.hpp"

// Constructor
Form::Form( void ): _name( "DEFAULT" ), _signedGrade( 1 ), _execGrade( 1 ), _isSign( false ) {

}

Form::Form( const Form &src ): _name( src._name + "_Copy" ), _signedGrade( src._signedGrade ), _execGrade( src._execGrade ), _isSign( src._isSign ) {
	checkGrade( src._signedGrade, src._execGrade );
	*this = src;
}

Form::Form( std::string name, int signedGrade, int execGrade ): _name( name ), _signedGrade( signedGrade ), _execGrade( execGrade ), _isSign( false ) {
	checkGrade( this->_signedGrade, this->_execGrade );
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
bool Form::getSignedStatus( void ) {
	return this->_isSign;
}

const int Form::getExecGrade( void ) {
	return this->_signedGrade;
}

const int Form::getExecGrade( void ) {
	return this->_execGrade;
}

// Methods
void Form::beSigned( Bureaucrat &b ) {
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

void checkGrade( const int signedGrade, const int execGrade ) {
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

