# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 13:20:07 by aestraic          #+#    #+#              #
#    Updated: 2022/08/09 09:33:18 by aestraic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = 	utils_libft.c\
		push_swap.c\
		utils_index.c\
		utils_quicksort.c\
		utils_optimisation.c\
		utils.c\
		utils2.c\
		rotate.c\
		swap.c\
		push.c\
		input.c

OBJ  = $(SRC:.c=.o)

HEADER_PATH = header
LIB_PATH = lib
SRC_PATH = src
OBJ_PATH = obj
C_FLAGS = #-Wall -Wextra -Werror

all:  library obj $(NAME)

obj: $(OBJ)

%.o : %.c
	cc $(C_FLAGS) -I$(HEADER_PATH) -c $^ 
	
$(NAME): $(OBJ)
	cc $(C_FLAGS) -I$(HEADER_PATH) $(COMPILED_SRC) $^ -L$(LIB_PATH) -lft -o $(NAME)

library:
#	@echo MAKE LIBFT
	@make all -C	$(SRC_PATH)/libft
	
#	@echo MAKE PRINTF
	@make all -C	$(SRC_PATH)/ft_printf

move:
	@make move -C	$(SRC_PATH)/libft
	@make move -C	$(SRC_PATH)/ft_printf
	@mv $(OBJ)$^ $(OBJ_PATH)
	@echo Moved Objectfiles into /$(OBJ_PATH)

clean:
	@make clean -C $(SRC_PATH)/libft
	@make clean -C $(SRC_PATH)/ft_printf
	@rm -f $(OBJ)
	@echo Objectfiles removed

fclean: clean
	@make fclean -C $(SRC_PATH)/libft
	@make fclean -C $(SRC_PATH)/ft_printf
	@rm -f $(NAME)
	@echo Libraries and exeutables removed
	
re: fclean all
	@echo REDONE

.PHONY: clean fclean re obj exec library