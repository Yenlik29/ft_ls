/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 09:05:20 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/26 09:05:21 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_what_is_it(mode_t st_mode)
{
	S_ISBLK(st_mode) ? ft_putstr("b") : NULL;
	S_ISCHR(st_mode) ? ft_putstr("c") : NULL;
	S_ISDIR(st_mode) ? ft_putstr("d") : NULL;
	S_ISFIFO(st_mode) ? ft_putstr("p") : NULL;
	S_ISREG(st_mode) ? ft_putstr("-") : NULL;
	S_ISLNK(st_mode) ? ft_putstr("l") : NULL;
	S_ISSOCK(st_mode) ? ft_putstr("s") : NULL;
}

void		print_permissions(mode_t st_mode)
{
	ft_putchar((st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((st_mode & S_IXOTH) ? 'x' : '-');
}

void		print_total(t_file *file)
{
	t_file			*n;
	int				total;
	struct stat		buf;

	total = 0;
	n = file;
	while (n)
	{
		lstat(n->path, &buf);
		total += buf.st_blocks;
		n = n->next;
	}
	if (file != NULL)
	{
		ft_putstr("total ");
		ft_putnbr(total);
		ft_putchar('\n');
	}
}

char		*ft_join_f(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	if (!(s1 = ft_strjoin(tmp, s2)))
		return (NULL);
	free(tmp);
	return (s1);
}

void		ft_print_link(char *path)
{
	char buf[1024];

	ft_putstr(" -> ");
	if (!(readlink(path, buf, sizeof(buf)) < 0))
		ft_putstr(buf);
}
