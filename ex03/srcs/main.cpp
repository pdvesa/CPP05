#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <Intern.hpp>

int main() {
    // Creating an Intern
    Intern someRandomIntern;

    // Creating Bureaucrats
    Bureaucrat highRankBureaucrat("HighRank", 1);  // Very high-ranked bureaucrat (can sign anything)
    Bureaucrat lowRankBureaucrat("LowRank", 150);  // Very low-ranked bureaucrat (probably can't sign anything)

    // Intern is asked to make different forms
    AForm *form1 = someRandomIntern.makeForm("Shrubbery creation", "Home");
    AForm *form2 = someRandomIntern.makeForm("Robotomy request", "Bender");
    AForm *form3 = someRandomIntern.makeForm("Presidential pardon", "John Doe");
    AForm *form4 = someRandomIntern.makeForm("Unknown form", "Test");  // This should fail and return nullptr

    // Checking if the forms were created successfully
    if (form1) {
        std::cout << "Form 1 created: " << form1->getName() << std::endl;
        highRankBureaucrat.signForm(*form1);
    }

    if (form2) {
        std::cout << "Form 2 created: " << form2->getName() << std::endl;
        lowRankBureaucrat.signForm(*form2);  // This might fail if the bureaucrat rank is too low
    }

    if (form3) {
        std::cout << "Form 3 created: " << form3->getName() << std::endl;
        highRankBureaucrat.signForm(*form3);
    }

	if (form4) {
		std::cout << "Somebody phucked up :()()" << std::endl;
	}

	highRankBureaucrat.executeForm(*form1);
	lowRankBureaucrat.executeForm(*form1);

    // Cleanup: delete allocated forms
    delete form1;
    delete form2;
    delete form3;

    return 0;
} //test main courtesy of gepete
