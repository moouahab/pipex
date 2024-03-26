/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 08:48:40 by moouahab          #+#    #+#             */
/*   Updated: 2024/01/25 15:42:16 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

bool	is_sp(char str)
{
	if (str == ':' || (str < 14 && str > 8)
		|| str == 32)
		return (true);
	return (false);
}

int	count_word(char	*str)
{
	int	inside_word;
	int	count;

	count = 0;
	inside_word = 0;
	while (*str)
	{
		if (is_sp(*str))
			inside_word = 0;
		else if (!inside_word)
		{
			count++;
			inside_word = 1;
		}
		str++;
	}
	return (count);
}

char	*ft_strndup(char *src, size_t	len)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(len * sizeof(char *) + 1);
	if (!dest)
		return (NULL);
	while (len-- > 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '/';
	dest[i + 1] = '\0';
	return (dest);
}

void	free_tab(char	**strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	strslen(char	**strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}
