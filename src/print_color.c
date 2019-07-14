/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 20:07:01 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/11 23:48:17 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	print_color(__uint8_t type, mode_t perms)
{
	if (type == DT_DIR)
		printf(BLUE);
	else if (type == DT_CHR)
		printf(YELLOW);
	else if (type == DT_LNK)
		printf(MAGENTA);
	else if (type == DT_SOCK)
		printf(CYAN);
	else if (type == DT_REG)
	{
		if(perms & S_IXUSR)
			printf(RED);
		else
			printf(RESET);
	}
	else if (type == 0)
		printf(RESET);
}
