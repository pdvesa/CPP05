#include <Bureaucrat.hpp>

int main() {
    try {
        // Valid bureaucrat
        Bureaucrat validBureaucrat("Alice", 100);
        std::cout << "Created bureaucrat: " << validBureaucrat.getName() 
                  << " with grade " << validBureaucrat.getGrade() << std::endl;

        // Test incrementing grade
        validBureaucrat.incrementGrade();
        std::cout << "After incrementing, " << validBureaucrat.getName() 
                  << " now has grade " << validBureaucrat.getGrade() << std::endl;

        // Test decrementing grade
        validBureaucrat.decrementGrade();
        validBureaucrat.decrementGrade(); // Decrementing twice
        std::cout << "After decrementing twice, " << validBureaucrat.getName() 
                  << " now has grade " << validBureaucrat.getGrade() << std::endl;

        // Bureaucrat with too low grade
        Bureaucrat lowGradeBureaucrat("Bob", 151);  // Should throw GradeTooLowException
    } 
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;
    } 
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
    }

    try {
        // Bureaucrat with too high grade
        Bureaucrat highGradeBureaucrat("Charlie", 0);  // Should throw GradeTooHighException
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;
    } 
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
    }

    try {
        // Another valid bureaucrat, testing the increment until exception
        Bureaucrat highRank("Dave", 2);
        std::cout << "Created bureaucrat: " << highRank.getName() 
                  << " with grade " << highRank.getGrade() << std::endl;

        // Increment the grade to trigger GradeTooHighException
        highRank.incrementGrade();
        std::cout << "After incrementing, " << highRank.getName() 
                  << " now has grade " << highRank.getGrade() << std::endl;

        highRank.incrementGrade();  // This should trigger the GradeTooHighException
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;
    } 
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
    }

    return (0);
} //main created by the grace of chatgpt