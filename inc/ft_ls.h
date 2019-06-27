
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:31:47 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/27 15:48:57 by ielmoudn         ###   ########.fr       */
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
#define RED				"\x1b[31m"
#define GREEN			"\x1b[32m"
#define YELLOW			"\x1b[33m"
#define BLUE			"\x1b[34m"
#define MAGENTA			"\x1b[35m"
#define CYAN			"\x1b[36m"
#define RESET			"\x1b[0m"
#define BOLD_BLUE		"\x1b[96m"


// defining flags values
#define FLAG_L		1
#define FLAG_RCAP	2
#define FLAG_A		4
#define FLAG_RLOW	8
#define FLAG_T		16

// flags macros
#define HIDDEN FALSE

//types macros
#define UNKNOWN		0
#define DIRECTORY	4
#define CHR			2
#define BLOCK		6
#define REGULAR		8
#define LINK		10
#define SOCKET		12
#define FIFO		1



//define function type
typedef int (*t_func)(long,long);

// defining a structure to store arguments in a sorted way
typedef struct		s_args
{
	char			*name;
	struct s_args	*previous;
	struct s_args	*next;
}					t_args;

// defining a double linked list to store data
typedef struct		s_node
{
	char			*path;
	char			*name;
	int				type;
	struct s_node	*previous;
	struct s_node	*next;
}					t_node;

// defining filling info structure
typedef struct		s_info
{
	char			*path_tbi;
	char			*name_tbi;
	int				*type_tbi;
	int				flags;
	
}					t_info;



// defining options structure

// functions prototypes 
int			check_valid_opt(char *str);
int			if_char(char *str, char c);
bool		is_dir(uint8_t type);
t_node		*new_lnode(char *path, char *name, int type);
void		insert_lnode(t_node **head, char *path, char *name, int type);
void		f_print(t_node *head);
void		d_print(t_node *head);
void		insert_beg(t_node **head, t_node *node);
void		recur_all(t_node **head, int tracker);
char		*get_dname(char *p_name, char *c_name);
char		*basename(char *str, char c);
int			get_type(__uint8_t type);
void		print_color(__uint8_t type);
int			is_hidden(char *name);
void		read_content(t_node **head, int tracker);
void		read_all(t_node **head, int tracker);
void		process_args(int ac, char **av);
void		reccur(t_node *dirs, t_node *copy, int *tracker);
int			get_options(int argc, char **argv, t_info **info);
t_args		fill_args(int ac, char **av);
t_args		*new_argnode(char *arg_name);









#endif
