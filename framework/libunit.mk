# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libunit.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/31 05:24:55 by pbondoer          #+#    #+#              #
#    Updated: 2017/02/11 07:16:56 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Base variables for libunit
# Use with 'include /path/to/libunit.mk'
# Make sure to define L_UNIT with path to libunit first

L_UNIT		?= .

UNIT_NAME	:= libunit.a

UNIT_LNK	:= -L $(L_UNIT) -l unit
UNIT_INC	:= -I $(L_UNIT)/includes
UNIT_LIB	:= $(L_UNIT)/$(UNIT_NAME)

# Global variables for compilation
ifndef LIB_LNK
LIB_LNK		:=
LIB_INC		:=
endif

LIB_LNK		+= $(UNIT_LNK)
LIB_INC		+= $(UNIT_INC)
