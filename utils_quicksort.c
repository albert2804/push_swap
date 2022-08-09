/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:30:47 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/09 15:58:09 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
find varible pivot elements from unsorted stack a
goal is to divide the list in different areas
*/
int	*pivotvalues(t_status *stats)
{
	int	*pivot_values;
	int	i;

	i = 1;
	pivot_values = ft_calloc(sizeof(int *), stats->piv_c);
	pivot_values[0] = stats->lsta_c / (stats->piv_c + 1);
	while (i < stats->piv_c)
	{
		// ft_printf("p_val1");
		pivot_values[i] = stats->lsta_c / (stats->piv_c + 1) * (i + 1);
		i++;
	}
	return (pivot_values);
}

/*
checks if the current index and descending values fromt that index
in Stack B are pushable. If Yes the function returns 1.
Else Stack B has to be rotated, until check for push returns 1.
*/
int	check_for_push(t_list_ps *lst_b)
{
	int	max_index;
	int	flag;

	max_index = find_max_index(lst_b);
	flag = count_descending_max_values(lst_b);
	if (flag != 0 || lst_b->index == max_index)
		return (1);
	return (0);
}

/*
pushes values depending on check_flag
*/
void	p_val(t_list_ps **l_a, t_list_ps **l_b, int *mx_val, t_status *sts)
{
	int	i;

	i = 0;
	while (i <= sts->count_max_val)
	{
		// ft_printf("p_val1");
		if ((*l_b)->index == mx_val[i] && i != sts->count_max_val)
		{
			sts->op_c = sts->op_c + push_a(l_a, l_b, sts->p_f);
			sts->op_c = sts->op_c + rotate_a(l_a, sts->p_f);
			i++;
		}
		else if ((*l_b)->index == mx_val[i] && i == sts->count_max_val)
		{
			sts->op_c = sts->op_c + push_a(l_a, l_b, sts->p_f);
			i++;
		}
		else if (rotate_or_rrotate(*l_b, mx_val[i]) == 1)
			sts->op_c = sts->op_c + rotate_b(l_b, sts->p_f);
		else if (rotate_or_rrotate(*l_b, mx_val[i]) == 0)
			sts->op_c = sts->op_c + rotate_rev_b(l_b, sts->p_f);
	}
	while (--i > 0)
	{
		sts->op_c = sts->op_c + rotate_rev_a(l_a, sts->p_f);
	// ft_printf("p_val2");
	}
}
