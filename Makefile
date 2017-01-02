# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdugot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 12:08:51 by mdugot            #+#    #+#              #
#    Updated: 2017/01/02 09:38:26 by cdrouet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= computer
CC= gcc
CFLAGS= -Wall -Werror -Wextra
SRC_NAME= main.c \
		  unknownsListFunctions.c
SRC_PATH= ./sources/
INC_PATH= ./includes/
LIB_NAME= libftprintf.a
LIB_ID= ftprintf
LIB_PATH= ./libft/
LIB_INC= ./libft/
OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ_PATH= ./obj/
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIB= $(addprefix $(LIB_PATH), $(LIB_NAME))

.PHONY: all
all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS)  -L$(LIB_PATH) -I$(INC_PATH) -o $(NAME) -l$(LIB_ID) $(OBJ)

$(LIB):
	make re -C $(LIB_PATH)

.PHONY: libft
libft:
	make re -C $(LIB_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) -I$(INC_PATH) -I$(LIB_INC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -fv $(OBJ)
	@rm -rf $(OBJ_PATH)
	make $@ -C $(LIB_PATH)

.PHONY: fclean
fclean: clean
	rm -fv $(NAME)
	make $@ -C $(LIB_PATH)

.PHONY: re
re: fclean all
