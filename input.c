/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:22:07 by aestraic          #+#    #+#             */
/*   Updated: 2022/06/27 16:45:37 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <push_swap.h>

/*
-reads the input $ARG and use the split function on $ARG, returns a **char.
*/
static char **read_input(char *str)
{
	char **split_string;

	split_string = ft_split(str, ' ');
	return(split_string);
}

/*
build Stack A1 from the input argv[1], from e.g. $arg = "1 2 3 4"
the index will be initalized 0 for all the elements
*/
t_list_ps *build_stack_A1(char *str)
{
	t_list_ps *lst_a;
	char **split_str;
	int elem;
	t_list_ps *new_node;
	int i;
	
	i = 1;
	split_str = read_input(str);
	elem = ft_atoi((split_str[0]));
	lst_a = ft_lstnew_ps(elem, 0);
	while(split_str[i] != NULL)
	{
		elem = ft_atoi(split_str[i]);
		new_node = ft_lstnew_ps(elem, 0);
		ft_lstadd_back_ps(&lst_a, new_node);
		i ++;
	}
	return (lst_a);
}

/*
build Stack A2 from the input argv[1], from e.g. ./test.out 1 2 3 4
the index will be initalized 0 for all the elements
*/
t_list_ps *build_stack_A2(char **argv)
{
	t_list_ps *lst_a;
	int elem;
	t_list_ps *new_node;
	int i;
	
	i = 2;
	elem = ft_atoi((argv[1]));
	lst_a = ft_lstnew_ps(elem, 0);
	while(argv[i] != NULL)
	{
		elem = ft_atoi(argv[i]);
		new_node = ft_lstnew_ps(elem, 0);
		ft_lstadd_back_ps(&lst_a, new_node);
		i ++;
	}
	return (lst_a);
}

/*
build Stack A depending on the input data, if it is one of the following
input:
1) ./test.out 1 2 3 4
2) ./test.out $arg
*/
