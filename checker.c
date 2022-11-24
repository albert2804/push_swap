/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:21:18 by aestraic          #+#    #+#             */
/*   Updated: 2022/11/24 13:59:03 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	execute_cmds_and_error(char *line, t_list_ps **lst_a, t_list_ps **lst_b)
{
	int	i;

	i = 1;
	if (line)
		i = commands(line, lst_a, lst_b);
	if (i == 0)
	{
		write(2, "Error\n", 6);
		ft_lstclear_ps(lst_a);
		ft_lstclear_ps(lst_b);
		return (0);
	}
	return (i);
}

/*
reads the instructions and executes the commands. 
If a wrong command was written, i becomes 0.

Afterwards the sort_check checks for proper sorting.
If sort_check equals 1 the stack has been sorted properly.
*/
int	read_instructions(t_list_ps **lst_a, t_list_ps **lst_b)
{
	char	*line;
	int		i;
	int		j;

	i = 1;
	j = 1;
	line = get_next_line(0);
	i = execute_cmds_and_error(line, lst_a, lst_b);
	if (i == 0)
		return (free(line), 2);
	while (line != NULL)
	{
		free (line);
		line = get_next_line(0);
		i = execute_cmds_and_error(line, lst_a, lst_b);
		if (i == 0)
			return (free(line), 2);
	}
	free(line);
	j = sort_check(*lst_a, *lst_b);
	return (j);
}

int	commands(char *line, t_list_ps **lst_a, t_list_ps **lst_b)
{
	if (ft_strncmp("ra\n", line, 3) == 0)
		return (rotate_a(lst_a, 0), 1);
	if (ft_strncmp("rb\n", line, 3) == 0)
		return (rotate_b(lst_b, 0), 1);
	else if (ft_strncmp("rra\n", line, 4) == 0)
		return (rotate_rev_a(lst_a, 0), 1);
	else if (ft_strncmp("rrb\n", line, 4) == 0)
		return (rotate_rev_b(lst_b, 0), 1);
	else if (ft_strncmp("sa\n", line, 3) == 0)
		return (swap_a(lst_a, 0), 1);
	else if (ft_strncmp("sb\n", line, 3) == 0)
		return (swap_b(lst_b, 0), 1);
	else if (ft_strncmp("pa\n", line, 3) == 0)
		return (push_a(lst_a, lst_b, 0), 1);
	else if (ft_strncmp("pb\n", line, 3) == 0)
		return (push_b(lst_a, lst_b, 0), 1);
	else if (ft_strncmp("ss\n", line, 3) == 0)
		return (sswap(lst_a, lst_b, 0), 1);
	else if (ft_strncmp("rr\n", line, 3) == 0)
		return (rrab(lst_a, lst_b, 0), 1);
	else if (ft_strncmp("rrr\n", line, 4) == 0)
		return (rrrab(lst_a, lst_b, 0), 1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_list_ps	*lst_a;
	t_list_ps	*lst_b;
	int			i;

	lst_a = NULL;
	lst_b = NULL;
	if (argc == 1)
		exit(0);
	else if (double_wrong_or_sorted(argc, argv, NULL, NULL) == 1)
		ft_lstclear_ps(&lst_a);
	else
	{
		lst_a = read_in(lst_a, argc, argv);
		lst_a = index_list(lst_a);
		i = read_instructions(&lst_a, &lst_b);
		if (i == 0)
			write (1, "KO", 2);
		else if (i == 1)
			write (1, "OK", 2);
		ft_lstclear_ps(&lst_a);
		ft_lstclear_ps(&lst_b);
	}
	ft_waitforpipe();
	exit (0);
}
