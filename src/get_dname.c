/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dname.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:48:46 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/21 20:12:40 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char		*get_dname(char *p_name, char *c_name)
{
	char	*ret;
	char	*to_be_freed;

	ret = NULL;
	if (*p_name && *c_name)
	{
		if (ft_strcmp(p_name, "/") == 0)
			ret = ft_strjoin(p_name, c_name);
		else
		{
			ret = ft_strjoin(p_name, "/");
			to_be_freed = ret;
			ret = ft_strjoin(ret, c_name);
			free(to_be_freed);
		}
	}
	return (ret);
}
