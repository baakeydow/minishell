/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 03:49:13 by bndao             #+#    #+#             */
/*   Updated: 2016/04/24 03:49:15 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			     	*bin_to_path(char *path, char *bin)
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
	if (is_in(cmd, '/'))
		return (check_absolute(cmd));
	while (e)
	{
		if (ft_strcmp(e->key, "PATH=") == 0)
			while (e->value)
			{
				if ((dir = opendir(e->value->entry)))
				{
					while ((f = readdir(dir)))
						if ((ft_strcmp(f->d_name, cmd) == 0))
							return (bin_to_path(e->value->entry, cmd));
					close_dir(dir);
				}
				e->value = e->value->next;
			}
		e = e->next;
	}
	return (NULL);
}

void				launch_it(char *asked, t_data *d)
{
	char	**cmd;
	char	*path;

	cmd = ft_strsplit(asked, ' ');
    if (handle(tab, d, cmd))
        ;
	else if (!(path = find_path_to_bin(ft_strtrim(cmd[0]), d->e)))
		error_handler(cmd[0], 1);
	else
		execve(path, cmd, d->env);
}

void				forked(t_data *d)
{
	char	*asked;
	pid_t	c_pid;
	pid_t	f_pid;

	f_pid = 0;
	while (get_next_line(0, &asked) > 0)
	{
		c_pid = fork();
		if (c_pid == 0)
			launch_it(asked, d);
		else
			while (f_pid != c_pid)
				f_pid = wait(NULL);
		ft_putstr("$> ");
	}
}
