/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:18:15 by moouahab          #+#    #+#             */
/*   Updated: 2024/01/26 01:58:58 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>
# include <sys/wait.h>

typedef struct pipex
{
	char	*path;
	char	**commande;
	char	**chemain_access;
	pid_t	id;
	pid_t	id2;
	int		infile;
	int		outflie;
	int		pipe[2];
}t_pipex;

// init_function
char	*recovery(char	**env);
void	data_init(char	**env, t_pipex	*data, char	**av, int index);
void	free_data(t_pipex	*data);
char	*chemain_access(t_pipex *head);
void	exec_parent(t_pipex	*data, char *const *env);
void	exec_enfant(t_pipex	*data, char *const *env);

// fuunction split 
bool	is_sp(char str);
int		count_word(char	*str);
char	*ft_strndup(char *src, size_t	len);
void	free_tab(char	**strs);
int		strslen(char	**strs);
char	**split(char	*str);
char	*ft_strndup_new(char *src, size_t	len);
char	**split_new(char	*str);

// substr
size_t	ft_strlen(const char	*str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const	*s1, char const	*s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memset(void	*s, int c, size_t n);
void	*ft_calloc(size_t num_elements, size_t element_size);
int		ft_strncmp(const char	*s1, const char	*s2, size_t n);

// ft_put
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char	*s, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char	*str, int fd);

// error 

void	msg_error(char *error);
bool	get_path(const char	**env);
char	*ft_strndup_new(char *src, size_t	len);

#endif