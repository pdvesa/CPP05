#ifndef INTERN_HPP
#define INTERN_HPP

#include <AForm.hpp>

class Intern {
	private:
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
	public:
		Intern();
		~Intern();

		AForm *makeForm(std::string name, std::string target);
};

#endif