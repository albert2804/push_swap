/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:44:33 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/03 11:04:27 by aestraic         ###   ########.fr       */
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

void	sort(t_list_ps **lst_a, t_list_ps **lst_b, t_status *stats)
{
	int	check;
	int	index_lsta;
	int	*pivot_array;
	int	i;

	i = 0;
	pivot_array = pivotvalues(stats);
	check = 0;
	index_lsta = list_count(*lst_a);
	while (i < stats->piv_c)
	{
		stats->piv1 = pivot_array[i];
		stats->piv2 = pivot_array[i + 1];
		pivotisation(lst_a, lst_b, stats);
		i = i + 2; // use this to pivot the stack mirrored
		// i++; // use this to pivot the stack descending
	}
	stats->piv1 = pivot_array[i + 1];
	stats->piv2 = index_lsta;
	pivotisation(lst_a, lst_b, stats);
	sortpivgroup(lst_a, lst_b, stats);
}

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
int	optimal_pivot_value(char **argv, int max_c, int min_c, int i)
{
	int			*op_counts;
	int			optimal_op_count;
	t_list_ps	*lst_a;
	t_list_ps	*lst_b;
	t_status	*stats;

	optimal_op_count = 0;
	op_counts = malloc(sizeof(int) * (max_c - min_c + 1));
	while (i <= (max_c - min_c))
	{
		lst_a = build_stack_a2(argv);
		lst_a = index_list(lst_a);
		lst_b = NULL;
		stats = init_struct(lst_a);
		stats->piv_c = min_c + i;
		sort(&lst_a, &lst_b, stats);
		op_counts[i] = stats->op_c;
		free (stats);
		i ++;
	}
	optimal_op_count = find_min_int(op_counts, max_c, min_c);
	return (optimal_op_count);
}

int	main(int argc, char **argv)
{
	t_list_ps	*lst_b;
	t_list_ps	*lst_a;
	t_status	*stats;
	int			a;

	if (argc > 3)
		lst_a = build_stack_a2(argv);
	ft_printf("argc: %d\n", argc);

	a = optimal_pivot_value(argv, 30, 1, 0);
	ft_printf("op_c:%d\n",a);
	// char **readin;
	// readin = read_input(*(argv + 1));
	// ft_printf("STRING:%s\n", readin[0]);
	// lst_a = read_in(argc, argv);
	// lst_a = build_stack_a1(*argv);
	lst_a = build_stack_a2(argv);
	lst_a = index_list(lst_a);

	lst_b = NULL;
	stats = init_struct(lst_a);
	stats->piv_c = a;
	stats->p_f = 1;
	sort(&lst_a, &lst_b, stats);
	ft_printf("%d", stats->op_c);
	free (stats);
	return (0);

	//**********************************************************************
}
