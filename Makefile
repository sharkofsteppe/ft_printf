# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gesperan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 14:31:45 by gesperan          #+#    #+#              #
#    Updated: 2020/12/16 19:24:53 by gesperan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
PRINTF = ft_printf.c ft_processing.c ft_charwrt.c ft_type.c ft_width.c \
		 ft_accuracy.c ft_flag.c ft_strwrt.c ft_fillstr.c ft_fillernum.c \
		 ft_fillnumrs.c ft_alignum.c ft_putnumright.c ft_numwrt.c  \
		 ft_xwrt.c ft_ptrwrt.c ft_prcntwrt.c ft_uintwrt.c
FLAGS = -c -Wall -Wextra -Werror
LIBFT_BUILD = cd libft && make && cd ..
LIBFT_FCLEAN = cd libft && make fclean && cd ..
LIBFT_FILES = 	libft/ft_atoi.o libft/ft_bzero.o libft/ft_substr.o \
				libft/ft_putchar_fd.o libft/ft_calloc.o libft/ft_isalnum.o \
				libft/ft_isalpha.o libft/ft_isascii.o libft/ft_isdigit.o \
				libft/ft_isprint.o libft/ft_memccpy.o libft/ft_memchr.o \
				libft/ft_memcmp.o libft/ft_memcpy.o libft/ft_memmove.o \
				libft/ft_memset.o libft/ft_strchr.o libft/ft_strdup.o \
				libft/ft_strlcat.o libft/ft_putstr_fd.o libft/ft_strlcpy.o \
				libft/ft_strlen.o libft/ft_strncmp.o libft/ft_putnbr_fd.o \
				libft/ft_strnstr.o libft/ft_strrchr.o libft/ft_putendl_fd.o \
				libft/ft_strjoin.o libft/ft_tolower.o libft/ft_toupper.o \
				libft/ft_strtrim.o libft/ft_itoa.o libft/ft_strmapi.o \
				libft/ft_split.o libft/ft_itoa_ptr.o libft/ft_itoabase.o \
				libft/ft_itoa_ui.o libft/ft_zeroer.o libft/libft.h
LIBFTPRINTF_BUILD = ar rc $(NAME)
LIBFTPRINTF_INDEX = ranlib $(NAME)

PRINTF_OBJ = $(PRINTF:.c=.o)

all : $(NAME)

$(NAME): $(PRINTF_OBJ) $(LIBFT_FILES) libftprintf.h Makefile
	$(LIBFT_BUILD)
	$(LIBFTPRINTF_BUILD) $(PRINTF_OBJ) $(LIBFT_FILES)
	$(LIBFTPRINTF_INDEX)

%.o: %.c
	@ gcc $(FLAGS) $< -o $@

clean:
	@ $(LIBFT_FCLEAN)
	@ rm -f *.o

fclean: clean
	@ rm -f libftprintf.a
	@ rm -f *.out
	
re:	fclean all
