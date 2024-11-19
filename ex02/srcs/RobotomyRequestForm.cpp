#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm(std::string trgt): AForm("RobotomyRequestForm", 72, 45) {
	target = trgt;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other) {
	target = other.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	target = other.target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getIfSigned())
		throw std::runtime_error("Form not signed!");
	if (executor.getGrade() <= getExec()) {
		std:: cout << "BRRRRRRRRT NRRRRTRTARAFASDA BRRRRRRRRRRT" << std::endl;
		srand(time(NULL));
		if (rand() % 2)
			std::cout << target << " has been robotomized" << std::endl;
		else
			std::cout << target << " passed away in attempt to be robotomized" << std::endl;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}
