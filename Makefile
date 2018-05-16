# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshiling <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 13:01:36 by sshiling          #+#    #+#              #
#    Updated: 2017/10/11 23:20:04 by sshiling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cut_pizza

SRCS =	main.c \
		generate_pizza.c \
		reader.c \
		general.c \
		cut_pizza.c

LIBFT = libft/

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = gcc

%.o: %.c
	@$(CC) $(FLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -L $(LIBFT) -lftprintf
	@echo "All .o files successfully created."
	@echo "Cut_pizza successfully created."

clean:
	@echo "Deleting all .o files. Please wait..."
	@rm -f $(OBJECTS)
	@make clean -C $(LIBFT)
	@echo "All .o files deleted."


fclean: clean
	@echo "Deleting all .o files and cut_pizza. Please wait..."
	@rm -f $(NAME) $(OBJECTS)
	@make fclean -C $(LIBFT)
	@echo "All .o files and cut_pizza deleted."
	

re: fclean all

.PHONY: re all clean fclean
