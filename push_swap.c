/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:44:33 by aestraic          #+#    #+#             */
/*   Updated: 2022/06/15 14:31:46 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <push_swap.h>

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

void sort(t_list_ps **lst_a, t_list_ps **lst_b)
{
	int check;
	
	check = 0;
	t_list_ps **b = lst_b;
	b = NULL;
	while (check != 1)
	{
		(*lst_a) = rotate_rev(*lst_a);
		check = sort_check(*lst_a);
	}
}

int main(int argc, char **argv)
{
	t_list_ps *lst_a;
	t_list_ps *lst_b;
	int elem;
	t_list_ps *new_node;
	int i;
	i = argc;
	
	elem = ft_atoi((argv[1]));
	lst_a = ft_lstnew_ps(elem);
	lst_b = ft_lstnew_ps(elem);
	
	elem = ft_atoi((argv[2]));
	new_node = ft_lstnew_ps(elem);
	ft_lstadd_back_ps(&lst_a, new_node);
	new_node = ft_lstnew_ps(elem);
	ft_lstadd_back_ps(&lst_b, new_node);
	
	elem = ft_atoi((argv[3]));
	new_node = ft_lstnew_ps(elem);
	ft_lstadd_back_ps(&lst_a, new_node);
	new_node = ft_lstnew_ps(elem);
	ft_lstadd_back_ps(&lst_b, new_node);
	
	elem = ft_atoi((argv[4]));
	new_node = ft_lstnew_ps(elem);
	ft_lstadd_back_ps(&lst_a, new_node);
	new_node = ft_lstnew_ps(elem);
	ft_lstadd_back_ps(&lst_b, new_node);
	
	sort(&lst_a, &lst_b);
}