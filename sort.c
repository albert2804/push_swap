/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:36:40 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/18 17:19:49 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

/*
single pivotisation
*/
void	pivotisation(t_list_ps **lst_a, t_list_ps **lst_b, t_status *stats)
{
	int	count_lsta;
	int	len_lsta;

	count_lsta = 0;
	len_lsta = list_count(*lst_a);
	while (pivgroup_pushed(lst_a, stats->piv2) == 0 && count_lsta++ < len_lsta)
	{
		if ((*lst_a)->index >= stats->piv1 && (*lst_a)->index <= stats->piv2)
			stats->op_c = stats->op_c + push_b(lst_a, lst_b, stats->p_f);
		else if ((*lst_a)->index < stats->piv1 && \
		(*lst_a)->next->index > stats->piv2)
			stats->op_c = stats->op_c + pb_rr(lst_a, lst_b, stats->p_f);
		else if ((*lst_a)->index < stats->piv1)
			stats->op_c = stats->op_c + pb_rb(lst_a, lst_b, stats->p_f);
		else
			stats->op_c = stats->op_c + rotate_a(lst_a, stats->p_f);
	}
}

void	sortpivgroup(t_list_ps **lst_a, t_list_ps **lst_b, t_status *stats)
{
	int	*max_values;

	// while ((*lst_b)->next)
	while ((*lst_b))
	{
		stats->count_max_val = count_descending_max_values(*lst_b);
		max_values = descending_max_values(*lst_b);
		if (check_for_push(*lst_b) == 0)
		{
			if (rotate_or_rrotate(*lst_b, max_values[0]) == 1)
				stats->op_c = stats->op_c + rotate_b(lst_b, stats->p_f);
			else if (rotate_or_rrotate(*lst_b, max_values[0]) == 0)
				stats->op_c = stats->op_c + rotate_rev_b(lst_b, stats->p_f);
		}
		else if (check_for_push(*lst_b) == 1 && stats->count_max_val == 0)
			stats->op_c = stats->op_c + push_a(lst_a, lst_b, stats->p_f);
		else if (check_for_push(*lst_b) == 1 && stats->count_max_val > 0)
			p_val(lst_a, lst_b, max_values, stats);
		free(max_values);
	}
	if ((*lst_b))
	{
	 	stats->op_c = stats->op_c + push_a(lst_a, lst_b, stats->p_f);
		ft_lstclear_ps(lst_b);
	}
}

void	sort_small_stack(t_list_ps **lst_a, t_status *stats)
{
	if (stats->lsta_c > 2)
		sort_3digit_stack(lst_a, stats);
	else if ((*lst_a)->index > (*lst_a)->next->index)
		swap_a(lst_a, stats->p_f);
}

/*
	i = i + 2; // use this to pivot the stack mirrored
	i++; // use this to pivot the stack descending
*/
void	sort(t_list_ps **lst_a, t_list_ps **lst_b, t_status *stats, int i)
{
	int	*pivot_array;

	pivot_array = pivotvalues(stats);
	if (stats->lsta_c >= 32)
	{
		while (i < stats->piv_c)
		{
			stats->piv1 = pivot_array[i];
			stats->piv2 = pivot_array[i + 1];
			pivotisation(lst_a, lst_b, stats);
			i = i + 2;
		}
	}
	stats->piv1 = pivot_array[i + 1];
	stats->piv2 = stats->lsta_c - 3;
	if (stats->lsta_c > 3)
		pivotisation(lst_a, lst_b, stats);
	if (stats->lsta_c > 1)
		sort_small_stack(lst_a, stats);
	else
		return (free(pivot_array));
	if (stats->lsta_c > 3)
		sortpivgroup(lst_a, lst_b, stats);
	free(pivot_array);
}
