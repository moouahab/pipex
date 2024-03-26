/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_new_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 08:48:40 by moouahab          #+#    #+#             */
/*   Updated: 2024/01/23 17:28:44 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	*ft_strndup_new(char *src, size_t	len)
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
	dest[i] = '\0';
	return (dest);
}
