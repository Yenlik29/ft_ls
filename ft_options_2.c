/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 09:16:46 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/26 15:52:25 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file			*ft_opt_d(t_file *begin, char *path, char *str, t_opt opt)
{
	if (opt.f == 0)
	{
		if (begin == NULL)
			begin = ft_list_new(path, str, "nothing");
		else
			begin = ft_list_add(&begin, str, path, "nothing");
	}
	else if (opt.f == 1)
		begin = ft_opt_f_with_d(begin, path, str);
	return (begin);
}

t_file			*ft_opt_f_with_d(t_file *begin, char *path, char *str)
{
	if (begin == NULL)
		begin = ft_list_new(path, str, "nothing");
	else
		begin = ft_list_add(&begin, str, path, "nothing");
	return (begin);
}

t_file			*ft_opt_f(t_file *begin, char *path)
{
	DIR				*dir;
	struct dirent	*sd;
	char			*tmp;

	if (!(dir = opendir(path)))
		exit(EXIT_FAILURE);
	while ((sd = readdir(dir)) != NULL)
	{
		tmp = ft_strjoin(path, sd->d_name);
		if (begin == NULL)
			begin = ft_list_new(tmp,
			sd->d_name, "nothing");
		else
			begin = ft_list_add(&begin, sd->d_name,
				tmp, "nothing");
		free(tmp);
	}
	closedir(dir);
	return (begin);
}

int				cpm_time_dir(t_file *elem1, t_file *elem2)
{
	return (elem1->date - elem2->date);
}

void			ft_elem_cpy_dir(t_file **dest, t_file *source)
{
	(*dest)->name = source->name;
	(*dest)->path = source->path;
	(*dest)->st_mode = source->st_mode;
	(*dest)->date = source->date;
	(*dest)->st_nlink = source->st_nlink;
	(*dest)->st_uid = source->st_uid;
	(*dest)->st_gid = source->st_gid;
	(*dest)->st_blocks = source->st_blocks;
	(*dest)->st_size = source->st_size;
	(*dest)->add = source->add;
}
