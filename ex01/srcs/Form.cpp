#include <Form.hpp>

Form::Form(): name("default"), isSigned(false), sign(42), exec(42) {
}

Form::Form(std::string nimi, int signReq, int execReq): name(nimi), isSigned(false), sign(signReq), exec(execReq) {
	if (sign > 150 || exec > 150)
		throw GradeTooLowException();
	if (sign < 1 || exec < 1)
		throw GradeTooHighException();
}

Form::~Form() {
}

Form::Form(const Form &other): name(other.name), isSigned(other.isSigned), sign(other.sign), exec(other.exec) {
}

Form& Form::operator=(const Form &other) {
	isSigned = other.isSigned;
		return (*this);
}

const std::string	Form::getName() const {
	return (name);
}

bool	Form::getIfSigned() const {
	return (isSigned);
}

int		Form::getSign() const {
	return (sign);
}

int		Form::getExec() const {
	return (exec);
}

void	Form::beSigned(Bureaucrat &author) {
	if (author.getGrade() <= sign)
		isSigned = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const noexcept {
	return ("Grade too high in form!");
}

const char *Form::GradeTooLowException::what() const noexcept {
	return ("Grade too low in form!");
}

std::ostream &operator<<(std::ostream &str, Form &ref) {
	str << "Form: " << ref.getName() << "\nSigned: " << ref.getIfSigned() << "\nRequired sign power: " << ref.getSign() << "\nRequired exec power: " << ref.getExec() << std::endl;
	return (str);
}