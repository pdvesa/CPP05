#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <AForm.hpp>

class	RobotomyRequestForm: public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);

		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		void	execute(Bureaucrat const &executor) const;
};

#endif