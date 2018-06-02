/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:07:40 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/26 22:38:59 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_null(t_file **tmp, t_file **new, t_file **file)
{
	*tmp = NULL;
	*new = NULL;
	*file = NULL;
}

void			swap_elem_dir(t_file **a, t_file **b)
{
	t_file	tmp;

	tmp = **a;
	ft_elem_cpy_dir(a, *b);
	ft_elem_cpy_dir(b, &tmp);
}

t_file			*ft_opt_t_dir(t_file **headptr)
{
	t_file	*a;
	t_file	*b;

	a = *headptr;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (cpm_time_dir(a, b) < 0)
				swap_elem_dir(&a, &b);
			else if (cpm_time_dir(a, b) == 0)
			{
				if (compare_names(a, b) >= 0)
					swap_elem_dir(&a, &b);
			}
			b = b->next;
		}
		a = a->next;
	}
	return (*headptr);
}

t_file			*ft_opt_a(t_file *begin, t_opt opt, char *path)
{
	DIR				*dir;
	struct dirent	*sd;

	if (!(dir = opendir(path)))
		exit(EXIT_FAILURE);
	while ((sd = readdir(dir)) != NULL)
	{
		if (opt.a == 0 && sd->d_name[0] != '.')
			begin = insert_sorted(begin, sd->d_name, path);
		if (opt.a == 1)
			begin = insert_sorted(begin, sd->d_name, path);
	}
	closedir(dir);
	return (begin);
}

t_file			*ft_opt_r_dir(t_file **begin, t_opt opt)
{
	t_file	*prev;
	t_file	*current;
	t_file	*next;

	prev = NULL;
	next = NULL;
	if (opt.r == 1)
	{
		current = *begin;
		while (current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		*begin = prev;
	}
	return (*begin);
}
