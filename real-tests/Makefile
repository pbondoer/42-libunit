# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/31 04:57:48 by pbondoer          #+#    #+#              #
#    Updated: 2017/02/12 22:44:05 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft_test

SRC_DIR		:= ./src
INC_DIR		:= ./includes
OBJ_DIR		:= ./obj

RAW_SRC		:= $(shell find $(SRC_DIR) -type f | grep -E "\.c$$")
RAW_DIRS	:= $(shell find $(SRC_DIR) -type d -mindepth 1)
SRC_DIRS	:= $(RAW_DIRS:$(SRC_DIR)/%=%)
SRC			:= $(RAW_SRC:$(SRC_DIR)/%=%)
OBJ			:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra -pedantic -std=c99

LIB_LNK		:=
LIB_INC		:=

L_FT		:= ../libft
L_UNIT		:= ../framework
include $(L_FT)/libft.mk
include $(L_UNIT)/libunit.mk

.PHONY: all clean fclean re test

all:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(addprefix $(OBJ_DIR)/,$(SRC_DIRS))
	@$(MAKE) -C $(L_FT) --no-print-directory
	@$(MAKE) -C $(L_UNIT) --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB_LNK) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

test:
	@$(MAKE) all -s --no-print-directory
	@./libft_test
