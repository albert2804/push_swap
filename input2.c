/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:28:20 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/19 15:33:13 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check_for_doubles(t_list_ps *l, t_list_ps *h, t_list_ps *tmp)
{
	while (l && h && h->next)
	{
		l = h->next;
		while (l)
		{
			if (h->content == l->content)
			{
				ft_lstclear_ps(&tmp);
				return (1);
			}
		l = l->next;
		}
	h = h->next;
	}
	return (0);
}
