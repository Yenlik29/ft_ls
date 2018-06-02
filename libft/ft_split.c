/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:41:22 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/01 14:43:55 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(char *str)
{
	char	**tab;
	int		i;
	int		words;

	words = ft_count_words(str);
	tab = (char **)malloc(sizeof(char) * words + 1);
}
