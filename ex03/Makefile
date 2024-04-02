# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 17:27:29 by hshimizu          #+#    #+#              #
#    Updated: 2024/04/03 03:33:18 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bsp

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -g
CXXFLAGS	+= -std=c++98 -pedantic

SRCS		= main.cpp
SRCS		+= Fixed.cpp
SRCS		+= Point.cpp
SRCS		+= bsp.cpp

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: clean
clean: $(NAME)
	rm -f $^
