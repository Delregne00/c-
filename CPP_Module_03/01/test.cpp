#include <iostream>
#include <string>
using namespace std;

// =============================================================================
// NIVEL 1: FUNCIONES VIRTUALES - El primer "WOW" de la herencia
// =============================================================================

// Problema: Sin virtual, no funciona como esperamos
class Animal {
protected:
    string name;
public:
    Animal(string n) : name(n) {}

    // SIN virtual - comportamiento estático
    void makeSound() {
        cout << name << " makes a generic animal sound" << endl;
    }

    void info() {
        cout << "I am " << name << ", an animal" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    // Sobrescribimos makeSound
    void makeSound() {
        cout << name << " says: WOOF WOOF!" << endl;
    }

    void info() {
        cout << "I am " << name << ", a loyal dog" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}

    void makeSound() {
        cout << name << " says: MEOW!" << endl;
    }

    void info() {
        cout << "I am " << name << ", an independent cat" << endl;
    }
};

// =============================================================================
// PROBLEMA: Punteros de clase base
// =============================================================================

void testWithoutVirtual() {
    cout << "\n=== SIN VIRTUAL - PROBLEMA ===\n" << endl;

    // Creamos animales específicos
    Dog dog("Rex");
    Cat cat("Whiskers");

    cout << "--- Llamadas directas (funciona bien) ---" << endl;
    dog.makeSound();  // WOOF WOOF!
    cat.makeSound();  // MEOW!

    cout << "\n--- Usando punteros de Animal (PROBLEMA) ---" << endl;
    Animal* pets[2];
    pets[0] = &dog;    // Dog tratado como Animal
    pets[1] = &cat;    // Cat tratado como Animal

    for (int i = 0; i < 2; i++) {
        pets[i]->makeSound();  // ¡Siempre llama Animal::makeSound()!
        pets[i]->info();       // ¡Siempre llama Animal::info()!
    }

    cout << "\n¿Por qué? Porque el compilador decide en TIEMPO DE COMPILACIÓN" << endl;
    cout << "Ve Animal* y dice: 'Usaré Animal::makeSound()'" << endl;
}

// =============================================================================
// SOLUCIÓN: FUNCIONES VIRTUALES
// =============================================================================

class VirtualAnimal {
protected:
    string name;
public:
    VirtualAnimal(string n) : name(n) {}

    // CON virtual - comportamiento dinámico
    virtual void makeSound() {
        cout << name << " makes a generic animal sound" << endl;
    }

    virtual void info() {
        cout << "I am " << name << ", an animal" << endl;
    }

    // Función no virtual para comparar
    void eat() {
        cout << name << " is eating" << endl;
    }
};

class VirtualDog : public VirtualAnimal {
public:
    VirtualDog(string n) : VirtualAnimal(n) {}

    // override es opcional pero recomendado (C++11+)
    void makeSound() override {
        cout << name << " says: WOOF WOOF!" << endl;
    }

    void info() override {
        cout << "I am " << name << ", a loyal dog" << endl;
    }

    // Método específico de Dog
    void fetch() {
        cout << name << " is fetching the ball!" << endl;
    }
};

class VirtualCat : public VirtualAnimal {
public:
    VirtualCat(string n) : VirtualAnimal(n) {}

    void makeSound() override {
        cout << name << " says: MEOW!" << endl;
    }

    void info() override {
        cout << "I am " << name << ", an independent cat" << endl;
    }

