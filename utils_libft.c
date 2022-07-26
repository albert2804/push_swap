/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:30:47 by aestraic          #+#    #+#             */
/*   Updated: 2022/06/17 16:16:46 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <push_swap.h>

t_list_ps	*ft_lstnew_ps(int content, int indx)
{
	t_list_ps	*list;

	list = malloc(sizeof(t_list_ps));
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
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

void	ft_lstadd_back_ps(t_list_ps **lst, t_list_ps *new)
{
	t_list_ps	*lst_tmp;

	//if (!*lst || !new) otherwise an empty list has to be malloced.
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
			lst_tmp-> next = new;
		}
	}
}





