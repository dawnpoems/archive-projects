.DEFAULT_GOAL := all

CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98
SRCS=main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS=$(SRCS:%.cpp=%.o)
NAME=mybsp

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
