# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 13:08:42 by ielmoudn          #+#    #+#              #
#    Updated: 2019/07/13 21:27:05 by ielmoudn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_lCYAN = \x1b[96m
_lYELLOW = \x1b[93m
_lGREEN = \x1b[92m
_lBLUE = \x1b[94m
_RED = \x1b[31m
_BOLD = \x1b[1m
_END = \x1b[0m

CC = gcc
NAME = my_ls
FILENAMES = get_options.c\
	insert_lnode.c\
	is_dir.c\
	main.c\
	new_lnode.c\
	f_print.c\
	get_dname.c\
	get_type.c\
	print_color.c\
	read_content.c\
	is_hidden.c\
	process_args.c\
	get_function.c\
	print_args.c\
	normal_fill.c\
	init_info.c\
	insert_argnode.c\
	insert_argnode_rev.c\
	insert_lnode_rev.c\
	new_argnode.c\
	usage_error.c\
	sort_function.c\
	sort_args_func.c\
	read_all.c\
	get_width.c\
	full_print.c\
	print_permissions.c\
	handle_error.c\
	full_print_node.c

HEADER_FILE = ./inc/ft_ls.h
SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./inc

SRC = $(addprefix $(SRC_DIR)/, $(FILENAMES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILENAMES:.c=.o))

FLAGS		= -Wall -Werror -Wextra
LIBFT		= ./libs/libft/libft.a
LIBFT_DIR	= ./libs/libft
INCLUDES	= -I ./libs/libft\
			  -I ./inc
LIBRARIES	= -L ./libs/libft -lft

DELAY = 0

all : $(NAME)
$(NAME): $(LIBFT) $(OBJ)
	@echo "$(CC) $(_lYELLOW)$(FLAGS)$(_END) $(_lCYAN)$(OBJ)$(_END)\n$(_lGREEN)$(LIBRARIES)$(_END)   -I$(_RED)$(INC_DIR)$(_END)$(_RED)$(INCLUDES)$(_END) -o $(_lBLUE)$(NAME)$(_lEND)$(_RED)\n"
	@$(CC) $(FLAGS) $(OBJ) $(LIBRARIES) $(INCLUDES) -o $(NAME)
$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADER_FILE) | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@ -I  $(INC_DIR) $(INCLUDES)
$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
$(LIBFT):
	@make -C $(LIBFT_DIR)
clean:
	@echo "\n$(_lCYAN)Makefile :$(_END) will delete $(_RED)$(OBJ) $(VIS_OBJ)$(_END)"
	@echo "starting in $(DELAY) sec, $(_RED)press Ctrl-c to abort$(_END)"
	@sleep $(DELAY)
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
fclean: clean
	@echo "\n$(_lCYAN)Makefile :$(_END) will delete $(_RED)$(NAME)$(_END)"
	@echo "starting in $(DELAY) sec, $(_RED)press Ctrl-c to abort$(_END)"
	@sleep $(DELAY)
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
re: fclean all
