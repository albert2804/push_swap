/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:44:33 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/02 14:34:52 by aestraic         ###   ########.fr       */
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
		{	
			stats->opcount = stats->opcount + push_b(lst_a, lst_b, stats->print_flag);
		}
		else if ((*lst_a)->index < stats->piv1)
		{
			stats->opcount = stats->opcount + push_b(lst_a, lst_b, stats->print_flag);
			//stats->opcount = stats->opcount + rrab(lst_a, lst_b, stats->print_flag);
			stats->opcount = stats->opcount + rotate_b(lst_b, stats->print_flag);
			// stats->opcount = stats->opcount + rotate_a(lst_a, stats->print_flag);
		}
		else
			stats->opcount = stats->opcount + rotate_a(lst_a, stats->print_flag);
		count_lsta ++;
	}
}

void	sortPivotgroup(t_list_ps **lst_a, t_list_ps **lst_b, t_status *stats)
{
	int	*max_values;

	while (find_max_index(*lst_b) > 1)
	{
		stats->count_max_val = count_descending_max_values(*lst_b);
		max_values = descending_max_values(*lst_b);
		if (check_for_push(*lst_b) == 0)
		{
			if (rotate_or_rrotate(*lst_b, max_values[0]) == 1)
				stats->opcount = stats->opcount + rotate_b(lst_b, stats->print_flag);
			else if (rotate_or_rrotate(*lst_b, max_values[0]) == 0)
				stats->opcount = stats->opcount + rotate_rev_b(lst_b, stats->print_flag);
		}
		else if (check_for_push(*lst_b) == 1 && stats->count_max_val == 0)
			stats->opcount = stats->opcount + push_a(lst_a, lst_b, stats->print_flag);
		else if (check_for_push(*lst_b) == 1 && stats->count_max_val > 0)
			push_values(lst_a, lst_b, max_values, stats);
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
	while (i < stats->pivot_count)
	{
		stats->piv1 = pivot_array[i];
		stats->piv2 = pivot_array[i + 1];
		pivotisation(lst_a, lst_b, stats);
		i = i + 2; // use this to pivot the stack mirrored
		//i++; // use this to pivot the stack descending
	}
	stats->piv1 = pivot_array[i + 1];
	stats->piv2 = index_lsta;
	pivotisation(lst_a, lst_b, stats);
	//sortPivotgroup(lst_a, lst_b, stats);
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
		lst_a = build_stack_A2(argv);
		lst_a = index_list(lst_a);
		lst_b = NULL;
		stats = init_struct(lst_a);
		stats->pivot_count = min_c + i;
		sort(&lst_a, &lst_b, stats);
		op_counts[i] = stats->opcount;
		free (stats);
		i ++;
	}
	optimal_op_count = find_min_int(op_counts, max_c, min_c);
	return (optimal_op_count);
}

int	main(int argc, char **argv)
{
	t_list_ps *lst_b;
	t_list_ps *lst_a;
	int i_argc;
	int max_pivot_count;
	int list_nbr;
	int i;
	t_status *stats;
	int a;
	
	i_argc = argc;
	max_pivot_count = 30;
	i = 5;
	a = optimal_pivot_value(argv, max_pivot_count, i, 0);
	ft_printf("op_c:%d\n",a);
	
	// lst_a = build_stack_A1(argv[1]);
	lst_a = build_stack_A2(argv);
	lst_a = index_list(lst_a);
	list_nbr = list_count(lst_a);

	lst_a = index_list(lst_a);
	lst_b = NULL;
	stats = init_struct(lst_a);
	stats->pivot_count = a;
	stats->print_flag = 1;
	sort(&lst_a, &lst_b, stats);
	ft_printf("%d", stats->opcount);
	free (stats);
	return (0);

	//**********************************************************************
}

