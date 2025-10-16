#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
    try {
        Bureaucrat b1("Andreu", 14);
        ShrubberyCreationForm f1;
        ShrubberyCreationForm f2("Abre");


        b1.signForm(f1);
        b1.executeForm(f1);

        b1.signForm(f2);
        b1.executeForm(f2);


    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
