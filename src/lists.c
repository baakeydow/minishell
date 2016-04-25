/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 20:37:07 by bndao             #+#    #+#             */
/*   Updated: 2016/04/23 20:37:08 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_val					*val_new(char *value)
{
	t_val			*node;

	if (!(node = (t_val *)malloc(sizeof(t_val))))
		return (NULL);
	node->entry = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_env					*key_new(char *key, t_val *v)
{
	t_env			*node;

	if (!(node = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	node->key = key;
    node->value = v;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_val         		     *path_to_list(char *str)
{
    t_val           *v;
    char            **tab;
    int             j;

    tab = ft_strsplit(ft_strchr(ft_strdup(str), '=') + 1, ':');
    v = val_new(tab[0]);
    j = 1;
    while (tab[j])
        push_back_list_val(&v, val_new(tab[j++]));
    return (v);
}

t_env             	  *env_to_list(char **env)
{
    t_env           *e;
    t_val           *v;
    int             i;

    i = 0;
    e = NULL;
    if (!*env)
        return (NULL);
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
            v = path_to_list(env[i]);
        else
            v = val_new(ft_strchr(ft_strdup(env[i]), '=') + 1);
        if (!e)
            e = key_new(ft_strcut(ft_strdup(env[i]), '='), v);
        else
            push_back_list_en(&e, key_new(ft_strcut(ft_strdup(env[i]), '='), v));
        i++;
    }
    return (e);
}

t_data				*new_data(int ac, char **av, char **environ)
{
	t_data		*d;

	if (!(d = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	d->ac = ac;
	d->av = av;
	d->env = environ;
	d->e = env_to_list(environ);
	return (d);
}
