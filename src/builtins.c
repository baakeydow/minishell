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

void			print_env(t_env *e)
{
	while (e)
	{
		ft_putstr_fd(e->key, 2);
		while (e->value)
		{
			ft_putstr_fd(e->value->entry, 2);
			if (e->value->next)
				ft_putchar_fd(':', 2);
			e->value = e->value->next;
		}
		ft_putchar_fd('\n', 2);
		e = e->next;
	}
}
