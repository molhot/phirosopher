NAME = philosophers

SRCS = basic_func/ft_atoi.c basic_func/print_action.c basic_func/time_func.c\
		philosophers_action/philo_behavior.c philosophers_action/philo_fork.c philosophers_action/philo_think_eat.c\
		arg_checker.c checker.c philo_main.c

OBJS = $(SRCS:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror -I includes -pthread

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(NAME)

fclean: clean
	rm -f all

re: fclean all

.PHONY:			all clean fclean re bonus