# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 13:20:07 by aestraic          #+#    #+#              #
#    Updated: 2022/08/18 16:39:11 by aestraic         ###   ########.fr        #
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
		swap.c\
		push.c\
		input.c\
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
		swap.c\
		push.c\
		input.c\
		sort.c\
		src/gnl/get_next_line_utils.c\
		src/gnl/get_next_line.c\
		checker.c


INPUT = 313 -569 928 -395 -251 -824 -96 -936 480 -48 -559 379 238 -776 872 -853 -523 -20 37 -878 -549 -278 706 -382 -280 -708 -842 -17 -49 -989 583 -724 908 21 -477 -415 -234 686 237 242 -555 987 -664 610 743 -360 994 907 280 -676 385 116 -655 -639 -706 343 362 263 -425 -681 997 -233 -195 735 40 -785 812 265 -159 384 -336 -713 -145 -736 302 -245 -476 -910 593 895 -237 -731 310 -631 482 -831 707 -735 -305 190 -311 -100 374 -726 923 -337 446 564 74 654


OBJ   = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

HEADER_PATH = header
LIB_PATH = lib
SRC_PATH = src
OBJ_PATH = obj
C_FLAGS = -Wall -Wextra -Werror

all:   library obj $(NAME)
bonus: library obj_b $(BONUS)

obj: $(OBJ)
obj_b: $(OBJ_B)

%.o : %.c
	gcc -g $(C_FLAGS) -I$(HEADER_PATH) -c $^
	
$(NAME): $(OBJ)
	gcc -g $(C_FLAGS) -I$(HEADER_PATH) $(OBJ) -L$(LIB_PATH) -lft -o $(NAME)

$(BONUS): $(OBJ_B)
	gcc -g $(C_FLAGS) -I$(HEADER_PATH) $(OBJ_B) -L$(LIB_PATH) -lft -o $(BONUS)

library:
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