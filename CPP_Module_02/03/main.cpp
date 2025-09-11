#include "Fixed.hpp"
#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	std::cout << "=== CASOS DE PRUEBA PARA BSP ===" << std::endl;
	std::cout << std::endl;

	std::cout << "--- CASO 1: Punto DENTRO ---" << std::endl;
	{
		Point p1(0, 0);
		Point p2(6, 0);
		Point p3(3, 4);
		Point test(3, 2);

		std::cout << "Triángulo: A(0,0), B(6,0), C(3,4)" << std::endl;
		std::cout << "Punto test: (3,2)" << std::endl;

		bool inside = bsp(p1, p2, p3, test);
		std::cout << "Resultado: " << (inside ? "DENTRO ✅" : "FUERA ❌") << std::endl;
		std::cout << "Esperado: DENTRO" << std::endl;
		std::cout << std::endl;
	}

	std::cout << "--- CASO 2: Punto FUERA ---" << std::endl;
	{
		Point p1(0, 0);
		Point p2(6, 0);
		Point p3(3, 4);
		Point test(7, 3);

		std::cout << "Triángulo: A(0,0), B(6,0), C(3,4)" << std::endl;
		std::cout << "Punto test: (7,3)" << std::endl;

		bool inside = bsp(p1, p2, p3, test);
		std::cout << "Resultado: " << (inside ? "DENTRO ✅" : "FUERA ❌") << std::endl;
		std::cout << "Esperado: FUERA" << std::endl;
		std::cout << std::endl;
	}

	// CASO 3: Punto en el BORDE (arista)
	std::cout << "--- CASO 3: Punto en ARISTA ---" << std::endl;
	{
		Point p1(0, 0);
		Point p2(6, 0);
		Point p3(3, 4);
		Point test(3, 0);

		std::cout << "Triángulo: A(0,0), B(6,0), C(3,4)" << std::endl;
		std::cout << "Punto test: (3,0) - en arista AB" << std::endl;

		bool inside = bsp(p1, p2, p3, test);
		std::cout << "Resultado: " << (inside ? "DENTRO ✅" : "FUERA ❌") << std::endl;
		std::cout << "Esperado: FUERA (porque está en el borde)" << std::endl;
		std::cout << std::endl;
	}

	std::cout << "--- CASO 4: Punto en VÉRTICE ---" << std::endl;
	{
		Point p1(0, 0);
		Point p2(6, 0);
		Point p3(3, 4);
		Point test(0, 0);

		std::cout << "Triángulo: A(0,0), B(6,0), C(3,4)" << std::endl;
		std::cout << "Punto test: (0,0) - en vértice A" << std::endl;

		bool inside = bsp(p1, p2, p3, test);
		std::cout << "Resultado: " << (inside ? "DENTRO ✅" : "FUERA ❌") << std::endl;
		std::cout << "Esperado: FUERA (porque está en el borde)" << std::endl;
		std::cout << std::endl;
	}

	std::cout << "--- CASO 5: Triángulo orientación horaria ---" << std::endl;
	{
		Point p1(0, 0);
		Point p2(3, 4);
		Point p3(6, 0);
		Point test(3, 2);

		std::cout << "Triángulo: A(0,0), C(3,4), B(6,0) [orden horario]" << std::endl;
		std::cout << "Punto test: (3,2)" << std::endl;

		bool inside = bsp(p1, p2, p3, test);
		std::cout << "Resultado: " << (inside ? "DENTRO ✅" : "FUERA ❌") << std::endl;
		std::cout << "Esperado: DENTRO (independiente de la orientación)" << std::endl;
		std::cout << std::endl;
	}

	std::cout << "--- CASO 6: Punto MUY CERCA del borde ---" << std::endl;
	{
		Point p1(0, 0);
		Point p2(6, 0);
		Point p3(3, 4);
		Point test(3, 0.1f);
		std::cout << "Triángulo: A(0,0), B(6,0), C(3,4)" << std::endl;
		std::cout << "Punto test: (3,0.1) - muy cerca del borde" << std::endl;

		bool inside = bsp(p1, p2, p3, test);
		std::cout << "Resultado: " << (inside ? "DENTRO ✅" : "FUERA ❌") << std::endl;
		std::cout << "Esperado: DENTRO" << std::endl;
		std::cout << std::endl;
	}

	std::cout << "--- CASO 7: Tu ejemplo original ---" << std::endl;
	{
		Point p1(0, 0);
		Point p2(5, 0);
		Point p3(2.5, 5);
		Point test(2.5, 3.5);

		std::cout << "Triángulo: A(0,0), B(5,0), C(2.5,5)" << std::endl;
		std::cout << "Punto test: (2.5,3.5)" << std::endl;

		bool inside = bsp(p1, p2, p3, test);
		std::cout << "Resultado: " << (inside ? "DENTRO ✅" : "FUERA ❌") << std::endl;
		std::cout << "Esperado: DENTRO" << std::endl;
		std::cout << std::endl;
	}

	std::cout << "--- CASO 8: Triángulo pequeño ---" << std::endl;
	{
		Point p1(0, 0);
		Point p2(1, 0);
		Point p3(0.5, 1);
		Point test(0.5, 0.3f);

		std::cout << "Triángulo: A(0,0), B(1,0), C(0.5,1)" << std::endl;
		std::cout << "Punto test: (0.5,0.3)" << std::endl;

		bool inside = bsp(p1, p2, p3, test);
		std::cout << "Resultado: " << (inside ? "DENTRO ✅" : "FUERA ❌") << std::endl;
		std::cout << "Esperado: DENTRO" << std::endl;
		std::cout << std::endl;
	}

	std::cout << "=== FIN DE PRUEBAS ===" << std::endl;

	return 0;
}
