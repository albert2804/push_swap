/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:30:47 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/04 15:23:35 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
find varible pivot elements from unsorted stack a
goal is to divide the list in different areas
*/
int *pivotvalues(int list_count, int pivot_count)
{
	int *pivot_values;
	int i;

	i = 1;
	pivot_values = malloc(sizeof(int) * pivot_count);
	pivot_values[0] = list_count/(pivot_count + 1);
	while (i < pivot_count)
	{
		pivot_values[i] = list_count/(pivot_count + 1) * (i + 1);
		i++;
	}
	return(pivot_values);
}

/*
single pivotisation
*/
int pivotisation(t_list_ps **lst_a, t_list_ps **lst_b, int piv1, int piv2, int print_flag)
{
	int count_lsta;
	int len_lsta;
	int op_count;

	op_count = 0;
	count_lsta = 0;
	len_lsta = list_count(*lst_a);
	while(count_lsta < len_lsta)
	{
		if ((*lst_a)->index >= piv1 && (*lst_a)->index <= piv2)
			{
			op_count = op_count + push_b(lst_a, lst_b, print_flag);
			if ((*lst_b)->next && (*lst_b)->next->index - (*lst_b)->index == -1)
				op_count = op_count + swap_b(lst_b, print_flag);
			}
		else if ((*lst_a)->index < piv1)
			{
			op_count = op_count + push_b(lst_a, lst_b, print_flag);
			op_count = op_count + rotate_b(lst_b, print_flag);
			}
		else
			op_count = op_count + rotate_a(lst_a, print_flag);
		count_lsta ++;
	}
	return(op_count);
}