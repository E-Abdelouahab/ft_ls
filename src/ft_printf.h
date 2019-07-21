/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:59:03 by rnbou             #+#    #+#             */
/*   Updated: 2019/07/21 01:18:22 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../libs/libft/libft.h"

typedef struct				s_tags
{
	int						flags;
	int						f_w;
	int						precision;
	int						l_m;
	int						c_c;
}							t_tags;

typedef struct				s_ilist
{
	int						val;
	struct s_ilist			*next;
}							t_ilist;

typedef struct				s_db
{
	size_t					m:52;
	unsigned int			p:11;
	unsigned int			s:1;

}							t_db;

typedef union				u_double
{
	double					f;
	t_db					d;
}							t_double;

typedef struct				s_ld
{
	size_t					m:63;
	unsigned int			q:1;
	unsigned int			p:15;
	unsigned int			s:1;
}							t_ld;

typedef union				u_long_double
{
	long double				l;
	t_ld					ld;

}							t_long_double;

typedef union				u_d
{
	int						d;
	long int				ld;
	long long int			lld;
	short int				hd;
	char					hhd;
}							t_d;

typedef union				u_u
{
	unsigned int			u;
	long unsigned int		lu;
	long long unsigned int	llu;
	short unsigned int		hu;
	unsigned char			hhu;
}							t_u;

typedef void				(*t_f)(t_tags, va_list);

int							number_lenth(t_tags tag,
		long long unsigned int nbr, int b);
void						print_nbr(long long unsigned int nbr,
		char *base, unsigned int b);
int							ft_printf(char *d, ...);
void						ft_printf_rep(char *d, ...);
char						*ft_get_space(int l);
char						*ft_get_zeros(int l);
t_f							ft_get_functions(int i);
int							ft_in(char c, char *str);
void						ft_printf_u1(t_u var, t_tags tag,
		int b, char *base);
void						ft_printf_c(t_tags tag, va_list l);
void						ft_printf_s(t_tags tag, va_list l);
void						ft_printf_p(t_tags tag, va_list l);
void						ft_printf_d(t_tags tag, va_list l);
void						ft_printf_u(t_tags tag, va_list l);
void						ft_printf_f(t_tags tag, va_list l);
void						ft_printf_pr(t_tags tag, va_list l);
t_ilist						*ft_ilistnew(int i);
void						ft_printf_base(t_tags tag, va_list l);
int							ft_in(char c, char *str);
void						ft_sep1(int *i, int *j, char *d);
t_ilist						*ft_sep(char *d, int *i);
char						**getall(char *d, t_ilist *p, int i);
void						ft_del_ilist(t_ilist *ilist);
char						**get_separate(char *d, int *i);
int							ft_in1(char c, char *str);
int							get_flags(char *out, int *j);
int							get_f_w(char *out, int *j);
int							get_precision(char *out, int *j);
int							get_l_m(char *out, int *j);
int							get_c_c(char *out, int *j);
void						get_tags(char **out, t_tags **tags);
void						ft_multiply(size_t **k, int l);
void						ft_cp(size_t *c, size_t **b, int l);
void						bit_shift_right(size_t **t, int shift, int o);
void						bit_shift_left(size_t **t, int l, int o);
void						bit_shift(size_t **t, int shift, int l);
int							ver_carry(size_t *carry, int l);
char						*ft_int(size_t *table_float, int dim, int carry,
		t_tags tag);
size_t						*new_table(int l);
void						ft_printf_td(t_tags tag, va_list l, char *str);
void						ft_printf_ts(t_tags tag, va_list l, char *str);
void						ft_add(size_t **a, size_t **b, int l);
void						ft_add_int(size_t **a, size_t *b, unsigned int l);
void						bit_shift_right(size_t **t, int shift, int o);
void						bit_shift_left(size_t **t, int l, int o);
void						bit_shift(size_t **t, int shift, int l);
size_t						*new_table(int l);
int							regulate_fl(char **part_fl, size_t k,
		int precision);
int							ft_fl(t_tags tag, size_t *table_float,
		char **part_fl, int dim);
void						ft_display_float1(int s, t_tags tag,
		char *part_int, char *part_fl);
void						ft_display_float(t_tags tag,
		size_t *table_float, int dim, int s);
void						ft_put_nan(t_tags tag, int s, size_t m);
#endif
