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

static char				**fill_it_in(char **tab, int i, t_val *value)
{
	while (value)
	{
		tab[i] = ft_strjoin(tab[i], ":");
		tab[i] = ft_strjoin(tab[i], value->entry);
		value = value->next;
	}
	return (tab);
}

char		          	**list_to_tab(t_env *e)
{
    char       **tab;
    int        size;
    int        i;

    i = 0;
    size = ft_list_size(e);
    if (!(tab = (char **)malloc(sizeof(char *) * (size + 1))))
        return (NULL);
    tab[size] = NULL;
	while (e)
	{
		if (e->value && e->value->entry)
        {
            tab[i] = ft_strjoin(e->key, e->value->entry);
            e->value = e->value->next;
			if (e->value)
				tab = fill_it_in(tab, i, e->value);
        }
        else
            tab[i] = ft_strdup(e->key);
		i++;
		e = e->next;
	}
    return (tab);
}
