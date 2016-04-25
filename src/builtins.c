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

static int  key_exist(char **env, char *key)
{
    int    exist;
    t_env   *tmp;

    exist = 0;
    tmp = env_to_list(env);
    while (tmp)
    {
        if (ft_strcmp(tmp->key, key) == 0)
            exist = 1;
        tmp = tmp->next;
    }
    return (exist);
}

static int         setenv_tpl(char *key, char *value, int overwrite, t_data *d)
{
    if (key_exist(d->env, key))
    {
        while (d->e)
        {
            if (ft_strcmp(d->e->key, key) == 0 && overwrite == 1)
                d->e->value->entry = ft_strdup(value);
            d->e = d->e->next;
        }
        while (d->e->prev)
            d->e = d->e->prev;
    }
    else
        push_back_list_en(&(d->e), key_new(key, val_new(value)));
    d->env = list_to_tab(d->e);
    return (1);
}

void           set_env(t_data *d, char **av)
{
    if ((!av[0] || !av[1] || !av[2] || ft_strcmp(ft_strtrim(av[0]), "setenv") != 0) ||
                (ft_atoi(av[2]) != 1 && ft_atoi(av[2]) != 0))
        ft_putstr_fd("please rtfm !\n", 2);
    else
        setenv_tpl(ft_strcut(ft_strdup(av[1]), '='), ft_strchr(ft_strdup(av[1]), '=') + 1, ft_atoi(av[2]), d);
}
