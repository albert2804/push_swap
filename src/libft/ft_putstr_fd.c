/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:25:09 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/06 17:56:46 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	len_str;

	if (!s)
		return ;
	len_str = ft_strlen(s);
	i = 0;
	while (i < len_str)
	{
		write(fd, &s[i], 1);
		i++;
	}
}
