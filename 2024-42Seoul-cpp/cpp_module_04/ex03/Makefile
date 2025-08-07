.DEFAULT_GOAL := all

CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98
SRCS=main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJS=$(SRCS:%.cpp=%.o)
NAME=game

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
