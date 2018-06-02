/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 00:35:58 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/29 00:36:00 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			free_elem(char *c1, char *c2, char *c3)
{
	free(c1);
	free(c2);
	free(c3);
}

void			free_elem_el(char *c1, char *c2)
{
	free(c1);
	free(c2);
}

void			ft_recurse_f(t_file **tmp, t_file *directory, t_opt opt)
{
	*tmp = directory;
	while (directory)
	{
		do_recurse(directory->name, directory->path, opt);
		directory = directory->next;
	}
}

char			*ft_path_el(char *path, char *str)
{
	char		*tmp;

	if (str[0] != '/')
	{
		path = ft_strdup(".");
		tmp = path;
		path = ft_strjoin(path, "/");
		free(tmp);
		tmp = path;
		path = ft_strjoin(path, str);
		free(tmp);
	}
	else
		path = ft_strdup(str);
	return (path);
}

char			*ft_path_path(char *path, char *str)
{
	if (str[0] != '/')
	{
		path = ft_strdup(".");
		path = ft_join_f(path, "/");
		path = ft_join_f(path, str);
	}
	else
		path = ft_strdup(str);
	return (path);
}
