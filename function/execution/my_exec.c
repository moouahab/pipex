/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:38:36 by moouahab          #+#    #+#             */
/*   Updated: 2024/01/25 18:34:29 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/**
 * exec_parant va prendre en parametre data et env
 * nous allon commencer a lui dire de copie la entre
 * standar dans le fd infile puis une le fermont 
 * pour evite des vite fuite de memoire 
 * 
 * une fois cette etape faite nous fermon le fd du pipe 
 * non utiliser dans le cas du parent est ce lui de la 
 * lecture, et nous demmandont que copier dans le fd ecriture
 * la sortie storti standar fait une le fermont et nous excuton 
 * avec execve   
 * 
 * si exeve echou on free tout et on renvoi un message d'erreur 
 * 
*/

// chemin absolue pas fait, si l'entree est /bin/cat ca doit marcher
// donc faire en premier un access :
//	1 - si ca marche pas tu fais ton join classique
//	2 - si ca marche execve direct sur ca

void	exec_enfant(t_pipex *data, char *const *env)
{
	dup2(data->infile, STDIN_FILENO);
	close(data->infile);
	close(data->pipe[0]);
	dup2(data->pipe[1], STDOUT_FILENO);
	close(data->pipe[1]);
	if (execve(data->path, data->commande, env) == -1)
	{
		free_data(data);
		msg_error("\033[1;31mexcve n'est pue excuter\033[0m");
	}
}

void	exec_parent(t_pipex *data, char *const *env)
{
	if (dup2(data->outflie, STDOUT_FILENO) == -1)
		msg_error("error");
	close(data->outflie);
	close(data->pipe[1]);
	if (dup2(data->pipe[0], STDIN_FILENO) == -1)
		msg_error("error");
	close(data->pipe[0]);
	if (execve(data->path, data->commande, env) == -1)
	{
		free_data(data);
		msg_error("\033[1;31mexcve n'est pue excuter\033[0m");
	}
}
