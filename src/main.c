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

char				*find_path_to_bin(char *cmd, t_env *e)
{
	DIR				*dir;
	struct dirent	*f;

	dir = NULL;
	f = NULL;
	if (is_in(cmd, '/'))
		return (check_absolute(cmd));
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

void				launch_it(char *asked, t_env *e, char **environ)
{
	char	**cmd;
	char	*path;

	cmd = ft_strsplit(asked, ' ');
	if (!(path = find_path_to_bin(ft_strtrim(cmd[0]), e)))
		error_handler(cmd[0], 1);
	else
		execve(path, cmd, environ);
}

void				forked(t_env *e, char **environ)
{
	char	*asked;
	pid_t	c_pid;
	pid_t	f_pid;

	f_pid = 0;
	while (get_next_line(0, &asked) > 0)
	{
		c_pid = fork();
		if (c_pid == 0)
			launch_it(asked, e, environ);
		else
			while (f_pid != c_pid)
				f_pid = wait(NULL);
		ft_putstr("$> ");
	}
}

int					main(int ac, char **av, char **environ)
{
	t_env	*e;

	CLEAR;
	if (ac != 1)
		error_handler(av[0], 0);
	ft_putstr("$> ");
	e = env_to_list(environ);
	forked(e, environ);
	return (0);
}
