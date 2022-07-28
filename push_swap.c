/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:44:33 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/28 18:48:27 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

/*
single pivotisation
*/
void pivotisation(t_list_ps **lst_a, t_list_ps **lst_b, t_status *stats)
{
	int count_lsta;
	int len_lsta;

	count_lsta = 0;
	len_lsta = list_count(*lst_a);
	while(count_lsta < len_lsta)
	{
		if ((*lst_a)->index >= stats->piv1 && (*lst_a)->index <= stats->piv2)
			{
			stats->opcount = stats->opcount + push_b(lst_a, lst_b, stats->print_flag);
			if ((*lst_b)->next && (*lst_b)->next->index - (*lst_b)->index == -1)
				stats->opcount = stats->opcount + swap_b(lst_b, stats->print_flag);
			}
		else if ((*lst_a)->index < stats->piv1)
			{
			stats->opcount = stats->opcount + push_b(lst_a, lst_b, stats->print_flag);
			stats->opcount = stats->opcount + rotate_b(lst_b, stats->print_flag);
			}
		else
			stats->opcount = stats->opcount + rotate_a(lst_a, stats->print_flag);
		count_lsta ++;
	}
}

void sortPivotgroup(t_list_ps **lst_a, t_list_ps **lst_b, t_status *stats)
{
	int *max_values;
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

void sort(t_list_ps **lst_a, t_list_ps **lst_b, t_status *stats)
{
	int check;
	int index_lsta;
	int *pivot_array;
	int i;

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
	sortPivotgroup(lst_a, lst_b, stats);
}

int main(int argc, char **argv)
{
	t_list_ps *lst_b;
	t_list_ps *lst_a;
	int i_argc;
	int max_pivot_count;
	int list_nbr;
	int i;
	t_status *stats;
	
	i_argc = argc;
	max_pivot_count = 30;
	i = 29;
	// lst_a = build_stack_A1(argv[1]);


	//**********************************************************************
	// test mit double pointern und einfach pointern
	// double pointer verknuepfen lst_a und tmp.
	/*
	t_list_ps **tmp;
	tmp = &lst_a;
	printList(*tmp);
	(*tmp) = (*tmp)->next;

	ft_printf("\nlst_a:");
	printList(lst_a);
	ft_printf("\ntmp:");
	printList(*tmp);
	*/
	// sort(&lst_a, &lst_b);

	// printList(lst_a);
	// printList(lst_b);
	//**********************************************************************

	// int *pivotelements;

	// while (i < max_pivot_count)
	// {
		lst_a = build_stack_A2(argv);
		lst_a = index_list(lst_a);
		list_nbr = list_count(lst_a);

		// pivotelements = pivotvalues(list_nbr);
		lst_a = index_list(lst_a);
		lst_b = NULL;
		// stats = init_struct(lst_a);
		stats = init_struct(lst_a);
		stats->pivot_count = i;
		stats->print_flag = 1;
		sort(&lst_a, &lst_b, stats);
		
		print_status(stats);
		free (stats);
	// 	i ++;
	// }

	return (0);

	//**********************************************************************
}

