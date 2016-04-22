/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:50:37 by bndao             #+#    #+#             */
/*   Updated: 2016/01/01 17:50:39 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_islower(int c)
{
	if (96 < c && c < 123)
		return (1);
	return (0);
}

int			ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}
