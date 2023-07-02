#include "Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat( void ) {
	this->_name = "DEFAULT";
	this->setGrade( rand() % 150 );
	std::cout << "Default Bureaucrat is create with random grade: " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &src ) {
	*this = src;
	std::cout << "Bureaucrat name: " << this->getName() << " is create with random grade: " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat( int grade ) {
	this->_name = "DEFAULT";
	this->setGrade( grade );
	std::cout << "Default Bureaucrat is create with grade: " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) {
	this->_name = name;
	this->setGrade( grade );
	std::cout << "Bureaucrat name: \'" << this->getName() << "\' is create with random grade: " << this->_grade << std::endl;
}

// Exceptions
const char *Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return "Grade Too High!";
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return "Grade Too Low!";
}

// Operator overload
Bureaucrat &Bureaucrat::operator=( const Bureaucrat &rhs ) {
	if ( this == &rhs ) {
		return *this;
	}

	this->_grade = rhs.getGrade();
	return *this;
}

// Getters
int Bureaucrat::getGrade( void ) const {
	return _grade;
}

const std::string &Bureaucrat::getName( void ) const {
	return _name;
}

// Setter
void	Bureaucrat::setGrade( int grade ) {
	if ( grade > 150 ) {
		throw Bureaucrat::GradeTooLowException();
	} else if ( grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade = grade;
}

// Implemented methods
void Bureaucrat::incrementGrade( void ) {
	this->setGrade( this->_grade - 1);
}

void Bureaucrat::decrementGrade( void ) {
	this->setGrade( this->_grade + 1);
}

void Bureaucrat::signForm( Form &form ) {
	form.beSigned( *this );
}

// Ostream overload
std::ostream &operator<<( std::ostream &o, Bureaucrat *b ) {
	o << b->getName() << ", Bureaucat grade " << b->getGrade() << std::endl;
	return o;
}
