# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 18:19:40 by ojacobs           #+#    #+#              #
#    Updated: 2025/01/27 18:23:40 by ojacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Name of the output program
NAME = The_Job_Of_Your_Dreams

# List of source files
SRCS = tests.cpp Account.cpp

# List of object files (same as source files but with .o extension)
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(NAME)

# Rule to create the executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Rule to compile .cpp files into .o object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS)

# Full clean, removing object files and the executable
fclean: clean
	rm -f $(NAME)

# Rule to clean and rebuild the project
re: fclean all

# Phony targets to avoid conflicts with filenames
.PHONY: all clean fclean re
