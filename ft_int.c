/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 08:42:26 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/26 22:40:33 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_notc_list(t_file *tmp)
{
	t_file *n;

	n = tmp;
	while (n != NULL)
	{
		ft_putendl(n->name);
		n = n->next;
	}
}

char		**ft_sort_str(char **str, int n, t_opt opt)
{
	(opt.f == 0) ? str = ft_sort(str, n) : NULL;
	(opt.r == 1 && opt.f == 0) ? str = ft_reverse(str, n) : NULL;
	if (opt.t == 1 && opt.d == 0 && opt.f == 0)
		str = ft_time_sort(str, opt);
	return (str);
}

void		ft_color(mode_t st_mode)
{
	S_ISBLK(st_mode) ? ft_putstr(C_RED) : NULL;
	S_ISCHR(st_mode) ? ft_putstr(C_GREEN) : NULL;
	S_ISDIR(st_mode) ? ft_putstr(C_BROWN) : NULL;
	S_ISFIFO(st_mode) ? ft_putstr(C_BLUE) : NULL;
	S_ISREG(st_mode) ? ft_putstr(C_WHITE) : NULL;
	S_ISLNK(st_mode) ? ft_putstr(C_CYAN) : NULL;
	S_ISSOCK(st_mode) ? ft_putstr(C_MAGENTA) : NULL;
}

t_file		*ft_new_new(t_file *new, char *str, char *path, char *add)
{
	struct stat		buf;

	lstat(path, &buf);
	new->name = ft_strdup(str);
	new->path = ft_strdup(path);
	new->st_mode = buf.st_mode;
	new->date = buf.st_mtime;
	new->st_nlink = buf.st_nlink;
	new->st_uid = buf.st_uid;
	new->st_gid = buf.st_gid;
	new->st_blocks = buf.st_blocks;
	new->st_size = buf.st_size;
	new->add = ft_strdup(add);
	new->next = NULL;
	return (new);
}

t_elem		*ft_new_el(t_elem *new, char *str, char *path, t_opt opt)
{
	struct stat		buf;

	if (str[0] == '/' && opt.l == 0)
		stat(path, &buf);
	else
		lstat(path, &buf);
	new->name = ft_strdup(str);
	new->path = ft_strdup(path);
	new->st_mode = buf.st_mode;
	new->date = buf.st_mtime;
	new->st_nlink = buf.st_nlink;
	new->st_uid = buf.st_uid;
	new->st_gid = buf.st_gid;
	new->st_blocks = buf.st_blocks;
	new->st_size = buf.st_size;
	new->next = NULL;
	return (new);
}
