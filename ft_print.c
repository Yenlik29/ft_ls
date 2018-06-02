/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:37:08 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/25 18:17:06 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_name_list(t_file *tmp, t_opt opt)
{
	(opt.l == 1) ? ft_long(tmp, opt) : NULL;
	(opt.big_g == 1 && opt.l == 0) ? ft_c_list(tmp) : NULL;
	(opt.big_g == 0 && opt.l == 0) ? ft_notc_list(tmp) : NULL;
}

void		ft_notc_file(t_elem *tmp)
{
	t_elem *n;

	n = tmp;
	while (n != NULL)
	{
		ft_putendl(n->name);
		n = n->next;
	}
}

void		ft_c_file(t_elem *tmp)
{
	t_elem *n;

	n = tmp;
	while (n != NULL)
	{
		ft_color(n->st_mode);
		ft_putendl(n->name);
		ft_putstr(C_NONE);
		n = n->next;
	}
}

void		print_name_file(t_elem *tmp, t_opt opt)
{
	(opt.l == 1) ? ft_long_file(tmp, opt) : NULL;
	(opt.big_g == 1 && opt.l == 0) ? ft_c_file(tmp) : NULL;
	(opt.big_g == 0 && opt.l == 0) ? ft_notc_file(tmp) : NULL;
}

void		print_from_last_list(t_file *n)
{
	if (n == NULL)
		return ;
	print_from_last_list(n->next);
	ft_putstr(n->name);
	ft_putstr("\n");
}
