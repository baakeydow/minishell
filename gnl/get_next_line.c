/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 03:20:06 by bndao             #+#    #+#             */
/*   Updated: 2016/03/14 19:35:53 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char					*analyse_buf(char *buf, char **line)
{
	char			*keep;
	char			*d;

	if (!(keep = ft_strchr(buf, '\n')))
	{
		d = *line;
		*line = ft_strjoin(*line, buf);
		if (d)
			free(d);
		return (NULL);
	}
	*keep++ = '\0';
	d = *line;
	*line = ft_strjoin(*line, buf);
	if (d)
		free(d);
	return (ft_strdup(keep));
}

char					*buf_to_string(char *buf, char **line, char *kept)
{
	char			*dup;

	if (!kept)
		return (analyse_buf(buf, line));
	else
	{
		if (!(dup = ft_strjoin(kept, buf)))
			return (NULL);
		return (analyse_buf(dup, line));
	}
}

int						get_next_line(int const fd, char **line)
{
	int				ret;
	char			*buf;
	static char		*kept[2147483648];

	if (!line || fd < 0)
		return (-1);
	*line = ft_strdup("");
	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((kept[fd] = buf_to_string(buf, line, kept[fd])))
		{
			free(buf);
			return (1);
		}
	}
	if (ret == -1)
		return (-1);
	buf[ret] = '\0';
	kept[fd] = buf_to_string(buf, line, kept[fd]);
	free(buf);
	return (ft_strlen(*line) || kept[fd] ? 1 : 0);
}
