#include <Bureaucrat.hpp>
#include <Form.hpp>

int main() {
    try {
        // Creating Bureaucrats with different grades
        Bureaucrat alice("Alice", 30);  // Alice, grade 30
        Bureaucrat bob("Bob", 100);      // Bob, grade 100
        Bureaucrat charlie("Charlie", 10); // Charlie, grade 10

        // Creating Forms with different grade requirements
        Form testForm1("Form 1", 40, 20);  // Requires grade 40 to sign, 20 to execute
        Form testForm2("Form 2", 10, 5);   // Requires grade 10 to sign, 5 to execute
        Form testForm3("Form 3", 60, 30);  // Requires grade 60 to sign, 30 to execute

        std::cout << "Test Form 1 (Alice signing)" << std::endl;
        std::cout << testForm1 << std::endl;
        alice.signForm(testForm1); // Alice can sign (grade 30 < 40)
        std::cout << testForm1 << std::endl;

        std::cout << "Test Form 2 (Bob signing)" << std::endl;
        std::cout << testForm2 << std::endl;
        bob.signForm(testForm2);  // Bob cannot sign (grade 50 > 10)
        std::cout << testForm2 << std::endl;

        std::cout << "Test Form 2 (Charlie signing)" << std::endl;
        std::cout << testForm2 << std::endl;
        charlie.signForm(testForm2); // Charlie can sign (grade 10 == 10)
        std::cout << testForm2 << std::endl;

        std::cout << "Test Form 3 (Charlie signing)" << std::endl;
        std::cout << testForm3 << std::endl;
        charlie.signForm(testForm3); // Charlie can sign (grade 10 > 60)
        std::cout << testForm3 << std::endl;

        // Create a Form with an invalid grade (too high for a bureaucrat to sign)
        try {
            std::cout << "Creating Form with grade too high to sign" << std::endl;
            Form invalidForm("Invalid Form", 0, 100);  // Requires grade 0 to sign (impossible)
            std::cout << invalidForm << std::endl;
            alice.signForm(invalidForm);  // This should throw exception
        } catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Create a Form with a bureaucrat that has a too low grade to sign
        try {
            Form formLowGrade("Low Grade Form", 99, 10); // Sign requires grade 100
            std::cout << formLowGrade << std::endl;
            bob.signForm(formLowGrade); // This should throw exception as Bob has grade 50
        } catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return (0);
} //powered by future overlords again
