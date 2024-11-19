#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm(std::string trgt): AForm("ShrubberyCreationForm", 145, 137) {
	target = trgt;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other) {
	target = other.target;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	target = other.target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (!getIfSigned())
		throw std::runtime_error("Form not signed!");
	if (executor.getGrade() <= getExec()) {
		std::ofstream	outfile(target + "_shrubbery", std::ios::out);
		if (outfile.is_open())
		{
        	outfile << "       ^\n"
                	<< "      ^^^\n"
                	<< "     ^^^^^\n"
                	<< "    ^^^^^^^\n"
                	<< "   ^^^^^^^^^\n"
                	<< "  ^^^^^^^^^^^\n"
                	<< "      |||\n"
                	<< "      |||\n";
        	outfile.close();
    	} else 
        	throw std::runtime_error("Failed to open outfile");
	}
	else
		throw GradeTooLowException();
}
