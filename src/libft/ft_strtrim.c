/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:25:09 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/06 18:34:52 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_set_in_str(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

static size_t	ft_first_pos(char const *s, char const *set)
{
	size_t	len_str;
	size_t	i;

	i = 0;
	len_str = ft_strlen(s);
	while (i < len_str && ft_set_in_str(s[i], set) == 0)
		i++;
	return (i);
}

static size_t	ft_last_pos(char const *s, char const *set)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i > 0 && ft_set_in_str(s[i], set) == 0)
		i--;
	if (i < 0)
		i = 0;
	return (i);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*sub_str;
	size_t	i;	

	i = 0;
	if (!set || !str)
		return (NULL);
	if (ft_first_pos(str, set) > ft_last_pos(str, set))
		sub_str = ft_strdup("");
	else
	{
		sub_str = malloc((ft_last_pos(str, set) - ft_first_pos(str, set) + 2) \
		* sizeof(char));
		if (!sub_str)
			return (NULL);
		while (i < (ft_last_pos(str, set) - ft_first_pos(str, set) + 2) + 1)
		{
			sub_str[i] = str[ft_first_pos(str, set) + i];
			i++;
		}
	sub_str[i] = '\0';
	}
	return (sub_str);
}
