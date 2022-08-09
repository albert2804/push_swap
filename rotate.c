/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:16:23 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/09 16:10:15 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	rotate_a(t_list_ps **lst, int print_flag)
{
	t_list_ps	*first;
	t_list_ps	*tmp;

	if ((*lst)->next)
	{
		tmp = *lst;
		first = ft_lstnew_ps((*lst)->content, (*lst)->index);
		ft_lstadd_back_ps(lst, first);
		(*lst) = (*lst)->next;
		free(tmp);
		if (print_flag == 1)
			ft_printf("ra\n");
	}
	return (1);
}

int	rotate_b(t_list_ps **lst, int print_flag)
{
	t_list_ps	*first;
	t_list_ps	*tmp;

	if ((*lst)->next)
	{
		tmp = *lst;
		first = ft_lstnew_ps((*lst)->content, (*lst)->index);
		ft_lstadd_back_ps(lst, first);
		(*lst) = (*lst)->next;
		free(tmp);
		if (print_flag == 1)
			ft_printf("rb\n");
	}
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
		// ft_printf("revb");
		temp = temp->next;
	}	
	temp->next = NULL;
	if (print_flag == 1)
		ft_printf("rrb\n");
	return (1);
}

int	rrab(t_list_ps **lsta, t_list_ps **lstb, int print_flag)
{
	rotate_a(lsta, 0);
	rotate_b(lstb, 0);
	if (print_flag == 1)
		ft_printf("rr\n");
	return (1);
}
