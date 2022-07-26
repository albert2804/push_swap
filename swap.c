/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:16:32 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/04 15:28:46 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <push_swap.h>

void swap_nodes(t_list_ps *node1, t_list_ps *node2)
{
	t_list_ps *temp;
	
	temp = node1->next;  
	node1->next = node2->next;   
	node2->next = temp;   
}

int swap_a(t_list_ps **lst, int print_flag)
{
	t_list_ps *node1;
	t_list_ps *node2;

	node1 = (*lst);
	node2 = (*lst)->next;
	swap_nodes(node1, node2);
	(*lst) = node2;
	(*lst)->next = node1;
	if (print_flag == 1)	
		ft_printf("sa\n");
	return (1);
}

int swap_b(t_list_ps **lst, int print_flag)
{
	t_list_ps *node1;
	t_list_ps *node2;

	node1 = (*lst);
	node2 = (*lst)->next;
	swap_nodes(node1, node2);
	(*lst) = node2;
	(*lst)->next = node1;
	if (print_flag == 1)		
		ft_printf("sb\n");
	return (1);
}