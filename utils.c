/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:30:47 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/28 14:58:33 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <push_swap.h>

void printList(t_list_ps *lst)
{
    t_list_ps *tmp;
	
	tmp = lst;
    while(tmp != NULL)
    {
        ft_printf("%d->", tmp->content);
        tmp = tmp->next;
    }
    ft_printf("NULL\n");
}

void printIndex(t_list_ps *lst)
{
    t_list_ps *tmp;
	
	tmp = lst;
    while(tmp != NULL)
    {
        ft_printf("%d->", tmp->index);
        tmp = tmp->next;
    }
    ft_printf("NULL\n");
}

int list_count(t_list_ps *lst)
{
	
	t_list_ps *temp;
	int i;
	
	i = 1;
	temp = lst;
	while (temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}	
	return (i);
}

/*
checks if lst_a is sorted
*/
int sort_check(t_list_ps *lst_a)
{
	t_list_ps *temp;
	
	temp = lst_a;
	while(temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void print_status(t_status *stats)
{
	ft_printf("List A Count: %d\n", stats->lista_count);
	ft_printf("Pivot Count: %d\n", stats->pivot_count);
	ft_printf("Operations Count: %d\n", stats->opcount);
	ft_printf("PrintFlag: %d\n", stats->print_flag);
}

// t_status init_struct(t_list_ps *lst_a)
// {
// 	t_status stats;

// 	stats.lista_count = list_count(lst_a);
// 	stats.pivot_count = 15;
// 	stats.opcount = 0;
// 	stats.print_flag = 0;
// 	return (stats);
// }

t_status *init_struct(t_list_ps *lst_a)
{
	t_status *stats;
	
	stats = malloc(sizeof(t_status));
	stats->lista_count = list_count(lst_a);
	stats->pivot_count = 15;
	stats->opcount = 0;
	stats->print_flag = 0;
	return (stats);
}