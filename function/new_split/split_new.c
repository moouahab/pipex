/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:23:37 by moouahab          #+#    #+#             */
/*   Updated: 2024/01/21 12:33:50 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static void	ft_spilt_norm(char	**strs, char	*str, char	*start, int in)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (is_sp(*str))
		{
			if (in)
			{
				strs[i++] = ft_strndup_new(start, str - start);
				in = 0;
			}
			start = str + 1;
		}
		else if (!in)
		{
			start = str;
			in = 1;
		}
		str++;
	}
	if (in)
		strs[i++] = ft_strndup_new(start, str - start);
	strs[i] = NULL;
}

char	**split_new(char	*str)
{
	char	*start;
	char	**strs;
	int		inside_word;	

	inside_word = 0;
	if (!str)
		msg_error("\033[1;31mstr non init dans split ☠️\033[0m");
	strs = malloc((count_word(str) + 1) * sizeof(char *));
	if (!strs)
		msg_error("\033[1;31mle malloc a echouer ☠️\033[0m");
	start = str;
	ft_spilt_norm(strs, str, start, inside_word);
	return (strs);
}
