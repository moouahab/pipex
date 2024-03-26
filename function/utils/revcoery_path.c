/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revcoery_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:58:09 by moouahab          #+#    #+#             */
/*   Updated: 2024/01/25 23:45:42 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	*recovery(char	**env)
{
	int		i;
	char	*str;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			str = (char *)env[i];
		i++;
	}
	return (str);
}

void	find_path(t_pipex	*data)
{
	int	i;

	i = 0;
	data->path = data->commande[0];
	if (data->path)
		if (!access(data->path, F_OK | X_OK))
			return ;
	while (i <= strslen(data->chemain_access))
	{
		data->path = ft_strjoin(data->chemain_access[i], data->commande[0]);
		if (data->path)
		{
			if (!access(data->path, F_OK | X_OK))
				return ;
			free(data->path);
		}
		else
		{
			free_data(data);
			msg_error("\033[1;31mdata.path est faux ☠️\033[0m");
		}
		i++;
	}
	free_data(data);
	msg_error("\033[1;31maccess na pas trouver le path ☠️\033[0m");
}

void	free_data(t_pipex	*data)
{
	if (data->path != NULL)
		free(data->path);
	free_tab(data->chemain_access);
	free_tab(data->commande);
	close(data->outflie);
	close(data->infile);
	close(data->pipe[1]);
	close(data->pipe[0]);
}

void	data_init(char	**env, t_pipex	*data, char	**av, int index)
{
	char	*tmp;

	tmp = recovery((char **)env);
	data->path = ft_substr(tmp, 5, ft_strlen(tmp) - 5);
	data->chemain_access = split(data->path);
	free(data->path);
	if (av[index])
	{
		data->commande = split_new(av[index]);
		find_path(data);
	}
}
