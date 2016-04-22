# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bndao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/18 04:48:31 by bndao             #+#    #+#              #
#    Updated: 2016/04/22 18:48:55 by bndao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall
FLAGS += -Werror
FLAGS += -Wextra

SRCDIR = src/
GNLDIR = gnl/

SRC = $(SRCDIR)main.c \
		$(GNLDIR)get_next_line.c \

INC = headers

OBJ = $(SRC:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(INC) -L ./libft -lft
	@echo "\033[1;31m---- Minishell Created !!! ----\033[0m"

%.o:%.c
	@gcc $(FLAGS) -c -o $@ $< -I $(INC) -I libft/

lib:
	@echo "\033[1;32m-> Creating Library...\033[0m"
	@make -C ./libft/

clean:
	@rm -f $(OBJ)
	@echo "\033[0;36m\nMinishell Directory Cleaned up.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft/

re: fclean all

allclean: re clean

.PHONY: $(NAME) all lib clean fclean re allclean
