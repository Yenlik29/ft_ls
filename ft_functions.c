/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 07:38:25 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/26 07:38:26 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem			*ft_creation_elem(char **str, int i, t_elem *elem, t_opt opt)
{
	char		*path;
	int			is_f;

	is_f = 0;
	path = NULL;
	path = ft_path_el(path, str[i]);
	is_f = ft_file_or_dir(str[i], opt);
	if (is_f == 0 && file_exist(str[i]) != -1 && ft_access(str[i]) == 1)
	{
		if (elem == NULL)
			elem = ft_listnew(str[i], path, opt);
		else
			elem = ft_listadd(&elem, str[i], path, opt);
	}
	free(path);
	return (elem);
}

int				ft_count_j(char *str)
{
	int		j;

	j = 0;
	while (str[j])
		j++;
	return (j);
}

char			*ft_path(char **str, int i)
{
	char	*path;

	if (ft_strcmp(&str[i][0], "/"))
		path = ft_strjoin(str[i], "/");
	else
		path = ft_strdup(str[i]);
	return (path);
}

t_file			*ft_file_manipulate(t_file *begin, char **str, int i, t_opt opt)
{
	char	*path;

	path = NULL;
	path = ft_path(str, i);
	if (opt.d == 1)
	{
		begin = ft_opt_d(begin, path, str[i], opt);
		opt.big_r = 0;
	}
	if (opt.f == 1 && opt.d == 0)
		begin = ft_opt_f(begin, path);
	if (opt.d == 0 && opt.f == 0)
		begin = ft_opt_a(begin, opt, path);
	if (opt.f == 0 && opt.d == 0 && opt.t == 1)
		ft_opt_t_dir(&begin);
	if (opt.f == 0 && opt.r == 1 && opt.d == 0)
		begin = ft_opt_r_dir(&begin, opt);
	free(path);
	return (begin);
}

void			ft_creation_file(char **str, t_opt opt, int n)
{
	t_file	*begin;
	int		is_f;
	int		i;

	i = 0;
	while (str[i])
	{
		begin = NULL;
		is_f = ft_file_or_dir(str[i], opt);
		if (n > 1 && is_f == 1 && i != n - 1 && !file_exist(str[i - 1]))
			ft_putchar('\n');
		if ((n >= 2) && (opt.d == 0) && is_f == 1)
			ft_file_perm(str[i]);
		if (is_f == 1 && ft_access(str[i]) != 0)
		{
			begin = ft_file_manipulate(begin, str, i, opt);
			print_name_list(begin, opt);
			(opt.big_r == 1 && opt.d == 0) ? ft_recursion(&begin, opt) : NULL;
			lst_file_del(&begin, free_elem);
		}
		i++;
	}
}
