/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 08:11:29 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/25 16:23:50 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*sort_list(t_file *dir, t_file *elem)
{
	if (!dir)
		return (elem);
	if (!elem)
		return (dir);
	if (ft_strcmp(dir->name, elem->name) <= 0)
	{
		dir->next = sort_list(dir->next, elem);
		return (dir);
	}
	else
	{
		elem->next = sort_list(dir, elem->next);
		return (elem);
	}
}

int			compare_names(t_file *a, t_file *b)
{
	return (ft_strcmp(a->name, b->name));
}

t_file		*insert_sorted(t_file *headptr, char *name, char *argv)
{
	t_file		*ptr;
	t_file		*cur;

	argv = ft_strjoin(argv, name);
	ptr = ft_list_new(argv, name, "nothing");
	free(argv);
	if (headptr == NULL || compare_names(ptr, headptr) < 0)
	{
		ptr->next = headptr;
		return (ptr);
	}
	else
	{
		cur = headptr;
		while (cur->next != NULL && compare_names(ptr, cur->next) >= 0)
			cur = cur->next;
		ptr->next = cur->next;
		cur->next = ptr;
		return (headptr);
	}
}

char		**ft_reverse(char **str, int n)
{
	int		i;
	int		j;
	char	*temp;
	char	*temp2;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			temp = ft_strsub(str[i], 0, ft_strlen(str[i]));
			free(str[i]);
			temp2 = ft_strsub(str[j], 0, ft_strlen(str[j]));
			free(str[j]);
			str[i] = temp2;
			str[j] = temp;
			j++;
		}
		i++;
	}
	return (str);
}

char		**ft_sort(char **str, int n)
{
	int		i;
	int		j;
	char	*temp;
	char	*temp2;

	i = 0;
	while (i < n)
	{
		j = i;
		while (j < n)
		{
			if ((ft_strcmp(str[i], str[j])) > 0)
			{
				temp = ft_strsub(str[i], 0, ft_strlen(str[i]));
				free(str[i]);
				temp2 = ft_strsub(str[j], 0, ft_strlen(str[j]));
				free(str[j]);
				str[i] = temp2;
				str[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (str);
}
