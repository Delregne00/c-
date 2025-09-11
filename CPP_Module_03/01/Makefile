# Variables del compilador
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = ScravTrap
SOURCES = main.cpp ClapTrap.cpp ScravTrap.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = ClapTrap.hpp ScravTrap.hpp

# Regla por defecto (la primera regla)
all: $(TARGET)

# Crear el ejecutable enlazando los archivos objeto
$(TARGET): $(OBJECTS) Makefile
	$(CXX) $(OBJECTS) -o $(TARGET)
	@echo "Ejecutable '$(TARGET)' creado exitosamente"

# Regla implícita para compilar .cpp a .o
%.o: %.cpp $(HEADERS)
		$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar archivos objeto
clean:
		rm -f $(OBJECTS)
		@echo "Archivos objeto eliminados"

# Regla para limpiar todo (archivos objeto + ejecutable)
fclean: clean
		rm -f $(TARGET)
		@echo "Ejecutable eliminado"

# Regla para recompilar todo
re: fclean all

# Reglas que no crean archivos
.PHONY: all clean fclean
