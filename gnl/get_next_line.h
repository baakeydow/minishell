/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 02:55:44 by bndao             #+#    #+#             */
/*   Updated: 2016/04/22 18:48:21 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# define BUFF_SIZE 10
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

int			get_next_line(int const fd, char **line);

#endif
