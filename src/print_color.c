/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 20:07:01 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/21 20:45:00 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	print_color(__uint8_t type, mode_t perms)
{
	if (type == DT_DIR)
		ft_printf(BLUE);
	else if (type == DT_CHR)
		ft_printf(YELLOW);
	else if (type == DT_LNK)
		ft_printf(MAGENTA);
	else if (type == DT_SOCK)
		ft_printf(CYAN);
	else if (type == DT_REG)
	{
		if (perms & S_IXUSR)
			ft_printf(RED);
		else
			ft_printf(RESET);
	}
	else if (type == 0)
		ft_printf(RESET);
}
