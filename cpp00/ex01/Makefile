# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 17:12:05 by lnicoter          #+#    #+#              #
#    Updated: 2023/12/20 20:05:53 by lnicoter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

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
