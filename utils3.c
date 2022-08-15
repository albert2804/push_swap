/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:05:28 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/15 16:33:48 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_lstclear_ps(t_list_ps **lst)
{
	t_list_ps	*lst_tmp;

	if (!lst)
		return ;
	while ((*lst))
	{
		lst_tmp = (*lst)->next;
		ft_lstdelone_ps(*lst);
		*lst = lst_tmp;
	}
}

void	ft_lstdelone_ps(t_list_ps *lst)
{
	if (!lst)
		return ;
	free (lst);
}

int	pivgroup_pushed(t_list_ps **lst, int piv_2)
{
	t_list_ps	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->index <= piv_2)
			return (0);
		tmp = tmp->next;
	}
	if (list_count(*lst) == 1)
		return (0);
	return (1);
}

void	sort_3digit_stack(t_list_ps **lst_a, t_status *stats)
{
	if ((*lst_a)->index == stats->lsta_c - 1 && \
	(*lst_a)->next->index == stats->lsta_c - 2)
		stats->op_c = stats->op_c + swap_a(lst_a, stats->p_f);
	else if ((*lst_a)->index == stats->lsta_c - 2 && \
	(*lst_a)->next->index == stats->lsta_c)
	{
		stats->op_c = stats->op_c + rotate_rev_a(lst_a, stats->p_f);
		stats->op_c = stats->op_c + swap_a(lst_a, stats->p_f);
	}
	else if ((*lst_a)->index == stats->lsta_c - 1 && \
	(*lst_a)->next->index == stats->lsta_c)
		stats->op_c = stats->op_c + rotate_rev_a(lst_a, stats->p_f);
	else if ((*lst_a)->index == stats->lsta_c && \
	(*lst_a)->next->index == stats->lsta_c - 1)
	{
		stats->op_c = stats->op_c + rotate_a(lst_a, stats->p_f);
		stats->op_c = stats->op_c + swap_a(lst_a, stats->p_f);
	}
	else if ((*lst_a)->index == stats->lsta_c && \
	(*lst_a)->next->index == stats->lsta_c - 2)
		stats->op_c = stats->op_c + rotate_a(lst_a, stats->p_f);
}
