/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:06:37 by aestraic          #+#    #+#             */
/*   Updated: 2022/07/06 17:56:24 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	j;	

	i = 0;
	j = 0;
	while (s[i] == c)
	{
		if (i == ft_strlen(s) - 1)
			return (j);
		i++;
	}
	while (i < ft_strlen(s))
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
		i++;
	}
	i = 0;
	if (s[0] != '\0')
		j++;
	return (j);
}

static size_t	*ft_get_first_positions(const char *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	j;
	size_t	*positions;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	positions = malloc((ft_word_count(s, c) + 1) * sizeof(size_t));
	while (s[i] == c)
		i++;
	if (s[i] != c)
		positions[j] = i;
	while (i < len)
	{
		if (s[i] == c && s[i + 1] != c)
		{
			j++;
			positions[j] = i + 1;
		}
	i++;
	}
	return (positions);
}

static size_t	*ft_get_last_positions(const char *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	j;
	size_t	*positions;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	positions = malloc((ft_word_count(s, c) + 1) * sizeof(size_t));
	while (i < len)
	{
		if (s[i] != c && s[i + 1] == c)
		{
			positions[j] = i;
			j++;
		}
	i++;
	}
	if (i == len)
		positions[j] = i - 1;
	return (positions);
}

static void	ft_write_array(char const *s, char c, char **array)
{
	size_t	i;
	size_t	*first_pos;
	size_t	*last_pos;

	first_pos = ft_get_first_positions(s, c);
	last_pos = ft_get_last_positions(s, c);
	i = 0;
	while (i < ft_word_count(s, c))
	{
		array[i] = ft_substr(s, first_pos[i], last_pos[i] - first_pos[i] + 1);
		i++;
	}
	array[i] = NULL;
	free(first_pos);
	free(last_pos);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	ft_write_array(s, c, array);
	return (array);
}
