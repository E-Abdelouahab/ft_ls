/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dname.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:48:46 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/19 22:15:47 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char *get_dname(char *p_name, char *c_name)
{
	if(*p_name && *c_name)
	{
		if (ft_strcmp(p_name, "/") == 0)
			return ft_strjoin(p_name, c_name);
		p_name =ft_strjoin(p_name, "/");
		p_name = ft_strjoin(p_name, c_name);
	}
	return (p_name);
}
