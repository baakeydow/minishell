/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 19:57:28 by bndao             #+#    #+#             */
/*   Updated: 2016/04/23 19:57:30 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

struct s_builtins	tab[TAB_SIZE] = {{"setenv", &set_env}, {"env", &print_env}};

int					handle(t_builtins tab[TAB_SIZE], t_data *d, char **av)
{
	int			i;

	i = 0;
	while (i < TAB_SIZE)
	{
		if (ft_strcmp(tab[i].cmd, ft_strtrim(av[0])) == 0)
		{
			tab[i].f(d, av);
			return (1);
		}
		i++;
	}
	return (0);
}
