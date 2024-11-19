#ifndef	AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <Bureaucrat.hpp>

class Bureaucrat;

class AForm  {
	private:
		const std::string	name;
		bool				isSigned;
		const int			sign;
		const int			exec;
	public:
		AForm();
		AForm(std::string name, int signReq, int execReq);
		virtual ~AForm();
		AForm(const AForm &other);
		
		AForm &operator=(const AForm &other);
		
		const std::string	getName() const;
		bool				getIfSigned() const;
		int					getSign() const;
		int 				getExec() const;
		
		void				beSigned(Bureaucrat &author);
		virtual void		execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception {
    		public:
        		const char *what() const noexcept;
    	};

    	class GradeTooLowException : public std::exception {
    		public:
        		const char *what() const noexcept;
    	};
};

std::ostream &operator<<(std::ostream &str, AForm &ref);

#endif