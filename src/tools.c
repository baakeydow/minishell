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

int				close_dir(DIR *dir)
{
	if (dir && closedir(dir) == -1)
	{
		ft_putstr("Error while closing dir");
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

void			print_that_list(t_env *e)
{
	while (e)
	{
		ft_putstr(e->key);
		while (e->value)
		{
			ft_putstr(e->value->entry);
			if (e->value->next)
				ft_putchar(':');
			e->value = e->value->next;
		}
		ft_putchar('\n');
		e = e->next;
	}
}
