/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_optimisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 09:29:02 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/09 15:28:59 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//Finds the optimal pivotcount which has 
//the minimum amount of operations
int	find_min_int(int *int_list, int max_c, int min_c)
{
	int	i;
	int	pos;
	int	min_val;

	i = 0;
	min_val = 10000000;
	while (i < (max_c - min_c))
	{
		if (int_list[i] < min_val)
		{	
			pos = i;
			min_val = int_list[i];
		}
		i ++;
	}
	free(int_list);
	return (pos + min_c);
}

//Function to save all operation_counts in a integer array
//Afterwards function find_min_int finds the minimum value and returns the
//corresponding pivotvalue.
int	optimal_pivot_value(char **argv, int argc, int i)
{
	int			*op_counts;
	int			opt_op_count;
	t_list_ps	*lst_a;
	t_list_ps	*lst_b;
	t_status	*stats;

	opt_op_count = 0;
	op_counts = malloc(sizeof(int) * (30 - 5 + 1));
	while (i <= (30 - 5))
	{
		lst_a = NULL;
		lst_b = NULL;
		lst_a = read_in(lst_a, argc, argv);
		lst_a = index_list(lst_a);
		stats = init_struct(lst_a);
		stats->piv_c = 5 + i;
		sort(&lst_a, &lst_b, stats);
		op_counts[i++] = stats->op_c;
		free (stats);
		ft_lstclear_ps(&lst_a);
		ft_lstclear_ps(&lst_b);
	}
	opt_op_count = find_min_int(op_counts, 30, 5);
	return (opt_op_count);
}
