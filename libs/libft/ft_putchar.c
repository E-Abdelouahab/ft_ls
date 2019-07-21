/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 23:25:11 by rnbou             #+#    #+#             */
/*   Updated: 2019/03/03 17:19:25 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	static int	*counter;
	int			i;
	char		k;

	k = (char)c;
	if (counter == NULL)
	{
		counter = (int *)malloc(sizeof(int));
		counter[0] = 0;
	}
	if (c != 300)
	{
		counter[0] += 1;
		write(1, &k, 1);
		i = counter[0];
	}
	else
	{
		i = counter[0];
		free(counter);
		counter = NULL;
	}
	return (i);
}
