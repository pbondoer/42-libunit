# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 21:02:30 by pbondoer          #+#    #+#              #
#    Updated: 2017/04/16 16:56:15 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include libunit.mk

SRC_DIR	= ./src
INC_DIR	= ./includes
OBJ_DIR	= ./obj

RAW_SRC	:=	suite.c \
			list.c \
			run.c \
			printf.c \
			io.c

SRCDIRS := $(RAW_DIRS:$(SRC_DIR)/%=%)
SRC		:= $(RAW_SRC:$(SRC_DIR)/%=%)
OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -pedantic -std=c99
CFLAGS	+= -O3 -march=native -pipe -flto

DEBUG	:= 0
ifeq ($(DEBUG),1)
CFLAGS	+= -g -fsanitize=address
endif

L_FT	:= ../libft
include $(L_FT)/libft.mk

.PHONY: all clean fclean re

all:
	mkdir -p $(OBJ_DIR)
	@$(MAKE) $(FT_NAME) --no-print-directory
	@$(MAKE) $(UNIT_NAME) --no-print-directory

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(LIB_INC) $(UNIT_INC) -o $@ -c $<

$(FT_NAME):
	@$(MAKE) -C $(L_FT) --no-print-directory

$(UNIT_NAME): $(OBJ)
	ar rc $(UNIT_NAME) $(OBJ)
	ranlib $(UNIT_NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(UNIT_NAME)

re:
	@$(MAKE) -C $(L_FT) fclean --no-print-directory
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory
