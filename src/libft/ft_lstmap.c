/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:25:09 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/06 17:58:51 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_tmp;

	lst_tmp = malloc(sizeof(t_list));
	if (!lst_tmp)
		return (NULL);
	lst_tmp = ft_lstnew(lst->content);
	if (!f || !lst)
		return (NULL);
	while (lst)
	{
		(f)(lst_tmp->content);
		lst_tmp = lst->next;
		lst = lst_tmp;
		ft_lstadd_back(&lst_tmp, lst);
	}
	return (lst_tmp);
}
