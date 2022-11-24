/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:26:10 by aestraic          #+#    #+#             */
/*   Updated: 2022/11/24 13:37:18 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <libft.h>
# include <limits.h>
# include <stdint.h>

//STRUCTS
typedef struct s_list_ps
{
	long				content;
	int					index;
	struct s_list_ps	*next;
}					t_list_ps;

typedef struct s_status
{
	int	lsta_c;
	int	piv_c;
	int	p_f;
	int	op_c;
	int	piv1;
	int	piv2;
	int	count_max_val;
	int	max_piv_c;
	int	min_piv_c;
	int	i;	
}					t_status;

typedef struct s_print
{
	char				*content;
	struct s_print		*next;
}					t_print;

//INPUT FUNCTIONS
t_list_ps	*build_stack_from_argv(t_list_ps *lst_a, char *str);
t_list_ps	*read_in(t_list_ps *lst_a, int nbr_arg, char **argv);
char		**read_input(char *str);
int			double_wrong_or_sorted(int n, char **a, t_list_ps *l, t_list_ps *h);
int			ft_strisdigit(char *str);
void		ft_free_split(char **str);
int			check_for_doubles(t_list_ps *l, t_list_ps *h);

//LIBFT-FUNCTIONS
void		ft_lstadd_front_ps(t_list_ps **lst, t_list_ps *new);
void		ft_lstadd_back_ps(t_list_ps **lst, t_list_ps *new);
t_list_ps	*ft_lstnew_ps(int content, int indx);
t_list_ps	*ft_lstlast_ps(t_list_ps *lst);
t_list_ps	*index_list(t_list_ps *lst);

//OPERATIONS
void		swap_nodes(t_list_ps *node1, t_list_ps *node2);
int			swap_a(t_list_ps **lst, int print_flag);
int			swap_b(t_list_ps **lst, int print_flag);
int			sswap(t_list_ps **lst_a, t_list_ps **lst_b, int print_flag);
int			push_a(t_list_ps **lst_a, t_list_ps **lst_b, int print_flag);
int			push_b(t_list_ps **lst_a, t_list_ps **lst_b, int print_flag);
int			rotate_a(t_list_ps **lst, int print_flag);
int			rotate_b(t_list_ps **lst, int print_flag);
int			rotate_rev_a(t_list_ps **lst, int print_flag);
int			rotate_rev_b(t_list_ps **lst, int print_flag);
int			rrab(t_list_ps **lsta, t_list_ps **lstb, int print_flag);
int			rrrab(t_list_ps **lsta, t_list_ps **lstb, int print_flag);
int			pb_rr(t_list_ps **lst_a, t_list_ps **lst_b, int print_flag);
int			pa_rr(t_list_ps **lst_a, t_list_ps **lst_b, int print_flag);
int			pb_rb(t_list_ps **lst_a, t_list_ps **lst_b, int print_flag);

//UTILS
t_status	*init_struct(t_list_ps *lst_a);
void		printlist(t_list_ps *lst);
void		printindex(t_list_ps *lst);
void		print_status(t_status *stats);
int			sort_check(t_list_ps *lst_a, t_list_ps *lst_b);
int			list_count(t_list_ps *lst);
int			rotate_or_rrotate(t_list_ps *lst_b, int index);
int			find_max_index(t_list_ps *lst_b);
int			check_for_push(t_list_ps *lst_b);
void		free_list(t_list_ps *lst);
void		ft_lstclear_ps(t_list_ps **lst);
void		ft_lstdelone_ps(t_list_ps *lst);
void		ft_waitforpipe(void);

//PIVOT
int			*pivotvalues(t_status *stats);
void		pivotisation(t_list_ps **lst_a, t_list_ps **lst_b, t_status *stats);
int			find_min_int(int *int_list, int max_c, int min_c);
int			optimal_pivot_value(char **argv, int argc, int i);
int			pivgroup_pushed(t_list_ps **lst, int piv_2);

//SORT
int			count_descending_max_values(t_list_ps *lst_b);
int			*build_max_values(int *max_values, int comp_val, t_list_ps *lst_b);
int			*descending_max_values(t_list_ps *lst_b);
void		sortpivgroup(t_list_ps **lst_a, t_list_ps **lst_b, t_status *stats);
void		p_val(t_list_ps **l_a, t_list_ps **l_b, int *mx_val, t_status *sts);
void		sort(t_list_ps **lst_a, t_list_ps **lst_b, t_status *stats, int i);
void		sort_3digit_stack(t_list_ps **lst_a, t_status *stats);
void		sort_small_stack(t_list_ps **lst_a, t_status *stats);

//BONUS
void		write_error_and_free(t_list_ps *lst_a, t_list_ps *lst_b);
int			commands(char *line, t_list_ps **lst_a, t_list_ps **lst_b);
int			read_instructions(t_list_ps **lst_a, t_list_ps **lst_b);

#endif