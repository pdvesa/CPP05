#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <AForm.hpp>

class AForm;

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		
		Bureaucrat &operator=(const Bureaucrat &other);
		
		const std::string 	getName() const;
		int 				getGrade() const;
		
		void	incrementGrade();
		void	decrementGrade();

		void	signForm(AForm &form);
		void	executeForm(AForm const &form);
		
    	class GradeTooHighException : public std::exception {
    		public:
        		const char *what() const noexcept;
    	};

    	class GradeTooLowException : public std::exception {
    		public:
        		const char *what() const noexcept;
    	};

};

std::ostream &operator<<(std::ostream &str, Bureaucrat &ref);

#endif