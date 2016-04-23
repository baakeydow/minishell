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

t_val               *path_to_list(char *str)
{
    t_val           *v;
    char            **tab;
    int             j;

    tab = ft_strsplit(ft_strchr(ft_strdup(str), '=') + 1, ':');
    v = val_new(tab[0]);
    j = 1;
    while (tab[j])
        push_back_list_val(v, val_new(tab[j++]));
    return (v);
}
