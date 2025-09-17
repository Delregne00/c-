CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = ScavTrap
SOURCES = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = ClapTrap.hpp ScavTrap.hpp

all: $(TARGET)

$(TARGET): $(OBJECTS) Makefile
	$(CXX) $(OBJECTS) -o $(TARGET)
	@echo "Ejecutable '$(TARGET)' creado exitosamente"

%.o: %.cpp $(HEADERS)
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		rm -f $(OBJECTS)
		@echo "Archivos objeto eliminados"

fclean: clean
		rm -f $(TARGET)
		@echo "Ejecutable eliminado"

re: fclean all

.PHONY: all clean fclean
