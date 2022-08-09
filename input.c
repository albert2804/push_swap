/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:22:07 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/09 09:26:37 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
-reads the input $ARG and use the split function on $ARG, returns a **char.
*/
char	**read_input(char *str)
{
	char	**split_string;

	split_string = ft_split(str, ' ');
	return (split_string);
}

/*
build Stack A1 from the input argv[1], from e.g. $arg = "1 2 3 4"
the index will be initalized 0 for all the elements
Either work with double pointer or return value
*/
t_list_ps	*build_stack_from_argv(t_list_ps *lst_a, char *str)
{
	t_list_ps	*new_node;
	char		**split_str;
	int			elem;
	int			i;

	i = 0;
	split_str = read_input(str);
	while (split_str[i] != NULL)
	{
		elem = ft_atoi(split_str[i]);
		new_node = ft_lstnew_ps(elem, 0);
		ft_lstadd_back_ps(&lst_a, new_node);
		i ++;
	}
	free(split_str);
	return (lst_a);
}

// void	build_stack_from_argv(t_list_ps **lst_a, char *str)
// {
// 	t_list_ps	*new_node;
// 	char		**split_str;
// 	int			elem;
// 	int			i;

// 	i = 0;
// 	split_str = read_input(str);
// 	while (split_str[i] != NULL)
// 	{
// 		elem = ft_atoi(split_str[i]);
// 		new_node = ft_lstnew_ps(elem, 0);
// 		ft_lstadd_back_ps(lst_a, new_node);
// 		i ++;
// 	}
// 	free(split_str);
// }

/*
build Stack A depending on the input data, if it is one of the following
input:
1) ./test.out 1 2 3 4
2) ./test.out $arg
Either work with double pointer or return value
*/
t_list_ps	*read_in(t_list_ps *lst_a, int nbr_arg, char **argv)
{
	int			i;

	i = 0;
	if (nbr_arg == 1)
	{
		ft_printf("Error");
		exit(0);
	}
	while (++i < nbr_arg)
		lst_a = build_stack_from_argv(lst_a, argv[i]);
	return (lst_a);
}

// void	read_in(t_list_ps **lst_a, int nbr_arg, char **argv)
// {
// 	int			i;

// 	i = 0;
// 	if (nbr_arg == 1)
// 	{
// 		ft_printf("Error");
// 		exit(0);
// 	}
// 	while (++i < nbr_arg)
// 		build_stack_from_argv(lst_a, argv[i]);
// }