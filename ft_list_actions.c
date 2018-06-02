/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:34:55 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/25 18:14:09 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_file_perm(char *str)
{
	ft_putstr(str);
	ft_putstr(":\n");
	if (ft_access(str) == 0)
		ft_permission_denied(str);
}

t_file		*ft_list_new(char *the_way, char *name, char *add)
{
	t_file			*new;

	if (!(new = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	if (name == NULL)
		new->name = NULL;
	else
	{
		new = ft_new_new(new, name, the_way, add);
		if (new->name == NULL)
			return (NULL);
		ft_memcpy((new->name), name, ft_strlen(name));
	}
	new->next = NULL;
	return (new);
}

t_file		*ft_list_add(t_file **elem, char *str, char *path, char *add)
{
	t_file			*new;
	t_file			*last;

	if (!(new = (t_file *)malloc(sizeof(t_file))))
		exit(EXIT_FAILURE);
	last = *elem;
	if (*elem == NULL)
	{
		*elem = new;
		return (new);
	}
	new = ft_new_new(new, str, path, add);
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	return (*elem);
}

t_elem		*ft_listnew(char *name, char *the_way, t_opt opt)
{
	t_elem			*new;
	struct stat		buf;

	if (!(new = (t_elem *)malloc(sizeof(t_elem))))
		return (NULL);
	if (name[0] == '/' && opt.l == 0)
		stat(the_way, &buf);
	else
		lstat(the_way, &buf);
	new->name = ft_strdup(name);
	new->path = ft_strdup(the_way);
	new->st_mode = buf.st_mode;
	new->date = buf.st_mtime;
	new->st_nlink = buf.st_nlink;
	new->st_uid = buf.st_uid;
	new->st_gid = buf.st_gid;
	new->st_blocks = buf.st_blocks;
	new->st_size = buf.st_size;
	if (new->name == NULL)
		return (NULL);
	ft_memcpy((new->name), name, ft_strlen(name));
	new->next = NULL;
	return (new);
}

t_elem		*ft_listadd(t_elem **elem, char *str, char *path, t_opt opt)
{
	t_elem			*new;
	t_elem			*last;

	if (!(new = (t_elem *)malloc(sizeof(t_elem))))
		exit(EXIT_FAILURE);
	last = *elem;
	if (*elem == NULL)
	{
		*elem = new;
		return (new);
	}
	new = ft_new_el(new, str, path, opt);
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	return (*elem);
}
