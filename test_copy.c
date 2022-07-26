/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:44:33 by aestraic          #+#    #+#             */
/*   Updated: 2022/06/25 16:17:31 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

//static int statc = 0;

/*
push the first half (lower numbers) of stack a into stack b and pivot them.
*/
void pivotisation_a(t_list_ps **lst_a, t_list_ps **lst_b, int *pivotvalues)
{
	int count_lsta;
	int len_lsta;

	count_lsta = 0;
	len_lsta = list_count(*lst_a);
	while(count_lsta < len_lsta)
	{
		if ((*lst_a)->index < pivotvalues[0])
			{
			push_b(lst_a, lst_b);
			rotate_b(lst_b);
			}
		else if ((*lst_a)->index >= pivotvalues[0] && (*lst_a)->index < pivotvalues[1])
			{
			push_b(lst_a, lst_b);
			}
		else
			rotate_a(lst_a);
		count_lsta ++;
	}
}

/*
push the second half (higher numbers) of stack a into stack b and pivot them.
*/
void pivotisation_b(t_list_ps **lst_a, t_list_ps **lst_b, int *pivotvalues)
{
	int count_lsta;
	int len_lsta;

	count_lsta = 0;
	len_lsta = list_count(*lst_a);
	while(count_lsta < len_lsta)
	{
		if ((*lst_a)->index < pivotvalues[2])
			push_b(lst_a, lst_b);
		else
			rotate_a(lst_a);
		count_lsta ++;
	}
	len_lsta = list_count(*lst_a);
	count_lsta = 0;
	while(count_lsta < len_lsta)
	{
		push_b(lst_a, lst_b);
		count_lsta ++;
	}
}
// void push_sort(t_list_ps **lst_a, t_list_ps **lst_b, int *pivotvalues)
// {
	
// }

void sort(t_list_ps **lst_a, t_list_ps **lst_b)
{
	int check;
	int count_lsta;
	int len_lsta;
	int *pivot_elem;
	int i;

	i = 0;
	pivot_elem = pivotvalues(list_count(*lst_a));
	len_lsta = list_count(*lst_a);
	count_lsta = 0;
	check = 0;
	
	//printIndex(*lst_a);
	pivotisation_a(lst_a, lst_b, pivot_elem);
	pivotisation_b(lst_a, lst_b, pivot_elem);
}

int main(int argc, char **argv)
{
	
	t_list_ps *lst_b;
	t_list_ps *lst_a;
	int i_argc;
	
	i_argc = argc;
	
	lst_a = build_stack_A2(argv);
	lst_a = index_list(lst_a);
//********************************************************************** 
	//test mit double pointern und einfach pointern
	//double pointer verknuepfen lst_a und tmp.
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
	//sort(&lst_a, &lst_b);
	
	//printList(lst_a);
	//printList(lst_b);
//**********************************************************************
	
	int *pivotelements;
	int list_nbr;

	list_nbr = list_count(lst_a);
	//ft_printf("%d", list_nbr);
	pivotelements = pivotvalues(list_nbr);	
	lst_a = index_list(lst_a);
	//printIndex(lst_a);
	lst_b = NULL;
	sort(&lst_a, &lst_b);
	ft_printf("\n%d, %d, %d\n", pivotelements[0], pivotelements[1], pivotelements[2]);
	

	return (0);

//**********************************************************************

}