NAME= ex00

SRC = Fixed.cpp main.cpp\

CC = c++
FLAGS= -Wall -Werror -Wextra -std=c++98
PARA  = -c 

OBJ= $(SRC:.cpp=.o)

%.o : %.cpp 
	@$(CC) $(PARA) $(FLAGS) $<  -o $@

all: $(NAME)
	
$(NAME): $(OBJ)
		@${CC} $(OBJ) $(FLAGS) -o ${NAME} 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all