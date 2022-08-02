/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:16:29 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/02 13:08:21 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	push_a(t_list_ps **lst_a, t_list_ps **lst_b, int print_flag)
{
	t_list_ps	*elem;

	elem = ft_lstnew_ps((*lst_b)->content, (*lst_b)->index);
	elem->next = (*lst_a);
	(*lst_a) = elem;
	(*lst_b) = (*lst_b)->next;
	if (print_flag == 1)
		ft_printf("pa\n");
	return (1);
}

int	push_b(t_list_ps **lst_a, t_list_ps **lst_b, int print_flag)
{
	t_list_ps	*elem;

	elem = ft_lstnew_ps((*lst_a)->content, (*lst_a)->index);
	elem->next = (*lst_b);
	(*lst_b) = elem;
	(*lst_a) = (*lst_a)->next;
	if (print_flag == 1)
		ft_printf("pb\n");
	return (1);
}
