NAME = test

CFLAGS = -Wextra -Wall -Werror -std=c++98 -fsanitize=address -g3

CC = c++

SRC = phonebook.cpp addUser.cpp displayData.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp phonebook.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all