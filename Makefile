# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 04:31:34 by tel-mouh          #+#    #+#              #
#    Updated: 2022/08/20 06:06:38 by tel-mouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash # Use bash syntax

# #################HEADERS###########################
HEADERS = 
HEADERS := $(addprefix include/, $(HEADERS))
# #################HEADERS_utils###########################
UHEADERS = 
UHEADERS := $(addprefix include/, $(UHEADERS))

# ################COMMANDS###########################

RM = rm -rf
CC = gcc 
CFLAG = -g -pthread -Wall -Werror -Wextra -I include 

# ################SRCS_Objs##########################

SRC = main.c queue.c
OBJ = $(addprefix obj/, $(SRC:.c=.o))

# ################SRCS_Objs_Utils####################

SRC_UTILS = 
OBJ_UTILS = $(addprefix obj/utils/, $(SRC_UTILS:.c=.o))

# ################COLOR##############################

COLOR='\033[0;32m'
NC='\033[0m'
RE= '\033[0;34m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'

# #################bar_line##############################

lines=$(shell tput lines)
cols=$(shell tput cols)
num=$(shell echo `ls src/*.c | wc -l`)
i_num:=$(shell expr $(cols) / $(num))
i_num:=$(shell expr $(i_num) / 2)
x  = -1
CODE_SAVE_CURSOR='\033[s'
CODE_RESTORE_CURSOR='\033[u'
CODE_CURSOR_IN_SCROLL_AREA="\033[1A"

# ###############executable##########################

NAME = ./name
LIBFT = libft/library/libft.a
ILIBFT = libft/include

# ###################################################

all : $(NAME)

$(NAME): $(OBJ) $(OBJ_UTILS)
	@ printf "\033[$(lines);0f"
	@ tput el
	@printf  ${CODE_RESTORE_CURSOR}""
	@tput el
	@ printf ${GREEN}"\rMaking is done ✅\n"${NC}
	@ $(CC) $(CFLAG) $(OBJ) $(OBJ_UTILS) -lreadline -o $(NAME)
	@ tput cvvis



obj/%.o : src/%.c  $(HEADERS) 
	@ mkdir -p obj
	@ mkdir -p obj/utils
	$ nu=$x ; if [[ $$nu -eq -1 ]] ; then \
	printf ${RE}"🔷 Making the  --> "${NC} \
	 ; fi
	@ $(CC) $(CFLAG) -c $< -o $@
	@tput civis
	$(eval x=$(shell expr $(x) + $(i_num) ))
	@ printf $(notdir $@)"\n"
	@ printf  ${CODE_SAVE_CURSOR}""
	@ printf "\033[$(lines);0f"
	@number=$x ; while [[ $$number -ge 0 ]] ; do \
        printf ${YELLOW}"🟩"${NC}  ;\
        ((number = number - 1)) ; \
    done
	@printf  ${CODE_RESTORE_CURSOR}""
	@printf  ${CODE_CURSOR_IN_SCROLL_AREA}""
	@printf  ${CODE_SAVE_CURSOR}""
	@printf ${RE}"🔷 Making the  --> "${NC} 
	@tput el

clean :
	@ $(RM) $(OBJ)
	@ $(RM) $(OBJ_UTILS)

fclean : clean
	@ $(RM) $(NAME)

re : 
	@make fclean
	@make all