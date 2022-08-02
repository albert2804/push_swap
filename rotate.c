/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:16:23 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/02 14:06:23 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	rotate_a(t_list_ps **lst, int print_flag)
{
	t_list_ps	*first;
	int			i;
	int			j;

	j = 1;
	i = list_count(*lst);
	first = ft_lstnew_ps((*lst)->content, (*lst)->index);
	(*lst) = (*lst)->next;
	ft_lstadd_back_ps(lst, first);
	if (print_flag == 1)
		ft_printf("ra\n");
	return (1);
}

int	rotate_b(t_list_ps **lst, int print_flag)
{
	t_list_ps	*first;
	int			i;
	int			j;

	j = 1;
	i = list_count(*lst);
	first = ft_lstnew_ps((*lst)->content, (*lst)->index);
	(*lst) = (*lst)->next;
	ft_lstadd_back_ps(lst, first);
	if (print_flag == 1)
		ft_printf("rb\n");
	return (1);
}

int	rotate_rev_a(t_list_ps **lst, int print_flag)
{
	t_list_ps	*last;
	t_list_ps	*temp;

	last = ft_lstlast_ps(*lst);
	temp = *lst;
	ft_lstadd_front_ps(lst, last);
	while (temp->next != last)
	{
		temp = temp->next;
	}	
	temp->next = NULL;
	if (print_flag == 1)
		ft_printf("rra\n");
	return (1);
}

int	rotate_rev_b(t_list_ps **lst, int print_flag)
{
	t_list_ps	*last;
	t_list_ps	*temp;

	last = ft_lstlast_ps(*lst);
	temp = *lst;
	ft_lstadd_front_ps(lst, last);
	while (temp->next != last)
	{
		temp = temp->next;
	}	
	temp->next = NULL;
	if (print_flag == 1)
		ft_printf("rrb\n");
	return (1);
}

int rrab(t_list_ps **lsta, t_list_ps **lstb, int print_flag)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	i = rotate_a(lsta, 0);
	j = rotate_b(lstb, 0);
	if (print_flag == 1)
		ft_printf("rr\n");
	return (1);
}
