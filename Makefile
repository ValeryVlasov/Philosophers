#NAME	=	philo
#
#SRC	=	philosophers.c
#
#HDR	=	philosophers.h
#
#LIBDIR	=	./libft
#
#OBJ = $(SRC:.c=.o)
#
#SRC_LIB	=	libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstclear.c libft/ft_lstdelone.c libft/ft_lstiter.c\
#			libft/ft_lstlast.c libft/ft_lstmap.c libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_atoi.c libft/ft_bzero.c\
#			libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c\
#			libft/ft_isspace.c libft/ft_itoa.c libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c\
#			libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c\
#			libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c\
#			libft/ft_strlcpy.c libft/ft_strmapi.c libft/ft_strcmp.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c\
#			libft/ft_strrev.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_strlen.c\
#			libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstclear.c libft/ft_lstdelone.c libft/ft_lstiter.c\
#			libft/ft_lstlast.c libft/ft_lstmap.c libft/ft_lstnew.c libft/ft_lstsize.c
#
#CC	=	gcc
#
#LIB	=	./libft/libft.a
#
#CFLAGS	=	#-Wall -Wextra -Werrors
#
#.PHONY:	all clean fclean re
#
#all: $(NAME)
#
#
#$(NAME):	Makefile  $(OBJ)
#		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
#
#%.o:	%.c $(HDR) $(LIB)
#		$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
#
#$(LIB):
#		make -s -C $(LIBDIR)
#
#clean:
#		rm -f $(OBJ)
#		make clean -C $(LIBDIR)
#
#fclean:	clean
#				make fclean -C $(LIBDIR)
#				rm -f $(NAME)
#
#re: clean fclean all
#

NAME = philo

SRC =  philosophers.c philo_num.c init.c routine.c errors.c

SRC_LIB	=

OBJ		=	$(SRC:.c=.o)
LIBDIR	=	libft
LIB		=	$(LIBDIR)/libft.a
CC		=	gcc
CFLAGS	=	 -g #-Wall -Wextra -Werror
HEADER	=	philosophers.h

.PHONY	:	all clean fclean re libft minilibs sbor_minishell

all		:	$(NAME)

$(LIB)	:
			make -s -C $(LIBDIR)

$(NAME)	:	$(OBJ) Makefile
			$(CC) $(CFLAGS) -L $(LIBDIR) -lft $(OBJ) -o $(NAME)

%.o		:	%.c $(LIB)
			$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean	:
			rm -f $(OBJ)
			make clean -s -C $(LIBDIR)

fclean	:	clean
			make fclean -s -C $(LIBDIR)
			rm -f $(NAME)

re		:	fclean all
