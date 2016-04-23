/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:46:54 by bndao             #+#    #+#             */
/*   Updated: 2016/04/22 18:59:38 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				*bin_to_path(char *path, char *bin)
{
	size_t	len1;
	size_t	len2;
	char	*name;

	if (!path)
		return (NULL);
	len1 = ft_strlen(path);
	len2 = ft_strlen(bin);
	if (!(name = ft_strnew((len1 + len2) + 1)))
		return (NULL);
	ft_memcpy(name, path, len1);
	name[len1] = '/';
	ft_memcpy((name + len1) + 1, bin, len2);
	return (name);
}

char				*find_path_to_bin(char *cmd, t_env *e)
{
	DIR				*dir;
	struct dirent	*f;

	dir = NULL;
	f = NULL;
	while (e)
	{
		if (ft_strcmp(e->key, "PATH=") == 0)
			while (e->value)
			{
				if ((dir = opendir(e->value->entry)))
					while ((f = readdir(dir)))
						if ((ft_strcmp(f->d_name, cmd) == 0))
							return (bin_to_path(e->value->entry, cmd));
				e->value = e->value->next;
			}
		e = e->next;
	}
	return (NULL);
}

int					main(int ac, char **av, char **environ)
{
	char	**cmd;
	char	*asked;
	t_env	*e;
	pid_t	c_pid;
	pid_t	f_pid;

	CLEAR;
	if (ac == 1)
		ft_putstr(av[0]);
	ft_putchar_fd('\n', 2);
	e = env_to_list(environ);
	while (get_next_line(0, &asked) > 0)
	{
		c_pid = fork();
		if (c_pid == 0)
		{
			cmd = ft_strsplit(asked, ' ');
			execve(find_path_to_bin(ft_strtrim(cmd[0]), e), cmd, environ);
		}
		while (f_pid != c_pid)
			f_pid = wait(NULL);
	}
	return (0);
}
