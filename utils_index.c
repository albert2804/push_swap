/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:54:47 by aestraic          #+#    #+#             */
/*   Updated: 2022/06/27 13:41:36 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <limits.h>

/*
threshold is value to cut out every number which was already indexed
the threshold is the biggest number in the stack
*/
int threshold_for_index_func(t_list_ps *lst)
{
	long threshold;
	t_list_ps *tmp;

	tmp = lst;
	threshold = INT_MAX;	//do threshold variable. it is the biggest number + 1.
	threshold++; 			//do an Error Message if nbr is bigger than SIZE_MAX.	
								
	while((tmp) != NULL)
	{
		if((tmp)->content <= threshold && (tmp->index) == 0)
			threshold = (tmp)->content;
		(tmp) = (tmp)->next;
	}
	return(threshold);
}

/*
index every element one at a time in the list, depending on the threshold
*/
t_list_ps *index_elem(t_list_ps *lst, int threshold, int indx)
{
	t_list_ps *tmp;
	
	tmp = lst;
	while((tmp) != NULL)
	{
		if (tmp->content == threshold)
			{
				tmp->index = indx;
				return(lst);
			}
		tmp = tmp->next;
	}
	return(lst);
}

/*
build an indexed list, first the smallest number will be indexed,
afterwards the index get bigger (indx++). Because of the threshold,
already indexed numers are not considered.
*/
t_list_ps *index_list(t_list_ps *lst)
{
	int threshold;
	int indx;
	t_list_ps *tmp;
	int count;
	
	indx = 1;
	count = list_count(lst);
	tmp = lst;
	while(indx <= count + 1)
	{
		threshold = threshold_for_index_func(lst);
		tmp = index_elem(lst, threshold, indx);
		indx++;		
	}
	return (lst);
}

/*
this function shall find the 2 elemets in which the "inserted element" index fits
*/
int *find_edge_elements(t_list_ps *lst_a, int inserted_elem)
{
	t_list_ps *temp;
	int *pos;

	pos = malloc(sizeof(int) * 2);
	pos[0] = 0;
	pos[1] = 0;
	temp = lst_a;
	//ft_printf("Inserted: %d\n", inserted_elem);
	while (temp->next != NULL)
	{
		// ft_printf("%d\n", temp->index);
		// ft_printf("%d\n", temp->next->index);
		// ft_printf("************\n");
		if (inserted_elem > temp->index && inserted_elem < temp->next->index)
		{
			pos[0] = temp->index;
			pos[1] = temp->next->index;
			return(pos);
		}
		temp = temp->next;
	}
	return (pos);
}