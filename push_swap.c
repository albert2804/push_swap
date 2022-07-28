/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:44:33 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/28 16:08:18 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

int find_max_index(t_list_ps *lst_b)
{
	int value;

	value = 0;
	while (lst_b)
	{
		if (lst_b->index > value)
			value = lst_b->index;
		lst_b = lst_b->next;
	}
	return (value);
}

/*
counts the indexes in descending order from max_index on, until max_index is found.
i.e. index_max -> index_max - 1 -> index_max - 2, ...
Returns the count of the found elements.
Needed to get the proper malloc size of the array max_values in
function descending_max_values
*/

int count_descending_max_values(t_list_ps *lst_b)
{
	int count;
	int compare_value;

	compare_value = lst_b->index;
	count = 0;
	while (1)
	{
		if (lst_b->index - compare_value == 1)
		{
			compare_value = lst_b->index;
			count++;
		}
		else if (lst_b->index - compare_value > 1)
		{
			count = 0;
			compare_value = lst_b->index;
		}
		if (lst_b->index == find_max_index(lst_b))
			return (count);
		lst_b = lst_b->next;
	}
	return (count);
}

/*
this function is used for building the max_values array.
Kind of sourcing out bc of norminette
*/
int *build_max_values(int *max_values, int compare_value, t_list_ps *lst_b)
{
	int i;

	i = 0;
	while (1)
	{
		if (lst_b->index - compare_value == 1)
		{
			max_values[i] = compare_value;
			compare_value = lst_b->index;
			i++;
		}
		else if (lst_b->index - compare_value > 1)
		{
			compare_value = lst_b->index;
			i = 0;
		}
		if (lst_b->index == find_max_index(lst_b))
		{
			max_values[i] = find_max_index(lst_b);
			return (max_values);
		}
		lst_b = lst_b->next;
	}
}
/*
looks for indexes in descending order from max_index on, until max_index is found.
i.e. index_max -> index_max - 1 -> index_max - 2, ...
Returns the index values of the found elements.
Goal is to push the values into stack A, so Stack B has to be rotated less.
*/
int *descending_max_values(t_list_ps *lst_b)
{
	int count_max_values;
	int compare_value;
	int *max_values;

	count_max_values = count_descending_max_values(lst_b);
	max_values = ft_calloc(count_max_values + 1, sizeof(int));
	if (count_max_values == 0)
	{
		max_values[0] = find_max_index(lst_b);
		return (max_values);
	}
	else
	{
		compare_value = lst_b->index;
		max_values = build_max_values(max_values, compare_value, lst_b);
		return (max_values);
	}
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

/*
checks if lst should be rotated or reverse_rotated.
if 1 that means reverse_rotating
0 means rotating list is better.
*/
int rotate_or_rrotate(t_list_ps *lst_b, int index)
{
	int count;
	int lcount;

	count = 0;
	lcount = list_count(lst_b);
	while(lst_b->index != index)
	{
		lst_b = lst_b->next;
		count ++;
	}
	if (count > lcount/2)
		return (0); 
	else
		return (1);
}

int push_values(t_list_ps **lst_a, t_list_ps **lst_b, int *max_val, int c_val, int print_flag)
{
	int i;
	int op_count;

	op_count = 0;
	i = 0;
	while (i <= c_val)
	{
		if ((*lst_b)->index == max_val[i])
		{
			op_count = op_count + push_a(lst_a, lst_b, print_flag);
			op_count = op_count + rotate_a(lst_a, print_flag);
			i++;
		}
		else if (rotate_or_rrotate(*lst_b, max_val[i]) == 1)
			op_count = op_count + rotate_b(lst_b, print_flag);
		else if (rotate_or_rrotate(*lst_b, max_val[i]) == 0)
			op_count = op_count + rotate_rev_b(lst_b, print_flag);
	}
	if (i > 1)
	{
		while (i > 0)
		{
			op_count = op_count + rotate_rev_a(lst_a, print_flag);
			i--;
		}
	}
	return (op_count);
}

int sortPivotgroup(t_list_ps **lst_a, t_list_ps **lst_b, int print_flag)
{
	int *max_values;
	int op_count;
	int count_max_val;

	op_count = 0;
	while (find_max_index(*lst_b) > 1)
	{
		count_max_val = count_descending_max_values(*lst_b);
		max_values = descending_max_values(*lst_b);
		if (check_for_push(*lst_b) == 0)
		{
			if (rotate_or_rrotate(*lst_b, max_values[0]) == 1)
					op_count = op_count + rotate_b(lst_b, print_flag);
			else if (rotate_or_rrotate(*lst_b, max_values[0]) == 0)
					op_count = op_count + rotate_rev_b(lst_b, print_flag);
		}
		else if (check_for_push(*lst_b) == 1 && count_max_val == 0)
			op_count = op_count + push_a(lst_a, lst_b, print_flag);
		else if (check_for_push(*lst_b) == 1 && count_max_val > 0)
			op_count = op_count + push_values(lst_a, lst_b, max_values, count_max_val, print_flag);
		free(max_values);
	}
	return (op_count);
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
	// single pivot//
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
	sortPivotgroup(lst_a, lst_b, stats->print_flag);
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
		print_status(stats);
		sort(&lst_a, &lst_b, stats);
		free (stats);
	// 	i ++;
	// }
	// ft_printf("\n%d, %d, %d, %d\n", pivotelements[0], pivotelements[1], pivotelements[2], pivotelements[3]);

	return (0);

	//**********************************************************************
}

