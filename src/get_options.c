/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:46:31 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/14 11:35:30 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int get_options(int argc, char **argv, int *myflags)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (check_valid_opt(argv[i]) == 1)
		{
			if(if_char(argv[i], 'l'))
				*myflags |= FLAG_L;
			if(if_char(argv[i], 'R'))
				*myflags |= FLAG_RCAP;
			if(if_char(argv[i], 'a'))
				*myflags |= FLAG_A;
			if(if_char(argv[i], 'r'))
				*myflags |= FLAG_RLOW;
			if(if_char(argv[i], 't'))
				*myflags |= FLAG_T;
		}
		else if (check_valid_opt(argv[i]) == 2)
			return i;
		i++;
	}
	return i;
}

// i is the index of the first non flag argument.

int check_valid_opt(char *str)
{
	if (str[0] == '-' && strcmp(str, "-") != 0 && strcmp(str, "--") != 0)
		return 1;
	else if (strcmp(str, "--") == 0)
		return 2;
	else
		return 0;
}

int if_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return 1;
		i++;
	}
	return 0;
}
