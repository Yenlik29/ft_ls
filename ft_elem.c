/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:48:09 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/25 17:00:05 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			compare_names_elem(t_elem *a, t_elem *b)
{
	return (ft_strcmp(a->name, b->name));
}

int			cpm_time_elem(t_elem *elem1, t_elem *elem2)
{
	return (elem1->date - elem2->date);
}

void		ft_elem_cpy_elem(t_elem **dest, t_elem *source)
{
	(*dest)->name = source->name;
	(*dest)->path = source->path;
	(*dest)->date = source->date;
	(*dest)->st_mode = source->st_mode;
}

void		swap_elem_elem(t_elem **a, t_elem **b)
{
	t_elem	tmp;

	tmp = **a;
	ft_elem_cpy_elem(a, *b);
	ft_elem_cpy_elem(b, &tmp);
}

t_elem		*ft_opt_t_elem(t_elem **headptr, t_opt opt)
{
	t_elem	*a;
	t_elem	*b;

	a = *headptr;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (cpm_time_elem(a, b) < 0)
				swap_elem_elem(&a, &b);
			else if (cpm_time_elem(a, b) == 0)
			{
				if (compare_names_elem(a, b) >= 0)
					swap_elem_elem(&a, &b);
			}
			b = b->next;
		}
		a = a->next;
	}
	(opt.r == 1) ? ft_opt_r_elem(headptr, opt) : NULL;
	return (*headptr);
}
