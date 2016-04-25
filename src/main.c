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

int					main(int ac, char **av, char **environ)
{
	t_data	*d;

	CLEAR;
	if (ac != 1)
		error_handler(av[0], 0);
	ft_putstr("$> ");
	d = new_data(ac, av, environ);
	forked(d);
	return (0);
}
