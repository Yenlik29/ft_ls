/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_w.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:34:23 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/01 14:37:51 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_w(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str && *str == ' ' && *str == '\t')
			str++;
		if (*str && *str != ' ' && *str != '\t')
		{
			count++;
			while (*str && *str != ' ' && *str != '\t')
				str++;
		}
	}
	return (count);
}
