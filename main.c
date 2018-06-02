/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <ybokina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:45:46 by ybokina           #+#    #+#             */
/*   Updated: 2018/05/26 22:26:58 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_where(char **argv)
{
	int i;
	int flag;
	int final;

	i = 1;
	flag = 0;
	final = 0;
	while (argv[i])
	{
		flag = 0;
		if (argv[i][0] != '-')
		{
			flag = 1;
			final = flag;
		}
		i++;
	}
	return (final);
}

char				**ft_cur_dir(void)
{
	char **str;

	str = (char **)malloc(sizeof(char*) * 1);
	str[0] = ft_strdup(".");
	str[1] = NULL;
	return (str);
}

void				ft_min(t_opt opt, char **str, int n)
{
	go_check(opt, str, n);
	free_str_arr(&str);
}

void				ft_stack(int argc, char **argv, int flag, t_opt opt)
{
	int			i;
	int			j;
	int			n;
	char		**str;

	n = 0;
	str = NULL;
	i = 1;
	j = 0;
	if (flag == 1)
	{
		while (argv[i] && argv[i][0] == '-' && argv[i][1])
			i++;
		while (argv[i++])
			n++;
		str = (char **)malloc(sizeof(char*) * (n + 1));
		str[n] = NULL;
		i = i - n - 1;
		while (argv[i])
			str[j++] = ft_strdup(argv[i++]);
	}
	(argc == 1 || flag == 0) ? str = ft_cur_dir() : NULL;
	if (argc > 1 && argv[1][0] == '-' && argv[1][1])
		opt = ft_check(argv, opt, argc);
	ft_min(opt, str, n);
}

int					main(int argc, char **argv)
{
	t_opt		opt;
	int			flag;

	flag = 0;
	opt = (t_opt){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	flag = ft_where(argv);
	if (argc == 2 && (argv[1][0] == '-' && argv[1][1] == '\0'))
	{
		ft_non_exist_file("-");
		exit(EXIT_FAILURE);
	}
	ft_stack(argc, argv, flag, opt);
	return (0);
}
