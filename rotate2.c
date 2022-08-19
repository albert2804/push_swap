/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:23:35 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/19 15:25:36 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	rrrab(t_list_ps **lsta, t_list_ps **lstb, int print_flag)
{
	rotate_rev_a(lsta, 0);
	rotate_rev_b(lstb, 0);
	if (print_flag == 1)
		ft_printf("rrr\n");
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
