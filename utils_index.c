/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:54:47 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/02 17:10:28 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <limits.h>

/*
threshold is value to cut out every number which was already indexed
the threshold is the biggest number in the stack

init threshold variable woth INT_MAX it is the biggest number + 1.
do an Error Message if nbr is bigger than SIZE_MAX.
*/
int	threshold_for_index_func(t_list_ps *lst)
{
	long		threshold;
	t_list_ps	*tmp;

	tmp = lst;
	threshold = INT_MAX;
	threshold ++;
	while ((tmp) != NULL)
	{
		if ((tmp)->content <= threshold && (tmp->index) == 0)
			threshold = (tmp)->content;
		(tmp) = (tmp)->next;
	}
	return (threshold);
}

/*
index every element one at a time in the list, depending on the threshold
*/
t_list_ps	*index_elem(t_list_ps *lst, int threshold, int indx)
{
	t_list_ps	*tmp;

	tmp = lst;
	while ((tmp) != NULL)
	{
		if (tmp->content == threshold)
		{
			tmp->index = indx;
			return (lst);
		}
		tmp = tmp->next;
	}
	return (lst);
}

/*
build an indexed list, first the smallest number will be indexed,
afterwards the index get bigger (indx++). Because of the threshold,
already indexed numers are not considered.
*/
t_list_ps	*index_list(t_list_ps *lst)
{
	int			threshold;
	int			indx;
	t_list_ps	*tmp;
	int			count;

	indx = 1;
	count = list_count(lst);
	tmp = lst;
	while (indx <= count + 1)
	{
		threshold = threshold_for_index_func(lst);
		tmp = index_elem(lst, threshold, indx);
		indx++;
	}
	return (lst);
}

int	find_max_index(t_list_ps *lst_b)
{
	int	value;

	value = 0;
	while (lst_b)
	{
		if (lst_b->index > value)
			value = lst_b->index;
		lst_b = lst_b->next;
	}
	return (value);
}
