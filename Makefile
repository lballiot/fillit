#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/07 11:00:28 by rvolberg          #+#    #+#              #
#    Updated: 2017/12/12 14:46:04 by rvolberg         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC_PATH = ./src/

SRC = *.c

OBJ = $(SRC:.c=.o)

INCLUDE = -I ./includes/

FLAGS += -Wall -Werror -Wextra

CC = clang

LIBFT_PATH = ./libft/

LIBFT_LINK = -L $(LIBFT_PATH) -lft

LIBFT = ./libft/libft.a

all: $(NAME)

LIBFT_CC:
	make -C $(LIBFT_PATH)

$(NAME): LIBFT_CC
	$(CC) -c $(FLAGS) $(SRC_PATH)$(SRC) $(INCLUDE)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIBFT_LINK)
clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
re: fclean all
	make -C $(LIBFT_PATH) re















