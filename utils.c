/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:30:47 by aestraic          #+#    #+#             */
/*   Updated: 2022/06/17 14:29:30 by aestraic         ###   ########.fr       */
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

