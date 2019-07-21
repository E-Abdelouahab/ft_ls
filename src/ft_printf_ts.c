/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:56:19 by rnbou             #+#    #+#             */
/*   Updated: 2019/07/21 01:18:53 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_ts(t_tags tag, va_list l, char *str)
{
	char	**table;
	size_t	len;
	size_t	i;
	size_t	l1;

	tag.c_c = 0;
	table = (char **)va_arg(l, char**);
	len = (size_t)va_arg(l, size_t);
	i = 0;
	l1 = ft_strlen(str);
	str[l1 - 1] = 's';
	while (i < len - 1)
		ft_printf_rep(str, table[i++]);
	ft_printf_rep(str, table[i]);
}
