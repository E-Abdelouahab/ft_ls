/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:31:47 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/15 21:58:43 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS
#include "../libs/libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

// boolean values
#define TRUE		1
#define FALSE		0

// color values
#define ANSI_COLOR_RED		"\x1b[31m"
#define ANSI_COLOR_GREEN	"\x1b[32m"
#define ANSI_COLOR_YELLOW	"\x1b[33m"
#define ANSI_COLOR_BLUE		"\x1b[34m"
#define ANSI_COLOR_MAGENTA	"\x1b[35m"
#define ANSI_COLOR_CYAN		"\x1b[36m"
#define ANSI_COLOR_RESET	"\x1b[0m"

// defining flags values
#define FLAG_L		1
#define FLAG_RCAP	2
#define FLAG_A		4
#define FLAG_RLOW	8
#define FLAG_T		16

// structure where I store data ( AVL BST )
typedef struct		s_node
{
	char	*name;
	char	*path;
	struct s_node	*left;
	struct s_node	*right;
	int		height;
}					t_node;

// functions prototypes 
int			get_options(int argc, char **argv, int *myflags);
int			check_valid_opt(char *str);
int			if_char(char *str, char c);
bool		is_dir(uint8_t type);
t_node		*recur(t_node *tree);
char		*get_dname(char *p_name, char *c_name);

int			get_balance(t_node *node);
int			height(t_node *node);
t_node		*insert_node(t_node *node, char *name, char *path);
t_node		*left_rotate(t_node *x);
t_node		*right_rotate(t_node *y);
int			max(int a, int b);
t_node		*new_node(char *name, char *path);
void		inorder_print(t_node *node);
char		*get_fname(char *f_name);
void		recall(t_node *node) ;
void		inorder_dprint(t_node *node);




#endif