    void climb() {
        cout << name << " is climbing a tree!" << endl;
    }
};

void testWithVirtual() {
    cout << "\n=== CON VIRTUAL - SOLUCIÓN ===\n" << endl;

    VirtualDog dog("Buddy");
    VirtualCat cat("Luna");

    cout << "--- Usando punteros de VirtualAnimal (FUNCIONA) ---" << endl;
    VirtualAnimal* pets[2];
    pets[0] = &dog;
    pets[1] = &cat;

    for (int i = 0; i < 2; i++) {
        pets[i]->makeSound();  // ¡Llama la versión correcta!
        pets[i]->info();       // ¡Llama la versión correcta!
        pets[i]->eat();        // No virtual - siempre VirtualAnimal::eat()
        cout << endl;
    }

    cout << "¿Cómo? El compilador decide en TIEMPO DE EJECUCIÓN" << endl;
    cout << "Ve el tipo REAL del objeto y llama la función correcta" << endl;
}

// =============================================================================
// CONCEPTOS CLAVE
// =============================================================================

void explainConcepts() {
    cout << "\n=== CONCEPTOS CLAVE ===\n" << endl;

    cout << "1. SIN virtual:" << endl;
    cout << "   - Decisión en TIEMPO DE COMPILACIÓN" << endl;
    cout << "   - Usa el tipo del PUNTERO" << endl;
    cout << "   - Animal* siempre llama Animal::función()" << endl;
    cout << endl;

    cout << "2. CON virtual:" << endl;
    cout << "   - Decisión en TIEMPO DE EJECUCIÓN" << endl;
    cout << "   - Usa el tipo del OBJETO REAL" << endl;
    cout << "   - Animal* puede llamar Dog::función() si apunta a Dog" << endl;
    cout << endl;

    cout << "3. override (C++11+):" << endl;
    cout << "   - No es obligatorio, pero RECOMENDADO" << endl;
    cout << "   - El compilador verifica que realmente sobrescribes" << endl;
    cout << "   - Previene errores de tipeo" << endl;
    cout << endl;

    cout << "4. ¿Cuándo usar virtual?" << endl;
    cout << "   - Cuando quieras POLIMORFISMO" << endl;
    cout << "   - Cuando tengas punteros/referencias de clase base" << endl;
    cout << "   - Cuando quieras comportamiento específico por tipo" << endl;
}

// =============================================================================
// EJEMPLO PRÁCTICO: Sistema de empleados
// =============================================================================

class Employee {
protected:
    string name;
    double baseSalary;
public:
    Employee(string n, double salary) : name(n), baseSalary(salary) {}

    virtual double calculatePay() {  // ¡Virtual!
        return baseSalary;
    }

    virtual void work() {  // ¡Virtual!
        cout << name << " is working" << endl;
    }

    void clockIn() {  // No virtual - mismo para todos
        cout << name << " clocked in at 9 AM" << endl;
    }

    string getName() const { return name; }
};

class Manager : public Employee {
private:
    double bonus;
public:
    Manager(string n, double salary, double b) : Employee(n, salary), bonus(b) {}

    double calculatePay() override {
        return baseSalary + bonus;  // Salario + bonus
    }

    void work() override {
        cout << name << " is managing the team" << endl;
    }
};

class Programmer : public Employee {
private:
    int linesOfCode;
public:
    Programmer(string n, double salary) : Employee(n, salary), linesOfCode(0) {}

    double calculatePay() override {
        return baseSalary + (linesOfCode * 0.1);  // Bonus por líneas de código
    }

    void work() override {
        cout << name << " is coding awesome software" << endl;
        linesOfCode += 100;
    }
};

void payrollSystem() {
    cout << "\n=== EJEMPLO PRÁCTICO: SISTEMA DE NÓMINA ===\n" << endl;

    // Array de empleados diferentes
    Employee* employees[3];
    employees[0] = new Manager("Alice", 5000, 1000);
    employees[1] = new Programmer("Bob", 4000);
    employees[2] = new Employee("Charlie", 3000);

    cout << "--- Procesando nómina ---" << endl;
    for (int i = 0; i < 3; i++) {
        employees[i]->clockIn();                           // Mismo para todos
        employees[i]->work();                              // ¡Específico por tipo!
        cout << "Pay: $" << employees[i]->calculatePay()  // ¡Específico por tipo!
             << endl << endl;
    }

    // Limpiar memoria
    for (int i = 0; i < 3; i++) {
        delete employees[i];
    }
}

// =============================================================================
// MAIN - EJECUTAR TODO
// =============================================================================

int main() {
    cout << "=== TUTORIAL HERENCIA C++ - NIVEL 1: FUNCIONES VIRTUALES ===" << endl;

    testWithoutVirtual();    // Mostrar el problema
    testWithVirtual();       // Mostrar la solución
    explainConcepts();       // Explicar conceptos
    payrollSystem();         // Ejemplo práctico

    cout << "\n=== ¿LISTO PARA EL NIVEL 2? ===" << endl;
    cout << "Siguiente: Destructores virtuales y clases abstractas" << endl;

    return 0;
}
