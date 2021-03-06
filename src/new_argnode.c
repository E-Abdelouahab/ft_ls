/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_argnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:45:29 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/21 20:35:04 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_args	*new_argnode(char *arg_name)
{
	t_args		*arg;

	if (!(arg = (t_args*)malloc(sizeof(t_args))))
		return (NULL);
	arg->name = ft_strdup(arg_name);
	arg->previous = NULL;
	arg->next = NULL;
	return (arg);
}
