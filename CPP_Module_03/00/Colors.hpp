#ifndef COLORS_HPP
#define COLORS_HPP

#include <string>

class Colors
{
public:
	// Colores básicos
	static const std::string RESET;
	static const std::string RED;
	static const std::string GREEN;
	static const std::string YELLOW;
	static const std::string BLUE;
	static const std::string MAGENTA;
	static const std::string CYAN;
	static const std::string WHITE;

	// Colores brillantes
	static const std::string BRIGHT_RED;
	static const std::string BRIGHT_GREEN;
	static const std::string BRIGHT_YELLOW;
	static const std::string BRIGHT_BLUE;
	static const std::string BRIGHT_MAGENTA;
	static const std::string BRIGHT_CYAN;
	static const std::string BRIGHT_WHITE;

	// Constructores
	Colors();
	Colors(const std::string &color);
	Colors(const Colors &other);
	Colors &operator=(const Colors &other);
	~Colors();

	// Métodos para obtener colores
	std::string getColor() const;
	void setColor(const std::string &color);

	// Método para colorear texto
	std::string colorize(const std::string &text) const;

	// Método estático para obtener color aleatorio
	static std::string getRandomColor();

	// Operador de salida
	friend std::ostream &operator<<(std::ostream &os, const Colors &colors);

private:
	std::string currentColor;
	static const std::string colorArray[];
	static const int colorCount;
};

#endif
