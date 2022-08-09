/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:30:47 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/09 09:35:58 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	printlist(t_list_ps *lst)
{
	t_list_ps	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		ft_printf("%d->", tmp->content);
		tmp = tmp->next;
	}
	//free (tmp);
	ft_printf("NULLL\n");
}

void	printindex(t_list_ps *lst)
{
	t_list_ps	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		ft_printf("%d->", tmp->index);
		tmp = tmp->next;
	}
	//free (tmp);
	ft_printf("NULL\n");
}

int	list_count(t_list_ps *lst)
{
	t_list_ps	*temp;
	int			i;

	i = 1;
	temp = lst;
	while (temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}	
	return (i);
}

void	print_status(t_status *stats)
{
	ft_printf("List A Count: %d\n", stats->lsta_c);
	ft_printf("Pivot Count: %d\n", stats->piv_c);
	ft_printf("Operations Count: %d\n", stats->op_c);
	ft_printf("PrintFlag: %d\n", stats->p_f);
}

/*
checks if lst should be rotated or reverse_rotated.
if 1 that means reverse_rotating
0 means rotating list is better.
*/
int	rotate_or_rrotate(t_list_ps *lst_b, int index)
{
	int	count;
	int	lcount;

	count = 0;
	lcount = list_count(lst_b);
	while (lst_b->index != index)
	{
		lst_b = lst_b->next;
		count ++;
	}
	if (count > lcount / 2)
		return (0);
	else
		return (1);
}
