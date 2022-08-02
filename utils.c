/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:30:47 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/02 13:45:37 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	printList(t_list_ps *lst)
{
	t_list_ps	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		ft_printf("%d->", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("NULL\n");
}

void	printIndex(t_list_ps *lst)
{
	t_list_ps	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		ft_printf("%d->", tmp->index);
		tmp = tmp->next;
	}
	ft_printf("NULL\n");
}

int	list_count(t_list_ps *lst)
{
	t_list_ps	*temp;
	int			i;

	i = 1;
	temp = lst;
	while (temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}	
	return (i);
}

/*
checks if lst_a is sorted
*/
int	sort_check(t_list_ps *lst_a)
{
	t_list_ps	*temp;

	temp = lst_a;
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	print_status(t_status *stats)
{
	ft_printf("List A Count: %d\n", stats->lista_count);
	ft_printf("Pivot Count: %d\n", stats->pivot_count);
	ft_printf("Operations Count: %d\n", stats->opcount);
	ft_printf("PrintFlag: %d\n", stats->print_flag);
}

t_status	*init_struct(t_list_ps *lst_a)
{
	t_status	*stats;

	stats = malloc(sizeof(t_status));
	stats->lista_count = list_count(lst_a);
	stats->pivot_count = 0;
	stats->print_flag = 0;
	stats->opcount = 0;
	stats->piv1 = 0;
	stats->piv2 = 0;
	stats->count_max_val = 0;
	return (stats);
}

/*
checks if lst should be rotated or reverse_rotated.
if 1 that means reverse_rotating
0 means rotating list is better.
*/
int	rotate_or_rrotate(t_list_ps *lst_b, int index)
{
	int	count;
	int	lcount;

	count = 0;
	lcount = list_count(lst_b);
	while (lst_b->index != index)
	{
		lst_b = lst_b->next;
		count ++;
	}
	if (count > lcount / 2)
		return (0);
	else
		return (1);
}

/*
counts the indexes in descending order from max_index on, until max_index is found.
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
int	*build_max_values(int *max_values, int compare_value, t_list_ps *lst_b)
{
	int	i;

	i = 0;
	while (1)
	{
		if (lst_b->index - compare_value == 1)
		{
			max_values[i] = compare_value;
			compare_value = lst_b->index;
			i++;
		}
		else if (lst_b->index - compare_value > 1)
		{
			compare_value = lst_b->index;
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
looks for indexes in descending order from max_index on, until max_index is found.
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
	max_values = ft_calloc(count_max_values + 1, sizeof(int));
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
