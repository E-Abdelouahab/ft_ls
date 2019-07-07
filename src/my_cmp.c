/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:33:53 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/06 12:19:55 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		my_cmp(const char* a, const char* b)
{
	unsigned long	a_;
	unsigned long	b_;

	a_ = (unsigned long)a;
	b_ = (unsigned long)b;
	return (a_ < b_) ? -1 : 1;
}
