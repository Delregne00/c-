#include "Bureaucrat.hpp"

int main(){
    try {
        Bureaucrat b1("Andreu", 34);
        Form    f1("DNI", 30, 50);

          for (int i = 0; i < 10; i++)
              b1.gradeTooHight();

        b1.signForm(f1);

        std::cout << f1 << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
