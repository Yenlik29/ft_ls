/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 22:51:27 by ybokina           #+#    #+#             */
/*   Updated: 2018/03/19 22:51:38 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (tab[i] != '\0')
	{
		if (f(tab[i]) == 1)
			count++;
		i++;
	}
	return (count);
}
