# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 13:20:07 by aestraic          #+#    #+#              #
#    Updated: 2022/08/19 15:34:17 by aestraic         ###   ########.fr        #
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


INPUT = -432 -635 497 -1000 -838 624 -482 978 -336 -815 -995 148 -177 -342 -914 457 343 -455 -470 813 259 -602 -107 60 -561 942 499 838 -605 393 699 -726 -570 -337 -434 790 -783 543 -2 943 743 -691 920 597 -795 1 593 -743 -598 711 224 480 -475 -108 -507 -329 681 -534 851 50 123 955 874 -357 -641 116 -366 726 -287 338 -123 -569 839 -512 661 -712 -163 919 503 459 479 492 769 435 650 -461 662 -775 995 509 -595 -640 -788 522 590 821 -879 738 -370 -67


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