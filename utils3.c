/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:05:28 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/09 15:22:58 by aestraic         ###   ########.fr       */
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