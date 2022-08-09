/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:30:47 by aestraic          #+#    #+#             */
/*   Updated: 2022/08/09 15:13:33 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list_ps	*ft_lstnew_ps(int content, int indx)
{
	t_list_ps	*list;

	list = ft_calloc(sizeof(t_list_ps), 1);
	if (!list)
		return (NULL);
	list->content = content;
	list->index = indx;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_front_ps(t_list_ps **lst, t_list_ps *new)
{
	if (lst)
	{
		if (*lst)
			new -> next = *lst;
		*lst = new;
	}
}

t_list_ps	*ft_lstlast_ps(t_list_ps *lst)
{
	//int i = 0;
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		// ft_printf("I: %d", i++);
		lst = lst -> next;
	}
	return (lst);
}

void	ft_lstadd_back_ps(t_list_ps **lst, t_list_ps *new)
{
	t_list_ps	*lst_tmp;

	if (!*lst && !new)
		return ;
	if (!*lst)
	{
		(*lst) = new;
		return ;
	}
	else
	{
		lst_tmp = ft_lstlast_ps(*lst);
		if (lst_tmp)
		{
			lst_tmp->next = new;
		}
	}
}
