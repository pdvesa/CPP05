#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm(std::string trgt): AForm("PresidentialPardonForm", 25, 5) {
	target = trgt;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other) {
	target = other.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	target = other.target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getIfSigned())
		throw std::runtime_error("Form not signed!");
	if (executor.getGrade() <= getExec())
		std:: cout<< target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else
		throw Bureaucrat::GradeTooLowException();
}
