# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/01 13:45:37 by ybokina           #+#    #+#              #
#    Updated: 2018/06/02 12:53:21 by ybokina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_ls

LIBA := ./libft/libft.a

FLAGS := -Wall -Wextra -Werror

SOURCES := ft_check.c ft_error.c ft_list_actions.c ft_options.c ft_print.c ft_recurse.c ft_sort.c main.c ft_elem.c ft_long.c ft_opt_file.c ft_functions.c ft_int.c ft_long_funcs.c ft_long_print.c ft_options_2.c ft_recursion.c ft_additional.c lst_file_del.c free_elem.c

OBJ := $(SOURCES:.c=.o)

HEADER := ft_ls.h


all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAGS) -o $(NAME) $(SOURCES) $(LIBA)
	@echo "\033[48;5;7m\033[31m\033[5mDone: ./ft_ls is created."

clean:
	@make -C libft clean

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
