/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:29:33 by moouahab          #+#    #+#             */
/*   Updated: 2024/01/26 10:45:57 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include <sys/wait.h>

static void	init_struct(t_pipex	*data, char	**av, int ac)
{
	data->outflie = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	data->infile = open(av[1], O_RDONLY);
	if (data->infile == -1 || data->outflie == -1)
	{
		close (data->outflie);
		msg_error("\033[1;31mLe descripteur de fichier est incorrect ☠️\033[0m");
	}
	if (pipe(data->pipe) == -1)
		msg_error("les ne sont pas fait");
}

/**
 * WEXITSTATUS(status) - Macro pour récupérer le statut de sortie
 * d'un processus fils terminé.
 * 
 * @param status La valeur de statut retournée par wait() ou waitpid().
 * @return Le statut de sortie du processus fils.
 */

static int	close_data(t_pipex	*data)
{
	int	status;

	close(data->pipe[0]);
	close(data->pipe[1]);
	waitpid(data->id2, NULL, 0);
	waitpid(data->id, &status, 0);
	close(data->outflie);
	close(data->infile);
	return (WEXITSTATUS(status));
}

static void	id_exec_parent(t_pipex	*data, char *const	*env, char	**av, int i)
{
	data_init((char **)env, data, av, i);
	close(data->infile);
	exec_parent(data, env);
}

static void	id_exec_enfant(t_pipex	*data, char *const	*env, char	**av, int i)
{
	data_init((char **)env, data, av, i);
	close(data->outflie);
	exec_enfant(data, env);
}

int	main(int ac, char	**av, char *const	*env)
{	
	t_pipex	data;

	if (!get_path((char const **)env))
		msg_error("\033[1;31mil a plus de environnement ☠️\033[0m");
	if (ac == 5)
	{
		init_struct(&data, av, ac);
		data.id = fork();
		if (data.id == -1)
			msg_error("\033[1;31mle fork a echouer ☠️\033[0m");
		if (data.id == 0)
			id_exec_enfant(&data, env, av, 2);
		data.id2 = fork();
		if (data.id2 == -1)
			msg_error("\033[1;31mle fork a echouer ☠️\033[0m");
		if (data.id2 == 0)
			id_exec_parent(&data, env, av, 3);
		else
			return (close_data(&data));
	}
	return (0);
}
