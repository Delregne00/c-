#include "Colors.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Definición de constantes estáticas
const std::string Colors::RESET = "\033[0m";
const std::string Colors::RED = "\033[31m";
const std::string Colors::GREEN = "\033[32m";
const std::string Colors::YELLOW = "\033[33m";
const std::string Colors::BLUE = "\033[34m";
const std::string Colors::MAGENTA = "\033[35m";
const std::string Colors::CYAN = "\033[36m";
const std::string Colors::WHITE = "\033[37m";

const std::string Colors::BRIGHT_RED = "\033[91m";
const std::string Colors::BRIGHT_GREEN = "\033[92m";
const std::string Colors::BRIGHT_YELLOW = "\033[93m";
const std::string Colors::BRIGHT_BLUE = "\033[94m";
const std::string Colors::BRIGHT_MAGENTA = "\033[95m";
const std::string Colors::BRIGHT_CYAN = "\033[96m";
const std::string Colors::BRIGHT_WHITE = "\033[97m";

// Array para colores aleatorios
const std::string Colors::colorArray[] = {
	RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE,
	BRIGHT_RED, BRIGHT_GREEN, BRIGHT_YELLOW, BRIGHT_BLUE,
	BRIGHT_MAGENTA, BRIGHT_CYAN, BRIGHT_WHITE};

const int Colors::colorCount = sizeof(colorArray) / sizeof(colorArray[0]);

// Constructor por defecto
Colors::Colors() : currentColor(WHITE)
{
	static bool seedInitialized = false;
	if (!seedInitialized)
	{
		srand(time(NULL));
		seedInitialized = true;
	}
}

// Constructor con color específico
Colors::Colors(const std::string &color) : currentColor(color)
{
	static bool seedInitialized = false;
	if (!seedInitialized)
	{
		srand(time(NULL));
		seedInitialized = true;
	}
}

// Constructor de copia
Colors::Colors(const Colors &other) : currentColor(other.currentColor)
{
}

// Operador de asignación
Colors &Colors::operator=(const Colors &other)
{
	if (this != &other)
	{
		currentColor = other.currentColor;
	}
	return *this;
}

// Destructor
Colors::~Colors()
{
}

// Getters y setters
std::string Colors::getColor() const
{
	return currentColor;
}

void Colors::setColor(const std::string &color)
{
	currentColor = color;
}

// Método para colorear texto
std::string Colors::colorize(const std::string &text) const
{
	return currentColor + text + RESET;
}

// Método estático para obtener color aleatorio
std::string Colors::getRandomColor()
{
	return colorArray[rand() % colorCount];
}

// Operador de salida
std::ostream &operator<<(std::ostream &os, const Colors &colors)
{
	os << colors.currentColor;
	return os;
}
