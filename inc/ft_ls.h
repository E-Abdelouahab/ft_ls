/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:31:47 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/12 22:08:05 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>


#define TRUE		1
#define FALSE		0

#define FLAG_L		1
#define FLAG_RCAP	2
#define FLAG_A		4
#define FLAG_RLOW	8
#define FLAG_T		16


typedef struct		s_node
{
	char	*name;
	struct s_node	*left;
	struct s_node	*right;
	int		height;
}					t_node;


int			get_options(int argc, char **argv, int *myflags);
int			check_valid_opt(char *str);
int			if_char(char *str, char c);
bool		is_dir(uint8_t type);
void		recur(t_node *root, char *str);
char		*get_name(char *p_name, char *c_name);

int			get_balance(t_node *node);
int			height(t_node *node);
t_node		*insert_node(t_node *node, char *name);
t_node		*left_rotate(t_node *x);
t_node		*right_rotate(t_node *y);
int			max(int a, int b);
t_node		*new_node(char *path);


#endif
