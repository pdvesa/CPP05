#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(): name("Unknown"), grade(42) {
};

Bureaucrat::Bureaucrat(const std::string &nimi, int luokka) : name(nimi) {
	if (luokka > 150)
		throw GradeTooLowException();
	if (luokka < 1)
		throw GradeTooHighException();
	grade = luokka;
};


Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade) {
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		grade = other.grade;
	}
	return (*this);
}

const std::string Bureaucrat::getName() const {
	return (name);
}

int32_t Bureaucrat::getGrade() const {
	return (grade);
}

void	Bureaucrat::incrementGrade() {
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade -= 1;
}

void	Bureaucrat::decrementGrade() {
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade += 1;
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return ("Grade too low :(");
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return ("Grade too high :(");
}

std::ostream& operator<<(std::ostream& str, Bureaucrat& ref) {
	str << ref.getName() << ", bureaucrat grade " << + ref.getGrade();
	return (str);
}
