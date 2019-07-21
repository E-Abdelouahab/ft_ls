/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:41:44 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/21 20:20:03 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"
#include <sys/ioctl.h>

unsigned short	get_width(void)
{
	struct ttysize	ts;

	ioctl(0, TIOCGSIZE, &ts);
	return (ts.ts_cols);
}
