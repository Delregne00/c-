CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = form
SOURCES = main.cpp Bureaucrat.cpp Form.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Bureaucrat.hpp Exception.hpp Form.hpp

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
