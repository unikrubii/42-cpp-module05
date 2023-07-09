#include "AForm.hpp"

// Constructor
AForm::AForm( void ): _name( "DEFAULT" ), _isSign( false ), _signedGrade( 1 ), _execGrade( 1 ) {
	std::cout << "AForm name: \'" << this->getName() << "\' signedGrade: " << std::to_string( this->getSignedGrade() ) << " execGrade: " << std::to_string( this->getExecGrade() ) << std::endl;

}

AForm::AForm( const AForm &src ): _name( src._name + "_Copy" ), _isSign( src._isSign ), _signedGrade( src._signedGrade ), _execGrade( src._execGrade ) {
	AForm::checkGrade( src._signedGrade, src._execGrade );
	std::cout << "AForm name: \'" << this->getName() << "\' signedGrade: " << std::to_string( this->getSignedGrade() ) << " execGrade: " << std::to_string( this->getExecGrade() ) << std::endl;
}

AForm::AForm( const std::string &name, int signedGrade, int execGrade ): _name( name ), _isSign( false ), _signedGrade( signedGrade ), _execGrade( execGrade ) {
	AForm::checkGrade( signedGrade, execGrade );
	std::cout << "AForm name: \'" << this->getName() << "\' signedGrade: " << std::to_string( this->getSignedGrade() ) << " execGrade: " << std::to_string( this->getExecGrade() ) << std::endl;
}

// assigned operator overload
AForm	&AForm::operator=( const AForm &rhs ) {
	if ( this == &rhs ) {
		return *this;
	}

	this->_isSign = rhs._isSign;
	return *this;
}

// Getters
bool AForm::isSigned( void ) const {
	return this->_isSign;
}

int AForm::getSignedGrade( void ) const {
	return this->_signedGrade;
}

int AForm::getExecGrade( void ) const {
	return this->_execGrade;
}

const std::string &AForm::getName( void ) const {
	return this->_name;
}

// Methods
void AForm::beSigned( const Bureaucrat &b ) {
	// validate grade
	if ( b.getGrade() > this->_signedGrade ) {
		throw( Bureaucrat::GradeTooLowException() );
	}
	if ( b.getGrade() < 1 ) {
		throw( Bureaucrat::GradeTooHighException() );
	}

	// validate form
	if ( this->isSigned() == false ) {
		this->_isSign = true;
		std::cout << "Bureaucrat: \"" << b.getName() << " signed Form: " << this->_name << std::endl;
	} else {
		std::cout << "Bureaucrat: \"" << b.getName() << " couldn't signed Form: " << this->_name << " because: Form is already signed" << std::endl;
	}
}

void AForm::checkGrade( int signedGrade, int execGrade ) {
	if ( signedGrade < 1 || execGrade < 1 ) {
		throw( AForm::GradeTooHighException() );
	} else if ( signedGrade > 150 || execGrade > 150 ) {
		throw( AForm::GradeTooLowException() );
	}
}

// exceptions
const char *AForm::GradeTooHighException::what( void ) const throw() {
	return "Grade too high!!";
}

const char *AForm::GradeTooLowException::what( void ) const throw() {
	return "Grade too low!!";
}

const char *AForm::FormNotSignedException::what( void ) const throw() {
	return "Form not signed!!";
}

const char *AForm::FileOpenedException::what( void ) const throw() {
	return "File open error!!";
}

// ostream overload
std::ostream &operator<<( std::ostream &out, const AForm &f ) {
	out << "Form:        " << f.getName() << std::endl;
	out << "isSigned:    " << f.isSigned() << std::endl;
	out << "signedGrade: " << std::to_string( f.getSignedGrade() ) << std::endl;
	out << "execGrade:   " << std::to_string( f.getExecGrade() ) << std::endl;
	return out;
}