# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouloube <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 10:21:15 by aouloube          #+#    #+#              #
#    Updated: 2016/01/11 17:38:37 by aouloube         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re
NAME = fdf
CC = gcc -o
SRCS = fdf.c
CFLAGS = -Wall -Werror -Wextra -I libft/includes -L libft/ -lft
MLX = -lmlx -framework OpenGL -framework AppKit -L minilibx
OBJS = fdf.o
LIBFT =   make -C libft/ fclean  -s  && make -C libft/ -s

RM = rm -rf

all: $(NAME)

$(NAME):
	@$(LIBFT)
	@echo "\033[33;35m |*******************************| \033[33;0m"
	@echo "\033[33;35m |*              FDF            *| \033[33;0m"
	@echo "\033[33;35m |*******************************| \033[33;0m"
	@$(CC) $(NAME) $(CFLAGS) $(SRCS)  $(MLX)
	@echo "\033[33;35m |*            GCC       OK [✓] *| \033[33;0m"
	@echo "\033[33;35m |*                             *| \033[33;0m"
	@echo "\033[33;35m |* =======  COMPLETED 😎  ===== *| \033[33;0m"
	@echo "\033[33;35m |*                             *| \033[33;0m"
	@echo "\033[33;35m |*******************************| \033[33;0m \n"
clean:
	@$(RM) $(NAME)

fclean: clean
	@echo "\033[33;35m |*******************************| \033[33;0m"
	@echo "\033[33;35m |*          FDF - CLEAN        *| \033[33;0m"
	@echo "\033[33;35m |*******************************| \033[33;0m"
	@$(RM) $(NAME)
	@echo "\033[33;35m |*                             *| \033[33;0m"
	@echo "\033[33;35m |* =======  ALL CLEAN 🚮  ===== *| \033[33;0m"
	@echo "\033[33;35m |*                             *| \033[33;0m"
	@echo "\033[33;35m |*******************************| \033[33;0m \n"

re: fclean all
