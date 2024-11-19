#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>

int main(void) {
    // Create Bureaucrats with different grades
    Bureaucrat bob("Bob", 150);  // Grade 150
    Bureaucrat marley("Marley", 20);  // Grade 20

    // Create forms
    ShrubberyCreationForm shrub("trash");
    PresidentialPardonForm pardon("monke");
    RobotomyRequestForm robotomy("chatGPT");

    // Test all combinations for ShrubberyCreationForm
    std::cout << "==== Testing ShrubberyCreationForm ====\n" << std::endl;
    
    // Bob tries to sign and execute
    std::cout << "Bob signing and executing form: ShrubberyCreationForm" << std::endl;
    bob.signForm(shrub);
    bob.executeForm(shrub);

    // Marley tries to sign and execute
    std::cout << "Marley signing and executing form: ShrubberyCreationForm" << std::endl;
    marley.signForm(shrub);
    marley.executeForm(shrub);

    // Test all combinations for PresidentialPardonForm
    std::cout << "\n==== Testing PresidentialPardonForm ====\n" << std::endl;

    // Bob tries to sign and execute
    std::cout << "Bob signing and executing form: PresidentialPardonForm" << std::endl;
    bob.signForm(pardon);
    bob.executeForm(pardon);

    // Marley tries to sign and execute
    std::cout << "Marley signing and executing form: PresidentialPardonForm" << std::endl;
    marley.signForm(pardon);
    marley.executeForm(pardon);

    // Test all combinations for RobotomyRequestForm
    std::cout << "\n==== Testing RobotomyRequestForm ====\n" << std::endl;

    // Bob tries to sign and execute
    std::cout << "Bob signing and executing form: RobotomyRequestForm" << std::endl;
    bob.signForm(robotomy);
    bob.executeForm(robotomy);

    // Marley tries to sign and execute
    std::cout << "Marley signing and executing form: RobotomyRequestForm" << std::endl;
    marley.signForm(robotomy);
    marley.executeForm(robotomy);

	// Trying to execute already signed
	Bureaucrat	test("Sn_Tester", 40);
	test.executeForm(robotomy);

    return (0);
} //courtesy of gepete