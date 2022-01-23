NAME = philo

SRC = 	philosophers.c philo_num.c init.c routine.c errors.c calc_time.c utils/delete_mem.c\
		utils/ft_putstrs_fd.c utils/ft_atoi.c utils/ft_itoa.c utils/ft_putstr_fd.c utils/ft_strlen.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	=	 -g -Wall -Wextra -Werror

HEADER	=	philosophers.h

.PHONY	:	all clean fclean re

all		:	$(NAME)


$(NAME)	:	$(OBJ) Makefile philosophers.h
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	clean fclean all
