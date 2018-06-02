/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:37:18 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/25 20:59:12 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				file_exist(char *filename)
{
	struct stat buffer;

	return (stat(filename, &buffer));
}

int				ft_file_or_dir(char *str, t_opt opt)
{
	struct stat		buf;
	int				flag;

	flag = 0;
	if (opt.l == 1)
		lstat(str, &buf);
	else
		stat(str, &buf);
	flag = (S_ISDIR(buf.st_mode)) ? 1 : 0;
	return (flag);
}

t_opt			ft_check_opt(char **str, t_opt opt, int i, int j)
{
	opt.d = (str[i][j] == 'd') ? 1 : opt.d;
	opt.l = (str[i][j] == 'l') ? 1 : opt.l;
	opt.big_r = (str[i][j] == 'R') ? 1 : opt.big_r;
	opt.r = (str[i][j] == 'r') ? 1 : opt.r;
	opt.a = (str[i][j] == 'a') ? 1 : opt.a;
	opt.t = (str[i][j] == 't') ? 1 : opt.t;
	opt.g = (str[i][j] == 'g') ? 1 : opt.g;
	opt.u = (str[i][j] == 'u') ? 1 : opt.u;
	opt.f = (str[i][j] == 'f') ? 1 : opt.f;
	opt.big_g = (str[i][j] == 'G') ? 1 : opt.big_g;
	opt.one = (str[i][j] == '1') ? 1 : opt.one;
	if ((str[i][j] != 'l' && str[i][j] != 'G' && str[i][j] != 'R' &&
		str[i][j] != 'r' && str[i][j] != 'a' && str[i][j] != 't' &&
		str[i][j] != 'd' &&
		str[i][j] != 'f' && str[i][j] != '1') || (str[1][0] == '-' &&
		str[1][1] == '-' && str[1][2]))
	{
		ft_illegal_err(str[i][j]);
		exit(EXIT_FAILURE);
	}
	return (opt);
}

t_opt			ft_check(char **str, t_opt opt, int argc)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		if ((str[1][0] == '-' && str[1][1] != '-' && str[i][j]) ||
			(str[1][0] == '-' && str[1][1] == '-' && str[1][2] == '\0'))
		{
			while (str[i][0] == '-' && str[i][1] != '-' && str[i][j])
			{
				opt = ft_check_opt(str, opt, i, j);
				j++;
			}
		}
		i++;
	}
	return (opt);
}

void			go_check(t_opt opt, char **str, int n)
{
	t_elem		*elem;
	int			i;

	elem = NULL;
	if (n > 1)
		str = ft_sort_str(str, n, opt);
	if (n == 1)
		ft_one_only(str[0]);
	(n > 1) ? ft_n_more(str) : NULL;
	i = 0;
	while (str[i])
	{
		elem = ft_creation_elem(str, i, elem, opt);
		(opt.t == 1 && opt.d == 0 && opt.f == 0) ?
		elem = ft_opt_t_elem(&elem, opt) : NULL;
		i++;
	}
	print_name_file(elem, opt);
	(elem != NULL) ? ft_putchar('\n') : NULL;
	lst_el_del(&elem, free_elem_el);
	ft_creation_file(str, opt, n);
}
