#ifndef	FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <Bureaucrat.hpp>

class Bureaucrat;

class Form  {
	private:
		const std::string	name;
		bool				isSigned;
		const int			sign;
		const int			exec;
	public:
		Form();
		Form(std::string name, int signReq, int execReq);
		~Form();
		Form(const Form &other);
		
		Form& operator=(const Form &other);
		
		const std::string	getName() const;
		bool				getIfSigned() const;
		int					getSign() const;
		int 				getExec() const;
		
		void				beSigned(Bureaucrat &author);

		class GradeTooHighException : public std::exception {
    		public:
        		const char *what() const noexcept;
    	};

    	class GradeTooLowException : public std::exception {
    		public:
        		const char *what() const noexcept;
    	};
};

std::ostream &operator<<(std::ostream &str, Form &ref);

#endif