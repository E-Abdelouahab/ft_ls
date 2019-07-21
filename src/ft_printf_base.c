/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:19:41 by rnbou             #+#    #+#             */
/*   Updated: 2019/03/06 01:21:23 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_base(t_tags tag, va_list l)
{
	t_u				var;
	char			*base;
	unsigned int	b;

	var.llu = va_arg(l, long long unsigned int);
	base = va_arg(l, char*);
	b = ft_strlen(base);
	if (tag.l_m == 1)
		var.llu = var.lu;
	else if (tag.l_m == 2)
		var.llu = var.hu;
	else if (tag.l_m == 6)
		var.llu = var.hhu;
	else if (tag.l_m == 0)
		var.llu = var.u;
	ft_printf_u1(var, tag, b, base);
}
