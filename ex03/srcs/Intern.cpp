#include <Intern.hpp>
#include <PresidentialPardonForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>

Intern::Intern() {
}

Intern::~Intern() {
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string names[3] { "Shrubbery creation", "Robotomy request", "Presidential pardon"};
	for (int i = 0; i < 3; i++) {
		if (name == names[i]) {
			std::cout << "Intern creates " << name << " form" << std::endl;
			switch (i) {
				case 0:
					return (new ShrubberyCreationForm(target));
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new PresidentialPardonForm(target));
			}
		}
	}
	std::cout << "No match for the form in question, possible forms currently :\n";
	for (auto name : names)
		std::cout << "\t" << name << std::endl;
	return (nullptr);
}