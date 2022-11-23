/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:16:29 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/23 14:37:40 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	push_a(t_list_ps **lst_a, t_list_ps **lst_b, int print_flag)
{
	t_list_ps	*elem;
	t_list_ps	*tmp;

	tmp = *lst_b;
	if ((*lst_b))
	{
		elem = ft_lstnew_ps((*lst_b)->content, (*lst_b)->index);
		ft_lstadd_front_ps(lst_a, elem);
		tmp = (*lst_b)->next;
		free(*lst_b);
		*lst_b = tmp;
	}
	if (print_flag == 1)
		ft_printf("pa\n");
	return (1);
}

int	push_b(t_list_ps **lst_a, t_list_ps **lst_b, int print_flag)
{
	t_list_ps	*elem;
	t_list_ps	*tmp;

	if ((*lst_a))
	{
		elem = ft_lstnew_ps((*lst_a)->content, (*lst_a)->index);
		ft_lstadd_front_ps(lst_b, elem);
		tmp = (*lst_a)->next;
		free(*lst_a);
		*lst_a = tmp;
	}
	if (print_flag == 1)
		ft_printf("pb\n");
	return (1);
}

int	pa_rr(t_list_ps **lst_a, t_list_ps **lst_b, int print_flag)
{
	push_a(lst_a, lst_b, print_flag);
	rrab(lst_a, lst_b, print_flag);
	return (2);
}

int	pb_rr(t_list_ps **lst_a, t_list_ps **lst_b, int print_flag)
{
	push_b(lst_a, lst_b, print_flag);
	rrab(lst_a, lst_b, print_flag);
	return (2);
}

int	pb_rb(t_list_ps **lst_a, t_list_ps **lst_b, int print_flag)
{
	push_b(lst_a, lst_b, print_flag);
	rotate_b(lst_b, print_flag);
	return (2);
}
