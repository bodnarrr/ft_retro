# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abodnar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/16 12:17:53 by abodnar           #+#    #+#              #
#    Updated: 2018/04/08 23:28:50 by abodnar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_retro

SRCS =	main.cpp Screen.class.cpp Ship.class.cpp Game.class.cpp Bullet.class.cpp \
		Enemy.class.cpp EnemyGen.class.cpp

OBJECTS = $(SRCS:.cpp=.o)

FLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

%.o : %.cpp
	@g++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@g++ -g -lncurses -o $@ -I. $(OBJECTS) $(LIB) -fsanitize=address
	@echo "\033[1;32mGame is ready, my sir!\033[0m"

clean:
	@rm -f *.o
	@echo "\033[1;32mObject files were removed\033[0m"

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
