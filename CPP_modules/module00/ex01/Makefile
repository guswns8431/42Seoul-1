NAME = phonebook
CC = clang++
CPPFLAGS = -Wall -Werror -Wextra
INC = -I./phonebook.hpp
SRC = phonebook.cpp main.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CPPFLAGS) $(INC) $^ -o $@

clean :
	rm -rf $(NAME)

re : clean all

