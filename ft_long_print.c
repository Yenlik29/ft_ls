/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 09:08:55 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/26 09:08:56 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_c_list(t_file *tmp)
{
	t_file	*n;

	n = tmp;
	while (n != NULL)
	{
		ft_color(n->st_mode);
		ft_putendl(n->name);
		ft_putstr(C_NONE);
		n = n->next;
	}
}

void		print_name(uid_t st_uid)
{
	struct passwd	*pd;

	if ((pd = getpwuid(st_uid)) == NULL)
		perror("getpwuid() error.");
	ft_putstr(pd->pw_name);
	ft_putstr(" ");
}

void		print_grp_name(gid_t st_gid)
{
	struct group	*grp;

	grp = getgrgid(st_gid);
	ft_putstr(grp->gr_name);
	ft_putstr(" ");
}

void		print_links(nlink_t st_nlink)
{
	ft_putnbr(st_nlink);
	ft_putstr(" ");
}

void		print_bytes(off_t st_size)
{
	ft_putnbr(st_size);
	ft_putstr(" ");
}
