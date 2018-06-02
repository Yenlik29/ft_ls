/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 08:09:49 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/26 22:28:57 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_recursion(t_file **begin, t_opt opt)
{
	t_file	*cur;
	t_file	*file;

	cur = *begin;
	file = NULL;
	while (cur)
	{
		if (cur->name && S_ISDIR(cur->st_mode) &&
			ft_strcmp(".", cur->name) && ft_strcmp("..", cur->name))
		{
			if (file == NULL)
				file = ft_list_new(cur->path, cur->name, "nothing");
			else
				file = ft_list_add(&file, cur->name, cur->path, "nothing");
		}
		cur = cur->next;
	}
	ft_putchar('\n');
	ft_go(file, opt);
}

t_file			*surprise_mthf(t_file *all,
					t_file *directory, char *path, t_opt opt)
{
	t_file	*tmp;
	t_file	*file;
	t_file	*new;

	ft_null(&tmp, &new, &file);
	while (all)
	{
		if (opt.a == 0)
		{
			(opt.f == 0) ? ft_none(all, &tmp, &file, &directory) : NULL;
			(opt.f == 1) ? ft_f(all, &directory, &new, path) : NULL;
		}
		else if (opt.a == 1)
		{
			(opt.f == 0) ? ft_none_f(all, &tmp, &directory, &file) : NULL;
			(opt.f == 1) ? ft_f_a(all, &directory, &new, path) : NULL;
		}
		all = all->next;
	}
	ft_meow(opt, &new, &file, &tmp);
	print_name_list(new, opt);
	ft_screw_it(opt, &directory);
	if (new)
		lst_file_del(&new, free_elem);
	return (directory);
}

void			fuck_off(char *str, char *name)
{
	int		rval;

	rval = access(name, F_OK);
	if (rval == 0)
	{
		if (errno == EACCES)
		{
			ft_putstr("ls: ");
			ft_putstr(str);
			ft_putstr(": ");
			ft_putendl(strerror(13));
			return ;
		}
	}
	ft_putstr(strerror(2));
}

void			do_recurse(char *str, char *name, t_opt opt)
{
	DIR			*dir;
	t_file		*directory;
	char		path[1024];
	t_file		*all;
	t_file		*tmp;

	ft_base(name, &tmp, &directory, &all);
	ft_strcpy(path, name);
	ft_strcat(path, "/");
	if ((dir = opendir(name)))
	{
		all = ft_create_f(dir, all, path);
		directory = surprise_mthf(all, directory, path, opt);
		closedir(dir);
		ft_recurse_f(&tmp, directory, opt);
	}
	else
		fuck_off(str, name);
	if (tmp)
		lst_file_del(&tmp, free_elem);
	if (all)
		lst_file_del(&all, free_elem);
}
