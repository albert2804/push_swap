/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:26:10 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/28 12:57:21 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <libft.h>

typedef struct s_list_ps
{
	int					content;
	int					index;
	struct s_list_ps	*next;
}					t_list_ps;

typedef struct s_status
{
	int piv1;
	int piv2;
	int print_flag;
	int pivot;
	int	inserted_elem;
	int list_count;
	int	pivot_count;
}					t_status;

t_list_ps	*build_stack_A1(char *str);
t_list_ps	*build_stack_A2(char **argv);

void		ft_lstadd_front_ps(t_list_ps **lst, t_list_ps *new);
void		ft_lstadd_back_ps(t_list_ps **lst, t_list_ps *new);
t_list_ps	*ft_lstnew_ps(int content, int indx);
t_list_ps	*ft_lstlast_ps(t_list_ps *lst);
void 		swap_nodes(t_list_ps *node1, t_list_ps *node2);
int	 		swap_a(t_list_ps **lst, int print_flag);
int	 		swap_b(t_list_ps **lst, int print_flag);
int	 		push_a(t_list_ps **lst_a, t_list_ps **lst_b, int print_flag);
int	 		push_b(t_list_ps **lst_a, t_list_ps **lst_b, int print_flag);
int	 		rotate_a(t_list_ps **lst, int print_flag);
int	 		rotate_b(t_list_ps **lst, int print_flag);
int	 		rotate_rev_a(t_list_ps **lst, int print_flag);
int			rotate_rev_b(t_list_ps **lst, int print_flag);

void 		printList(t_list_ps *lst);
void 		printIndex(t_list_ps *lst);
int 		sort_check(t_list_ps *lst_a);
int 		list_count(t_list_ps *lst);

t_list_ps 	*index_list(t_list_ps *lst);
int 		*pivotvalues(int list_count, int pivot_count);
int			pivotisation(t_list_ps **lst_a, t_list_ps **lst_b, int piv1, int piv2, int print_flag);
int 		sortPivotgroup(t_list_ps **lst_a, t_list_ps **lst_b, int pivot, int print_flag);
int 		*find_edge_elements(t_list_ps *lst_a, int inserted_elem);

int			find_max_index(t_list_ps *lst_b);
int			count_descending_max_values(t_list_ps *lst_b);
int			*build_max_values(int *max_values, int compare_value, t_list_ps *lst_b);
int			*descending_max_values(t_list_ps *lst_b);
int			check_for_push(t_list_ps *lst_b);
int			rotate_or_rrotate(t_list_ps *lst_b, int index);
int			push_values(t_list_ps **lst_a, t_list_ps **lst_b, int *max_val, int c_val, int print_flag);
int			sortPivotgroup(t_list_ps **lst_a, t_list_ps **lst_b, int pivot, int print_flag);
void		sort(t_list_ps **lst_a, t_list_ps **lst_b, int pivot_count);

// int 		*pivotvalues(status stats);
// int			pivotisation(t_list_ps **lst_a, t_list_ps **lst_b, status stats);
// int 		sortPivotgroup(t_list_ps **lst_a, t_list_ps **lst_b, status stats);
// int 		*find_edge_elements(t_list_ps *lst_a, status stats);

# endif