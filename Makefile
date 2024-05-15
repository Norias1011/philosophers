NAME		= philo

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g -pthread

SRCS		= main.c dinner.c data_init.c utils.c utils_second.c philo_action.c

OBJS		= $(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) 
						$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
					rm -rf $(OBJS)

fclean		:		clean
					rm -rf $(NAME)

re			:		fclean all