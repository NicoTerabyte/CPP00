# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 19:25:34 by lnicoter          #+#    #+#              #
#    Updated: 2024/01/17 14:10:37 by lnicoter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animals

CC = g++

FLAGS = -Wall -Werror -Wextra -std=c++98 -g

SOURCE = $(wildcard *.cpp) \

OBJS = $(SOURCE:.cpp=.o)

all: $(NAME)

%.o : %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@g++ $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
