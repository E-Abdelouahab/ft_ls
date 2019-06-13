/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:48:46 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/12 21:53:52 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_ls.h"

char	*get_name(char *p_name, char *c_name)
{
	char	*result;
	size_t	size;

	p_name = ft_strjoin(p_name, "/");
	if (p_name && c_name)
		size = (size_t)(ft_strlen((char*)p_name) + ft_strlen((char*)c_name));
	else if (p_name)
		size = (size_t)(ft_strlen((char*)p_name));
	else if (c_name)
		size = (size_t)(ft_strlen((char*)c_name));
	else
		return (NULL);
	if (!(result = ft_memalloc(size)))
		return (NULL);
	if (p_name)
		result = ft_strcpy(result, (char*)p_name);
	else
		result = ft_strcpy(result, (char*)c_name);
	if (p_name && c_name)
		result = ft_strcat(result, (char*)c_name);
	return (result);
}
