/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcntlastchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ********          #+#    #+#             */
/*   Updated: 2019/06/01 05:28:45 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strcntlastchar(char *str, const char *charset)
{
	unsigned int	i;
	int				index;
	unsigned int	count;
	unsigned int	tmp;

	count = 0;
	i = (unsigned int)ft_strlen(str) - 1;
	while (str[i])
	{
		index = 0;
		tmp = count;
		while (charset[index])
			if (charset[index++] == str[i])
				++count;
		if (count == tmp)
			return (count);
		--i;
	}
	return (count);
}
