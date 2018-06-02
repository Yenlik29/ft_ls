/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_file_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 00:44:02 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/29 00:44:03 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	lst_file_del(t_file **alst, void (*del)(char *c1, char *c2, char *c3))
{
	t_file *temp;

	if (!alst || !*alst || !del)
		return ;
	while (*alst)
	{
		temp = (*alst)->next;
		del((*alst)->name, (*alst)->path, (*alst)->add);
		free(*alst);
		*alst = temp;
	}
	*alst = NULL;
}

void	ft_go(t_file *file, t_opt opt)
{
	t_file	*runner;

	runner = file;
	while (file)
	{
		if (file->name)
			do_recurse(file->name, file->path, opt);
		file = file->next;
	}
	lst_file_del(&runner, free_elem);
}

void	lst_el_del(t_elem **alst, void (*del)(char *c1, char *c2))
{
	t_elem *temp;

	if (!alst || !*alst || !del)
		return ;
	while (*alst)
	{
		temp = (*alst)->next;
		del((*alst)->name, (*alst)->path);
		free(*alst);
		*alst = temp;
	}
	*alst = NULL;
}

void	lst_file_del_el(t_elem **alst)
{
	t_elem *temp;

	if (!alst || !*alst)
		return ;
	while (*alst)
	{
		temp = (*alst)->next;
		free((*alst)->name);
		free((*alst)->path);
		free(*alst);
		*alst = temp;
	}
	*alst = NULL;
}

void	free_str_arr(char ***str)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		++i;
	}
	free(*str);
	**str = NULL;
}
