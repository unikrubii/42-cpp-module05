#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		try
		{
			Form a1;
			Form a2("F2", 10, 21);
			Form a3("F3", 159, 19);
		}
		catch( const std::exception &e )
		{
			std::cerr << e.what() << std::endl;
		}

	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		try
		{
			Bureaucrat b("B1", 15);
			Form f1("F1", 20, 20);
			b.signForm( f1 );

			Form f2("F2", 10, 10);
			b.signForm( f2 );

			Form f3("F3", 20, 10);
			b.signForm( f3 );
		}
		catch( const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return (0);
}