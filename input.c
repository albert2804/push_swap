/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:22:07 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/17 14:19:44 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
cheks if a string is containing only digits
*/
void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
}

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
		if (ft_strisdigit(split_str[i]) == 1 && ft_atoi(split_str[i]) < INT_MAX \
		&& ft_atoi(split_str[i]) > INT_MIN)
		{
			elem = ft_atoi(split_str[i]);
			new_node = ft_lstnew_ps(elem, 0);
			ft_lstadd_back_ps(&lst_a, new_node);
			i ++;
		}
		else
			break ;
	}
	if (split_str[i] != NULL)
		ft_lstclear_ps(&lst_a);
	ft_free_split(split_str);
	return (lst_a);
}

/*
build Stack A depending on the input data, if it is one of the following
input:
1) ./test.out 1 2 3 4
2) ./test.out $arg
*/
t_list_ps	*read_in(t_list_ps *lst_a, int nbr_arg, char **argv)
{
	int			i;

	i = 0;
	while (++i < nbr_arg)
	{
		lst_a = build_stack_from_argv(lst_a, argv[i]);
		if (lst_a == NULL)
			break ;
	}
	return (lst_a);
}

/*
hadnles errors like letters or an already sorted stack, 
l is shoort for lst_a
h is short for head which got sourced out bc of norminette
*/
int	check_wrong_or_sorted(int n, char **a, t_list_ps *l, t_list_ps *h)
{
	t_list_ps	*tmp;

	tmp = NULL;
	l = read_in(l, n, a);
	if (l == NULL || sort_check(l) == 1)
		return (1);
	tmp = l;
	h = l;
	while (h->next)
	{
		l = h->next;
		while (l)
		{
			if (h->content == l->content)
			{
				ft_lstclear_ps(&tmp);
				return (1);
			}
		l = l->next;
		}
	h = h->next;
	}
	ft_lstclear_ps(&tmp);
	return (0);
}
