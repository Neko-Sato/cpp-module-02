# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 17:27:29 by hshimizu          #+#    #+#              #
#    Updated: 2024/03/30 10:15:45 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Fixed

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror
CXXFLAGS	+= -std=c++98 -pedantic

SRCS		= main.cpp
SRCS		+= Fixed.cpp

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: clean
clean: $(NAME)
	rm -f $^
