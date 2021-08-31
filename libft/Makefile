
NAME = 				libft.a

FLAGS = 			 -c -Wall -Wextra -Werror

LIBFT = 		ft_atoi.c  ft_bzero.c  ft_substr.c ft_putchar_fd.c\
				ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c \
				ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
				ft_strchr.c ft_strdup.c ft_strlcat.c ft_putstr_fd.c \
				ft_strlcpy.c ft_strlen.c  ft_strncmp.c ft_putnbr_fd.c\
				ft_strnstr.c ft_strrchr.c ft_putendl_fd.c ft_strjoin.c\
				ft_tolower.c ft_toupper.c ft_strtrim.c ft_itoa.c ft_strmapi.c \
				ft_split.c ft_zeroer.c ft_itoabase.c ft_itoa_ui.c \
				ft_itoa_ptr.c

BONUS = 		ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c \
				ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c \
				ft_lstiter.c ft_lstmap.c

OBJ =			$(LIBFT:.c=.o)
OBJ_BONUS = 	$(BONUS:.c=.o)

HEADERS =		 libft.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	ar rc $(NAME) $(OBJ) $(HEADERS)
	ranlib $(NAME)

%.o: %.c $(HEADERS)
	gcc $(FLAGS) $< -g -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f libft.a

re: fclean all

bonus: all $(OBJ_BONUS)
	ar rc $(NAME) $(OBJ_BONUS) $(HEADERS)
	ranlib $(NAME)
