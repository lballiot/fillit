# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lballiot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 10:49:26 by lballiot          #+#    #+#              #
#    Updated: 2017/12/12 10:56:38 by lballiot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_PATH = ./src/

SRC = main.c

OBJ = $(SRC:.c=.o)

INCLUDE = -I ./includes

FLAGS += -Wall -Werror -Wextra

CC = clang

LIBFT_PATH = ./libft/

LIBFT_LINK = -L $(LIBFT_PATH) -lft

LIBFT = ./libft/libft.a

RM = rm -rf

all: $(NAME)

LIBFT_CC:
	make -C $(LIBFT_PATH)

$(NAME): LIBFT_CC
	$(CC) -c $(FLAGS) $(SRC_PATH)$(SRC) $(INCLUDE)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIBFT_LINK)

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all
	make -C $(LIBFT_PATH) re
