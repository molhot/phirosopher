NAME = philo

SRCS = main.c\
		arg_checker.c\
		ready_samephiloinfo.c\
		handling_mutex.c\
		handling_threads.c\
		basic_func/ft_atoi.c basic_func/print_action.c basic_func/ft_getnowtime.c\
		philosophers_action/philo_behavior.c philosophers_action/philo_think_eat.c\
		checker.c

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