/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 09:31:15 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/19 12:48:22 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_status	*init_struct(t_list_ps *lst_a)
{
	t_status	*stats;

	stats = ft_calloc(sizeof(t_status), 1);
	stats->lsta_c = list_count(lst_a);
	stats->piv_c = 0;
	stats->p_f = 0;
	stats->op_c = 0;
	stats->piv1 = 0;
	stats->piv2 = 0;
	stats->count_max_val = 0;
	return (stats);
}

/*
counts the indexes in descending order from max_index on, 
until max_index is found.
i.e. index_max -> index_max - 1 -> index_max - 2, ...
Returns the count of the found elements.
Needed to get the proper malloc size of the array max_values in
function descending_max_values
*/

int	count_descending_max_values(t_list_ps *lst_b)
{
	int	count;
	int	compare_value;

	compare_value = lst_b->index;
	count = 0;
	while (1)
	{
		if (lst_b->index - compare_value == 1)
		{
			compare_value = lst_b->index;
			count++;
		}
		else if (lst_b->index - compare_value > 1)
		{
			count = 0;
			compare_value = lst_b->index;
		}
		if (lst_b->index == find_max_index(lst_b))
			return (count);
		lst_b = lst_b->next;
	}
	return (count);
}

/*
this function is used for building the max_values array.
Kind of sourcing out bc of norminette

*/
int	*build_max_values(int *max_values, int comp_val, t_list_ps *lst_b)
{
	int	i;

	i = 0;
	while (1)
	{
		if (lst_b->index - comp_val == 1)
		{
			max_values[i] = comp_val;
			comp_val = lst_b->index;
			i++;
		}
		else if (lst_b->index - comp_val > 1)
		{
			comp_val = lst_b->index;
			i = 0;
		}
		if (lst_b->index == find_max_index(lst_b))
		{
			max_values[i] = find_max_index(lst_b);
			return (max_values);
		}
		lst_b = lst_b->next;
	}
}
/*
looks for indexes in descending order from max_index on,
until max_index is found.
i.e. index_max -> index_max - 1 -> index_max - 2, ...
Returns the index values of the found elements.
Goal is to push the values into stack A, so Stack B has to be rotated less.
*/

int	*descending_max_values(t_list_ps *lst_b)
{
	int	count_max_values;
	int	compare_value;
	int	*max_values;

	count_max_values = count_descending_max_values(lst_b);
	max_values = ft_calloc((count_max_values + 10), sizeof(int *));
	if (count_max_values == 0)
	{
		max_values[0] = find_max_index(lst_b);
		return (max_values);
	}
	else
	{
		compare_value = lst_b->index;
		max_values = build_max_values(max_values, compare_value, lst_b);
		return (max_values);
	}
}

/*
checks if lst_a is sorted
*/
int	sort_check(t_list_ps *lst_a, t_list_ps *lst_b)
{
	if (lst_a && !lst_b)
	{
		while (lst_a->next != NULL)
		{
			if (lst_a->content >= lst_a->next->content)
				return (0);
			lst_a = lst_a->next;
		}
		return (1);
	}
	else
		return (0);
}
