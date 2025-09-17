CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = Materia

# Directorios
SRCDIR = srcs
INCDIR = includes

# Archivos fuente con rutas correctas
SOURCES = main.cpp \
		  $(SRCDIR)/AMateria.cpp \
		  $(SRCDIR)/Character.cpp \
		  $(SRCDIR)/Cure.cpp \
		  $(SRCDIR)/Ice.cpp \
		  $(SRCDIR)/MateriaSource.cpp

OBJECTS = $(SOURCES:.cpp=.o)

# Headers con rutas correctas
HEADERS = $(INCDIR)/AMateria.hpp \
		  $(INCDIR)/Character.hpp \
		  $(INCDIR)/Cure.hpp \
		  $(INCDIR)/Ice.hpp \
		  $(INCDIR)/ICharacter.hpp \
		  $(INCDIR)/IMateriaSource.hpp \
		  $(INCDIR)/MateriaSource.hpp \
		  $(INCDIR)/headers.h

# Flags para includes
INCLUDES = -I$(INCDIR)

all: $(TARGET)

$(TARGET): $(OBJECTS) Makefile
	$(CXX) $(OBJECTS) -o $(TARGET)
	@echo "Exe '$(TARGET)' is created"

# Regla para compilar archivos .cpp a .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	@echo "Objects are destroyed"

fclean: clean
	rm -f $(TARGET)
	@echo "EXE is destroyed"

re: fclean all

.PHONY: all clean fclean re
