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

t_val					*val_new(char *value)
{
	t_val			*node;

	if (!(node = (t_val *)malloc(sizeof(t_val))))
		return (NULL);
	node->entry = value;
	node->next = NULL;
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
	return (node);
}

t_env               *env_to_list(char **env)
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
            push_back_list_en(e, key_new(ft_strcut(ft_strdup(env[i]), '='), v));
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
