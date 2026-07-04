CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

NAME = serialize
SRC = main.cpp Serializer.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	
%.o: %.cpp Serializer.hpp Data.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all