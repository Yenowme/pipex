# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 18:54:27 by jeong-yena        #+#    #+#              #
#    Updated: 2022/01/19 19:16:28 by jeong-yena       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= so_long

CC						= gcc
CFLAGS					= -Wall -Werror -Wextra
AR						= ar rcs
RM						= rm -f

LIBFT_DIR				= ./libft/
LIBFT_FLAGS				= -L ./$(LIBFT_DIR) -lft
LIBFT_FILE				= $(LIBFT_DIR)libft.a

INCS_DIR				= ./include/
SRCS_DIR				= ./src/
INCS					= -I include

SRC						= main.c 
SRCS					= $(addprefix $(SRCS_DIR), $(SRC))
OBJS					= $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(GNL_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) $(GNL_FLAGS) $(LIBFT_FLAGS) -I $(INCS_DIR)

all : $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS) $(BONUS_OBJS) a.out.dSYM

fclean : clean
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	$(RM) $(NAME) $(BONUS_OBJS) $(BONUS_NAME) a.out.dSYM

re : fclean all

test :
	make -C $(LIBFT_DIR)
	$(CC) -g -o $(NAME) $(SRCS) $(GNL_FLAGS) $(LIBFT_FLAGS) -I $(INCS_DIR)

leak :
	make -C $(LIBFT_DIR)
	$(CC) -g3 -fsanitize=address -o $(NAME) $(SRCS) $(GNL_FLAGS) $(LIBFT_FLAGS) -I $(INCS_DIR)

norm :
	norminette $(SRCS) $(BONUS_SRCS) $(INCS_DIR) $(BONUS_INCS_DIR)

PHONY	: all clean fclean re bonus
