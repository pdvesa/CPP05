#include <AForm.hpp>

AForm::AForm(): name("default"), isSigned(false), sign(42), exec(42) {
}

AForm::AForm(std::string nimi, int signReq, int execReq): name(nimi), isSigned(false), sign(signReq), exec(execReq) {
	if (sign > 150 || exec > 150)
		throw GradeTooLowException();
	if (sign < 1 || exec < 1)
		throw GradeTooHighException();
}

AForm::~AForm() {
}

AForm::AForm(const AForm &other): name(other.name), isSigned(other.isSigned), sign(other.sign), exec(other.exec) {
}

AForm& AForm::operator=(const AForm &other) {
	isSigned = other.isSigned;
		return (*this);
}

const std::string	AForm::getName() const {
	return (name);
}

bool	AForm::getIfSigned() const {
	return (isSigned);
}

int		AForm::getSign() const {
	return (sign);
}

int		AForm::getExec() const {
	return (exec);
}

void	AForm::beSigned(Bureaucrat &author) {
	if (author.getGrade() <= sign)
		isSigned = true;
	else
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const noexcept {
	return ("Grade too high in AForm!");
}

const char *AForm::GradeTooLowException::what() const noexcept {
	return ("Grade too low in AForm!");
}

std::ostream &operator<<(std::ostream &str, AForm &ref) {
	str << "AForm: " << ref.getName() << "\nSigned: " << ref.getIfSigned() << "\nRequired sign power: " << ref.getSign() << "\nRequired exec power: " << ref.getExec() << std::endl;
	return (str);
}