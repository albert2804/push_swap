# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 13:20:07 by aestraic          #+#    #+#              #
#    Updated: 2022/11/24 16:03:18 by aestraic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
#MAKEFILE += --no-builtin-rules

SRC = 	utils_libft.c\
		utils_index.c\
		utils_quicksort.c\
		utils_optimisation.c\
		utils.c\
		utils2.c\
		utils3.c\
		rotate.c\
		rotate2.c\
		swap.c\
		push.c\
		input.c\
		input2.c\
		sort.c\
		push_swap.c
		
SRC_B = utils_libft.c\
		utils_index.c\
		utils_quicksort.c\
		utils_optimisation.c\
		utils.c\
		utils2.c\
		utils3.c\
		rotate.c\
		rotate2.c\
		swap.c\
		push.c\
		input.c\
		input2.c\
		sort.c\
		src/gnl/get_next_line_utils.c\
		src/gnl/get_next_line.c\
		checker.c

 
INPUT = 1 2 3


OBJ   = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

HEADER_PATH = header
LIB_PATH = lib
LIB = $(LIB_PATH)/libft.a
SRC_PATH = src
OBJ_PATH = obj
C_FLAGS = -Wall -Wextra -Werror


all:    $(NAME)
bonus:  $(BONUS)

%.o : %.c
	gcc -g $(C_FLAGS) -I$(HEADER_PATH) -c $^
	
$(NAME): $(LIB) $(OBJ)
	gcc -g $(C_FLAGS) -I$(HEADER_PATH) $(OBJ) -L$(LIB_PATH) -lft -o $(NAME)

$(BONUS): $(LIB) $(OBJ_B)
	gcc -g $(C_FLAGS) -I$(HEADER_PATH) $(OBJ_B) -L$(LIB_PATH) -lft -o $(BONUS)

$(LIB):
	@mkdir -p $(LIB_PATH)
#	@echo MAKE LIBFT
	@make all -C	$(SRC_PATH)/libft
	
#	@echo MAKE PRINTF
	@make all -C	$(SRC_PATH)/ft_printf

#	@echo MAKE GNL	
	@make all -C	$(SRC_PATH)/gnl
	
val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(INPUT)

move:
	@make move -C	$(SRC_PATH)/libft
	@make move -C	$(SRC_PATH)/ft_printf
	@mv $(OBJ)$^ $(OBJ_PATH)
	@echo Moved Objectfiles into /$(OBJ_PATH)

clean:
	@rm -f $(OBJ) $(OBJ_B) $(NAME) $(BONUS)
	@echo Objectfiles removed

fclean: clean
	@make fclean -C $(SRC_PATH)/libft
	@make fclean -C $(SRC_PATH)/ft_printf
	@rm -f $(NAME) $(BONUS)
	@echo Libraries and exeutables removed
	
re: fclean all
	@echo REDONE

.PHONY: clean fclean re obj exec library