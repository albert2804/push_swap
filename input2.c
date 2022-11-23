/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:28:20 by aestraic          #+#    #+#             */
/*   Updated: 2022/11/23 18:44:54 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check_for_doubles(t_list_ps *l, t_list_ps *h)
{
	while (l && h && h->next)
	{
		l = h->next;
		while (l)
		{
			if (h->content == l->content)
				return (1);
			l = l->next;
		}
		l = h->next;
		h = h->next;
	}
	return (0);
}
