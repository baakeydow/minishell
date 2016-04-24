/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 17:33:26 by bndao             #+#    #+#             */
/*   Updated: 2016/04/23 17:33:28 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		      		error_handler(char *str, int num)
{
	if (num == 0)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(" : Error Too Many Arguments !\n", 2);
		exit(1);
	}
	else if (num == 1)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
		exit(1);
	}
	else if (num == 2)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(" : No such file or directory \n", 2);
		exit(1);
	}
}

void					push_back_list_val(t_val *b_list, t_val *new)
{
	t_val		*tmp;

	if (b_list == NULL)
		b_list = new;
	else
	{
		tmp = b_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void					push_back_list_en(t_env *b_list, t_env *new)
{
	t_env		*tmp;

	if (b_list == NULL)
		b_list = new;
	else
	{
		tmp = b_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void			print_that_list(t_data *d)
{
	while (d->e)
	{
		ft_putstr_fd(d->e->key, 2);
		while (d->e->value)
		{
			ft_putstr_fd(d->e->value->entry, 2);
			if (d->e->value->next)
				ft_putchar_fd(':', 2);
			d->e->value = d->e->value->next;
		}
		ft_putchar_fd('\n', 2);
		d->e = d->e->next;
	}
}

char		          	**list_to_tab(t_env *e)
{
    char       **tab;
    int        size;
    int        i;

    i = 0;
    size = ft_list_size(e);
    tab = NULL;
    if (!(tab = (char **)malloc(sizeof(char *) * (size + 1))))
        return (NULL);
    tab[size] = NULL;
	while (e)
	{
		if (e->value && e->value->entry)
        {
            tab[i] = ft_strjoin(e->key, e->value->entry);
            e->value = e->value->next;
            while (e->value)
            {
                tab[i] = ft_strjoin(tab[i], ":");
                tab[i] = ft_strjoin(tab[i], e->value->entry);
                e->value = e->value->next;
            }
        }
        else
            tab[i] = ft_strdup(e->key);
		i++;
		e = e->next;
	}
    return (tab);
}
