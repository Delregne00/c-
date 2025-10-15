CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = AAnimal
SOURCES = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Animal.hpp Cat.hpp Dog.hpp Brain.hpp

all: $(TARGET)

$(TARGET): $(OBJECTS) Makefile
	$(CXX) $(OBJECTS) -o $(TARGET)
	@echo "Exe '$(TARGET)' is created"

%.o: %.cpp $(HEADERS)
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		rm -f $(OBJECTS)
		@echo "Objects are destroyed"

fclean:
		rm -f $(TARGET)
		@echo "EXE is destroyed"

re: fclean all

.PHONY: all clean fclean
