CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

NAME = convert
SRC = ScalarConverter.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	
%.o: %.cpp ScalarConverter.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all