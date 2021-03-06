/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:48:57 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/21 21:28:38 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../src/ft_printf.h"
# include "../libs/libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>
# include <pwd.h>
# include <sys/types.h>
# include <grp.h>
# include <time.h>
# include <stdarg.h>

# define TRUE			1
# define FALSE			0

# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define MAGENTA		"\x1b[35m"
# define CYAN			"\x1b[36m"
# define RESET			"\x1b[0m"
# define BOLD_BLUE		"\x1b[96m"

# define FLAGS_STR "lRartSh"

# define FLAG_L			1
# define FLAG_RCAP		2
# define FLAG_A			4
# define FLAG_RLOW		8
# define FLAG_T			16
# define FLAG_SCAP		32
# define FLAG_H			64

# define HIDDEN FALSE

# define UNKNOWN		0
# define DIRECTORY		4
# define CHR			2
# define BLOCK			6
# define REGULAR		8
# define LINK			10
# define SOCKET			12
# define FIFO			1

typedef struct s_info	t_info;

typedef struct			s_args
{
	char				*name;
	time_t				m_time;
	blkcnt_t			size;
	struct s_args		*previous;
	struct s_args		*next;
}						t_args;

typedef struct			s_node
{
	char				*path;
	char				*name;
	dev_t				m_rdev;
	mode_t				perm;
	nlink_t				h_links;
	char				*owner;
	char				*group;
	off_t				size;
	blksize_t			blk_size;
	time_t				m_time;
	int					type;
	struct s_node		*previous;
	struct s_node		*next;
}						t_node;

typedef int				(*t_func)(const char*, const char*);

typedef int				(*t_func2)(t_args**, t_info*, char*);

typedef void			(*t_func3)(t_node*, t_info*);

struct					s_info
{
	unsigned char		print_total;
	char				*name_tbi;
	char				*path_tbi;
	int					max_len;
	int					type_tbi;
	int					flags;
	int					tracker;
	int					list_len;
	int					lines_tbp;
	int					cols_tbp;
	int					ikhan;
	int					counter;
	t_func				insert_func;
	t_func2				insert_arg_func;
	t_func3				print_func;
};

int						check_valid_opt(char *str);
int						if_char(char *str, char c);
bool					is_dir(uint8_t type);
t_node					*new_lnode(t_info *info);
int						insert_lnode(const char *head_, const char *info_);
void					f_print(t_node *head, t_info *info);
void					d_print(t_node *head);
void					insert_beg(t_node **head, t_node *node);
void					recur_all(t_node **head, int tracker);
char					*get_dname(char *p_name, char *c_name);
char					*basename(char *str, char c);
int						get_type(int type);
void					print_color(__uint8_t type, mode_t perms);
int						is_hidden(char *name);
void					read_content(t_node **head, t_info **info,
						int tracker);
void					read_all(t_node **head, t_info **info, int tracker);
void					reccur(t_node *dirs, t_node *copy, int *tracker);
int						get_options(int argc, char **argv, t_info **info);
t_args					fill_args(int ac, char **av);
t_args					*new_argnode(char *arg_name);
int						insert_argnode(t_args **args, t_info *info,
						char *name);
void					init_info(t_info **info);
int						my_cmp(const char *a, const char *b);
void					get_function(t_info **info);
int						insert_argnode_rev(t_args **args, t_info *info,
						char *name);
int						insert_lnode_rev(const char *head_, const char *info_);
void					print_args(t_args *args);
void					normal_fill(t_info **info, struct dirent *dp);
void					usage_error(char c);
int						sort_function(t_node *node, t_node *new_node,
						t_info *info);
int						sort_args_func(t_args *node, t_args *new_node,
						t_info *info);
t_args					*process_args(int ac, char **av, t_info **info);
unsigned short			get_width(void);
void					print_permissions(unsigned short filemode);
void					full_print(t_node *head, t_info *info);
void					handle_error(char *name);
void					get_time(time_t m_time);
void					print_size(off_t size, int perms);
void					full_print_node(t_node *head, t_info *info);
int						get_type2(mode_t st_mode);
void					read_args(t_args **head, t_info **info);
void					read_function(t_node **head, t_info **info);
void					free_nodes(t_node *nodes);
void					free_args(t_args *args);
#endif
