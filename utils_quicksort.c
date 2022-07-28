/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:30:47 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/28 15:08:24 by aestraic         ###   ########.fr       */
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
single pivotisation
*/
void pivotisation(t_list_ps **lst_a, t_list_ps **lst_b, int piv1, int piv2, t_status *stats)
{
	int count_lsta;
	int len_lsta;

	count_lsta = 0;
	len_lsta = list_count(*lst_a);
	while(count_lsta < len_lsta)
	{
		if ((*lst_a)->index >= piv1 && (*lst_a)->index <= piv2)
			{
			stats->opcount = stats->opcount + push_b(lst_a, lst_b, stats->print_flag);
			if ((*lst_b)->next && (*lst_b)->next->index - (*lst_b)->index == -1)
				stats->opcount = stats->opcount + swap_b(lst_b, stats->print_flag);
			}
		else if ((*lst_a)->index < piv1)
			{
			stats->opcount = stats->opcount + push_b(lst_a, lst_b, stats->print_flag);
			stats->opcount = stats->opcount + rotate_b(lst_b, stats->print_flag);
			}
		else
			stats->opcount = stats->opcount + rotate_a(lst_a, stats->print_flag);
		count_lsta ++;
	}
}