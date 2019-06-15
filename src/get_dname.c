/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:48:46 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/15 13:17:36 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char *get_dname(char *p_name, char *c_name)
{
	p_name =ft_strjoin(p_name, "/");
	c_name = ft_strjoin(p_name, c_name);
	return (c_name);
}
