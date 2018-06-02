/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:55:18 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/25 16:51:29 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_access(char *str)
{
	DIR		*dir;

	if ((dir = opendir(str)) == NULL)
	{
		if (errno == ENOENT)
			return (1);
		if (errno != ENOTDIR)
			return (0);
	}
	else
		closedir(dir);
	return (1);
}

void		ft_illegal_err(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("usage: ls [-1arRtldfG] [file ...]", 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void		ft_non_exist_file(char *str)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(2), 2);
	ft_putstr_fd("\n", 2);
}

void		ft_permission_denied_once(char *str)
{
	ft_putstr("ls: ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putendl(strerror(13));
}

void		ft_permission_denied(char *str)
{
	ft_putstr("ls: ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putendl(strerror(13));
}
