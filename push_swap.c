/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:44:33 by aestraic          #+#    #+#             */
/*   Updated: 2022/11/23 18:47:19 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list_ps	*lst_a;
	t_list_ps	*lst_b;
	t_status	*stats;
	int			a;

	lst_a = NULL;
	lst_b = NULL;
	if (argc == 1)
		exit(0);
	else if (double_wrong_or_sorted(argc, argv, NULL, NULL) == 1)
		exit(0);
	a = optimal_pivot_value(argv, argc, 0);
	lst_a = read_in(lst_a, argc, argv);
	lst_a = index_list(lst_a);
	stats = init_struct(lst_a);
	stats->piv_c = a;
	stats->p_f = 1;
	sort(&lst_a, &lst_b, stats, 1);
	free (stats);
	ft_lstclear_ps(&lst_a);
	ft_lstclear_ps(&lst_b);
	return (0);
}
