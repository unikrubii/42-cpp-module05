#include "ShrubberyCreationForm.hpp"

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm( void ): AForm("ShrubberyCreationForm_Default", 145, 137), _target("None") {
	// std::cout << "ShrubberyCreationForm name: \'" << this->getName() << "\' signedGrade: " << std::to_string( this->getSignedGrade() ) << " execGrade: " << std::to_string( this->getExecGrade() ) << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src ): AForm(src), _target(src._target) {
	// std::cout << "ShrubberyCreationForm name: \'" << this->getName() << "\' signedGrade: " << std::to_string( this->getSignedGrade() ) << " execGrade: " << std::to_string( this->getExecGrade() ) << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target ): AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	// std::cout << "ShrubberyCreationForm name: \'" << this->getName() << "\' signedGrade: " << std::to_string( this->getSignedGrade() ) << " execGrade: " << std::to_string( this->getExecGrade() ) << std::endl;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
}

// assigned operator overload
ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm &rhs ) {
	if ( this == &rhs ) {
		return *this;
	}

	this->_target = rhs._target;
	return *this;
}

// Methods
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	// validate grade
	if ( executor.getGrade() > this->getExecGrade() ) {
		throw( ShrubberyCreationForm::GradeTooLowException() );
	}
	if ( executor.getGrade() < 1 ) {
		throw( ShrubberyCreationForm::GradeTooHighException() );
	}

	// validate form
	if ( this->isSigned() == false ) {
		throw( ShrubberyCreationForm::FormNotSignedException() );
	}

	std::ofstream ofs(this->_target + "_shrubbery");
	if ( !ofs.is_open() ) {
		throw( ShrubberyCreationForm::FileOpenedException() );
	}

	std::cout << "Bureaucrat: " << executor.getName() << " executed " << this->getName() << std::endl << std::endl;
	std::cout << "    Check the file: " << this->_target << "_shrubbery" << std::endl;

	ofs << "      /\\\n";
	ofs << "     /\\*\\\n";
	ofs << "    /\\O\\*\\\n";
	ofs << "   /*/\\/\\/\\\n";
	ofs << "  /\\O\\/\\*\\/\\\n";
	ofs << " /\\*\\/\\*\\/\\/\\\n";
	ofs << "/\\O\\/\\/*/\\/O/\\\n";
	ofs << "      ||\n";
	ofs << "      ||\n";
	ofs << "      ||\n";
	ofs << std::endl;
	ofs.close();
}
