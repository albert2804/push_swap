# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 13:20:07 by aestraic          #+#    #+#              #
#    Updated: 2022/07/20 18:34:41 by aestraic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =  push_swap.c utils_libft.c utils.c rotate.c swap.c push.c utils_index.c

TEST = 	test.c \
		utils_libft.c\
		utils_index.c\
		utils_quicksort.c\
		utils.c\
		rotate.c\
		swap.c\
		push.c\
		input.c

all:
	cc -Wall -Wextra -Werror -I header -L bib -l ft $(SRC) -o $(NAME)

test: 
	cc -Wall -Wextra -Werror -I header -L bib -l ft $(TEST) -o test.out
val:
	valgrind --leak-check=full --show-leak-kinds=all header/*.h bib/*.a $(TEST)
clean:
	rm -f test.out

fclean: clean
	rm -f $(NAME) test.out
	
re: fclean all

.PHONY: clean fclean re bonus