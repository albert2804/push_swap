/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:44:33 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/09 11:43:19 by aestraic         ###   ########.fr       */
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
	while (count_lsta < len_lsta)
	{
		if ((*lst_a)->index >= stats->piv1 && (*lst_a)->index <= stats->piv2)
			stats->op_c = stats->op_c + push_b(lst_a, lst_b, stats->p_f);
		else if ((*lst_a)->index < stats->piv1)
		{
			stats->op_c = stats->op_c + push_b(lst_a, lst_b, stats->p_f);
			stats->op_c = stats->op_c + rotate_b(lst_b, stats->p_f);
		}
		else if ((*lst_a)->index > len_lsta - 3)
			stats->op_c = stats->op_c + rotate_a(lst_a, stats->p_f);
		else
			stats->op_c = stats->op_c + rotate_a(lst_a, stats->p_f);
		count_lsta ++;
	}
}

void	sortpivgroup(t_list_ps **lst_a, t_list_ps **lst_b, t_status *stats)
{
	int	*max_values;

	while (find_max_index(*lst_b) > 1)
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
}

/*
	i = i + 2; // use this to pivot the stack mirrored
	i++; // use this to pivot the stack descending
*/
void	sort(t_list_ps **lst_a, t_list_ps **lst_b, t_status *stats)
{
	int	index_lsta;
	int	*pivot_array;
	int	i;

	i = 0;
	pivot_array = pivotvalues(stats);
	index_lsta = list_count(*lst_a);
	while (i < stats->piv_c)
	{
		stats->piv1 = pivot_array[i];
		stats->piv2 = pivot_array[i + 1];
		pivotisation(lst_a, lst_b, stats);
		i = i + 2;
	}
	stats->piv1 = pivot_array[i + 1];
	stats->piv2 = index_lsta;
	pivotisation(lst_a, lst_b, stats);
	sortpivgroup(lst_a, lst_b, stats);
}

int	main(int argc, char **argv)
{
	t_list_ps	*lst_a;
	t_list_ps	*lst_b;
	t_status	*stats;
	int			a;

	// a = optimal_pivot_value(argv, argc, 0);
	a = 3;
	lst_a = NULL;
	lst_b = NULL;
	lst_a = read_in(lst_a, argc, argv);
	lst_a = index_list(lst_a);
	stats = init_struct(lst_a);
	stats->piv_c = a;
	stats->p_f = 0;
	sort(&lst_a, &lst_b, stats);
	ft_printf("%d", stats->op_c); //delete this line for eval
	free (stats);
	system("leaks push_swap");
	return (0);
}
