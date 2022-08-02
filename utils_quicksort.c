/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:30:47 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/02 11:17:27 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
find varible pivot elements from unsorted stack a
goal is to divide the list in different areas
*/
int *pivotvalues(t_status *stats)
{
	int *pivot_values;
	int i;

	i = 1;
	pivot_values = malloc(sizeof(int) * stats->pivot_count);
	pivot_values[0] = stats->lista_count/(stats->pivot_count + 1);
	while (i < stats->pivot_count)
	{
		pivot_values[i] = stats->lista_count/(stats->pivot_count + 1) * (i + 1);
		i++;
	}
	return(pivot_values);
}

/*
checks if the current index and descending values fromt that index
in Stack B are pushable. If Yes the function returns 1.
Else Stack B has to be rotated, until check for push returns 1.
*/
int check_for_push(t_list_ps *lst_b)
{
	int max_index;
	int flag;

	max_index = find_max_index(lst_b);
	flag = count_descending_max_values(lst_b);
	if (flag != 0 || lst_b->index == max_index)
		return (1);
	return (0);
}

void push_values(t_list_ps **lst_a, t_list_ps **lst_b, int *max_val, t_status *stats)
{
	int i;
	
	i = 0;
	while (i <= stats->count_max_val)
	{
		if ((*lst_b)->index == max_val[i])
		{
			stats->opcount = stats->opcount + push_a(lst_a, lst_b, stats->print_flag);
			stats->opcount = stats->opcount + rotate_a(lst_a, stats->print_flag);
			i++;
		}
		else if (rotate_or_rrotate(*lst_b, max_val[i]) == 1)
			stats->opcount = stats->opcount + rotate_b(lst_b, stats->print_flag);
		else if (rotate_or_rrotate(*lst_b, max_val[i]) == 0)
			stats->opcount = stats->opcount + rotate_rev_b(lst_b, stats->print_flag);
	}
	if (i > 1)
	{
		while (--i > -1)
			stats->opcount = stats->opcount + rotate_rev_a(lst_a, stats->print_flag);
	}
}