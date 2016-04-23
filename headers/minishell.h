/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 17:15:14 by bndao             #+#    #+#             */
/*   Updated: 2016/04/22 18:40:30 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# define CLEAR ft_putstr("\033c");
# define RESET ft_putstr("\x1B[0m");

typedef struct          s_val
{
    char                *entry;
    struct s_val        *next;
}                       t_val;

typedef struct          s_env
{
    char                *key;
    struct s_val        *value;
    struct s_env        *next;
}                       t_env;

void			print_env(t_env *e);
char	       	*bin_to_path(char *path, char *bin);
char	       	*find_path_to_bin(char *cmd, t_env *e);

t_val           *val_new(char *value);
t_env			*key_new(char *key, t_val *v);
t_val           *path_to_list(char *str);
t_env           *env_to_list(char **env);
void			push_back_list_val(t_val *b_list, t_val *new);
void			push_back_list_en(t_env *b_list, t_env *new);

int				fields(char **env);
int				is_dir(char *str);
void			print_that_tab(char **tab);
char			*ft_strcut(char *str, char c);

#endif
