/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:09:28 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/26 15:52:12 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_base(char *name, t_file **tmp,
				t_file **directory, t_file **all)
{
	*tmp = NULL;
	*directory = NULL;
	*all = NULL;
	print_n(name);
}

void			print_n(char *name)
{
	ft_putchar('\n');
	ft_putstr(name);
	ft_putendl(": ");
}

t_file			*ft_create_f(DIR *dir, t_file *all, char *path)
{
	struct dirent	*entry;
	char			*tmp;

	while ((entry = readdir(dir)) != NULL)
	{
		tmp = ft_strjoin(path, entry->d_name);
		if (all == NULL)
			all = ft_list_new(tmp,
			entry->d_name, path);
		else
			all = ft_list_add(&all, entry->d_name,
				tmp, path);
		free(tmp);
	}
	return (all);
}

t_file			*ft_screw_it(t_opt opt, t_file **directory)
{
	if (opt.f == 0)
	{
		(opt.t == 1) ? ft_opt_t_dir(directory) : NULL;
		(opt.r == 1) ? *directory = ft_opt_r_dir(directory, opt) : NULL;
	}
	return (*directory);
}

void			ft_meow(t_opt opt, t_file **new, t_file **file, t_file **tmp)
{
	(opt.f == 1) ? opt.r = 0 : opt.r;
	if (opt.f == 0)
	{
		*new = sort_list(*tmp, *file);
		(opt.t == 1) ? ft_opt_t_dir(new) : NULL;
		(opt.r == 1) ? *new = ft_opt_r_dir(new, opt) : NULL;
	}
}
