/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ********          #+#    #+#             */
/*   Updated: 2019/06/01 05:20:12 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dup(void const *content, size_t content_size)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;
	void			*new;

	if (!(new = ft_memalloc(content_size)))
		return (NULL);
	ptr = (unsigned char*)content;
	ptr2 = (unsigned char*)new;
	while (*ptr)
		*(ptr2++) = *(ptr++);
	return (new);
}
