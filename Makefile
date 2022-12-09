NAME = philosophers.a

SRCS = basic_func/ft_atoi.c basic_func/ft_graspcharlen.c basic_func/ft_putchar_fd.c show_error/showerror.c\
		philosophers_action/philo_behavior.c philosophers_action/philo_fork.c philosophers_action/philo_think_eat.c\
		philo_main.c

OBJS = $(SRCS:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror -I includes

all: $(NAME)

$(NAME):$(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f all

re: fclean all

.PHONY:			all clean fclean re bonus