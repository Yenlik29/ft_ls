/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:10:50 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/25 20:55:26 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem			*ft_opt_r_elem(t_elem **begin, t_opt opt)
{
	t_elem		*prev;
	t_elem		*current;
	t_elem		*next;

	prev = NULL;
	next = NULL;
	if (opt.r == 1)
	{
		current = *begin;
		while (current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		*begin = prev;
	}
	return (*begin);
}

t_elem			*ft_opt_f_elem(t_elem *begin, char *path, t_opt opt)
{
	DIR				*dir;
	struct dirent	*sd;

	if (!(dir = opendir(path)))
		exit(EXIT_FAILURE);
	ft_strjoin(path, "/");
	while ((sd = readdir(dir)) != NULL)
	{
		if (begin == NULL)
			begin = ft_listnew(ft_strjoin(path, sd->d_name), sd->d_name, opt);
		else
			begin = ft_listadd(&begin, sd->d_name,
				ft_strjoin(path, sd->d_name), opt);
	}
	return (begin);
}

int				ft_len_struct(t_elem **file)
{
	t_elem		*n;
	int			count;

	count = 0;
	n = *file;
	while (n)
	{
		count++;
		n = n->next;
	}
	return (count);
}

char			**ft_reborn(t_elem **file, char **str)
{
	t_elem		*n;
	int			count;
	int			i;

	i = 0;
	count = ft_len_struct(file);
	n = *file;
	while (n)
	{
		str[i] = ft_strdup(n->name);
		i++;
		n = n->next;
	}
	return (str);
}

char			**ft_time_sort(char **str, t_opt opt)
{
	t_elem		*fignya;
	char		*path;
	int			i;

	i = 0;
	fignya = NULL;
	while (str[i])
	{
		path = NULL;
		path = ft_path_path(path, str[i]);
		if (fignya == NULL)
			fignya = ft_listnew(str[i], path, opt);
		else
			fignya = ft_listadd(&fignya, str[i], path, opt);
		free(str[i]);
		free(path);
		i++;
	}
	(opt.t == 1) ? fignya = ft_opt_t_elem(&fignya, opt) : NULL;
	ft_reborn(&fignya, str);
	lst_file_del_el(&fignya);
	return (str);
}
