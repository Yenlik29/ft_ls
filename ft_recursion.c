/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 11:42:20 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/26 15:50:56 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_none(t_file *all, t_file **tmp,
					t_file **file, t_file **directory)
{
	if (!(S_ISDIR(all->st_mode)))
		*file = insert_sorted(*file, all->name, all->add);
	if (S_ISDIR(all->st_mode) && ft_strcmp(all->name, ".") != 0 &&
		ft_strcmp(all->name, "..") != 0 &&
		all->name[0] != '.' && (!S_ISLNK(all->st_mode)))
	{
		*tmp = insert_sorted(*tmp, all->name, all->add);
		*directory = insert_sorted(*directory, all->name, all->add);
	}
}

void			ft_f(t_file *all, t_file **directory, t_file **new, char *path)
{
	if (S_ISDIR(all->st_mode) && ft_strcmp(all->name, ".") != 0 &&
		ft_strcmp(all->name, "..") != 0 && (!S_ISLNK(all->st_mode)))
	{
		*directory = insert_sorted(*directory, all->name, path);
		if (*new == NULL)
			*new = ft_list_new(all->path, all->name, "nothing");
		else
			*new = ft_list_add(new, all->name, all->path, "nothing");
	}
	else
	{
		if (*new == NULL)
			*new = ft_list_new(all->path, all->name, "nothing");
		else
			*new = ft_list_add(new, all->name, all->path, "nothing");
	}
}

void			ft_none_f(t_file *all, t_file **tmp,
					t_file **directory, t_file **file)
{
	if (S_ISDIR(all->st_mode) && ft_strcmp(all->name, ".") != 0 &&
		ft_strcmp(all->name, "..") != 0 && (!S_ISLNK(all->st_mode)))
	{
		*tmp = insert_sorted(*tmp, all->name, all->add);
		*directory = insert_sorted(*directory, all->name, all->add);
	}
	else
		*file = insert_sorted(*file, all->name, all->add);
}

void			ft_f_a(t_file *all, t_file **directory,
					t_file **new, char *path)
{
	if (S_ISDIR(all->st_mode) && ft_strcmp(all->name, ".") != 0 &&
		ft_strcmp(all->name, "..") != 0 && (!S_ISLNK(all->st_mode)))
	{
		*directory = insert_sorted(*directory, all->name, path);
		if (new == NULL)
			*new = ft_list_new(all->path, all->name, "nothing");
		else
			*new = ft_list_add(new, all->name, all->path, "nothing");
	}
	else
	{
		if (*new == NULL)
			*new = ft_list_new(all->path, all->name, "nothing");
		else
			*new = ft_list_add(new, all->name, all->path, "nothing");
	}
}

void			ft_n_more(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (file_exist(str[i]) == -1)
			ft_non_exist_file(str[i]);
		i++;
	}
}
