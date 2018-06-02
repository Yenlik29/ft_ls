/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:24:18 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/25 15:18:47 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_one_only(char *str)
{
	if (file_exist(str) == -1)
	{
		ft_non_exist_file(str);
		exit(1);
	}
	else if (ft_access(str) == 0)
		ft_permission_denied(str);
}

void			print_last_mod(time_t date)
{
	time_t		actualtime;
	char		*str1;
	char		*str2;
	char		*tmp;

	actualtime = time(0);
	str1 = ctime(&date);
	if ((actualtime - 15778463) > date || actualtime < date)
	{
		str2 = ft_strsub(str1, 20, 4);
		str1 = ft_strsub(str1, 4, 6);
		tmp = str1;
		str1 = ft_strjoin(str1, "  ");
		free(tmp);
		tmp = str1;
		str1 = ft_strjoin(str1, str2);
		free(tmp);
		free(str2);
	}
	else
		str1 = ft_strsub(str1, 4, 12);
	str1[12] = '\0';
	ft_putstr(str1);
	ft_putchar(' ');
	free(str1);
}

void			print_acl(char *path)
{
	acl_t			acl;
	acl_entry_t		dummy;
	ssize_t			xattr;

	acl = NULL;
	xattr = 0;
	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	if (xattr > 0)
		ft_putstr("@ ");
	else if (acl != NULL)
		ft_putstr("+ ");
	else
		ft_putchar(' ');
	acl_free(acl);
}

void			ft_long(t_file *file, t_opt opt)
{
	t_file *n;

	n = file;
	(opt.d == 0) ? print_total(file) : NULL;
	while (n)
	{
		print_what_is_it(n->st_mode);
		print_permissions(n->st_mode);
		print_acl(n->path);
		print_links(n->st_nlink);
		print_name(n->st_uid);
		print_grp_name(n->st_gid);
		print_bytes(n->st_size);
		print_last_mod(n->date);
		(opt.big_g == 1) ? ft_color(n->st_mode) : NULL;
		ft_putstr(n->name);
		ft_putstr(C_NONE);
		S_ISLNK(n->st_mode) ? ft_print_link(n->path) : NULL;
		ft_putchar('\n');
		n = n->next;
	}
}

void			ft_long_file(t_elem *file, t_opt opt)
{
	t_elem *n;

	n = file;
	while (n)
	{
		print_what_is_it(n->st_mode);
		print_permissions(n->st_mode);
		print_acl(n->path);
		print_links(n->st_nlink);
		print_name(n->st_uid);
		print_grp_name(n->st_gid);
		print_bytes(n->st_size);
		print_last_mod(n->date);
		(opt.big_g == 1) ? ft_color(n->st_mode) : NULL;
		ft_putstr(n->name);
		ft_putstr(C_NONE);
		S_ISLNK(n->st_mode) ? ft_print_link(n->path) : NULL;
		ft_putchar('\n');
		n = n->next;
	}
}
