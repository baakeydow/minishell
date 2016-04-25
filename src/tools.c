/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 19:05:24 by bndao             #+#    #+#             */
/*   Updated: 2016/04/23 19:05:28 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			is_in(char *fmt, char c)
{
	int		i;

	i = 0;
	if (!fmt)
		return (0);
	while (fmt[i])
	{
		if (fmt[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char				*check_absolute(char *cmd)
{
	struct stat		s;

	if (stat(cmd, &s) != 0)
		error_handler(cmd, 2);
	return (cmd);
}

int				close_dir(DIR *dir)
{
	if (dir && closedir(dir) == -1)
	{
		ft_putstr_fd("Error while closing dir", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int				is_dir(char *str)
{
	struct stat s;

	if (!str)
		return (0);
	if (stat(str, &s) == 0)
		if (s.st_mode & S_IFDIR)
			return (1);
	return (0);
}

int				fields(char **env)
{
	int		i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char			*ft_strcut(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != c)
		i++;
	if (!str[i] || i == 0)
		return (NULL);
	return (ft_strsub(str, 0, i + 1));
}

void			print_that_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		ft_putendl(tab[i++]);
}

void			print_env(t_data *d, char **av)
{
	(void)av;
	print_that_tab(d->env);
}

int				ft_list_size(t_env *b)
{
	return (b) ? (ft_list_size(b->next) + 1) : (0);
}
