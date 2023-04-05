# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 14:49:04 by jdias-mo          #+#    #+#              #
#    Updated: 2023/03/09 17:16:30 by jdias-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			fixed02

SRC =			$(addsuffix .cpp,	main \
									Fixed)

INC_DIR =		inc/

SRC_DIR =		src/

OBJ_DIR =		obj/

OBJ =			$(addprefix $(OBJ_DIR), $(patsubst %.cpp, %.o, $(SRC)))

INC =			-I$(INC_DIR)

CC =			c++

CFLAGS =		-Wall -Werror -Wextra -std=c++98 -fsanitize=address

RM =			rm -f

all:			$(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
				$(CC) $(CFLAGS) -c $(<) -o $(@) $(INC)

$(OBJ_DIR):
				mkdir $(OBJ_DIR)

$(NAME):		$(OBJ_DIR) $(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
				$(RM) $(OBJ) -r $(OBJ_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
