/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:44:15 by noprysk           #+#    #+#             */
/*   Updated: 2017/12/18 17:45:25 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <wchar.h>

# define CHECK(x) (x) ? 1 : exit(-1)
# define ABS(x) ((x) >= 0 ? (x) : -(x))

# define FLAG1(x) (x == '#' || x == '0' || x == '-')
# define FLAG(x)  (FLAG1(x) || x == '+' || x == ' ' || x == '*' || x == '.')
# define MODIF(x) (x == 'h' || x == 'l' || x == 'j' || x == 'z')

# define SPEC1(x) (x == 's' || x == 'S' || x == 'p' || x == 'd' || x == 'D')
# define SPEC2(x) (x == 'i' || x == 'o' || x == 'O' || x == 'u' ||x == 'U')
# define SPEC3(x) (x == 'x' || x == 'X' || x == 'c' || x == 'C' || x == 'n')
# define SPEC4(x) (x == 'b' || x == '%')
# define SPECIF(x) ((SPEC1(x)) || (SPEC2(x)) || (SPEC3(x)) || (SPEC4(x)))

# define DIGIT(x) (x >= '0' && x <= '9')

# define D (g_on[S_D].state == ON || g_on[B_D].state == ON)
# define O (g_on[S_O].state == ON || g_on[B_O].state == ON)
# define U (g_on[S_U].state == ON || g_on[B_U].state == ON)
# define X (g_on[S_X].state == ON || g_on[B_X].state == ON)

# define NUMBER ((D) || (O) || (U) || (X) || g_on[I].state == ON)

# define ON 1
# define OFF 0
# define UP 32

# define ZERO 0
# define SHARP 1
# define PLUS 3
# define MINUS 2
# define SPACE 4
# define HH 5
# define H 6
# define L 7
# define LL 8
# define J 9
# define Z 10

# define S_S 11
# define B_S 12
# define P 13
# define S_D 14
# define B_D 15
# define I 16
# define S_O 17
# define B_O 18
# define S_U 19
# define B_U 20
# define S_X 21
# define B_X 22
# define S_C 23
# define B_C 24
# define N 25
# define B 26
# define PER 27
# define DOT 28
# define NB 29

# define NFLAGS 30

# define EOC "\033[0m"

# define BLACK "\e[30m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define MAGENTA "\e[35m"
# define CYAN "\e[36m"
# define WHITE "\e[37m"

# define BBLACK "\e[40"
# define BRED "\e[41m"
# define BGREEN "\e[42m"
# define BYELLOW "\e[43m"
# define BBLUE "\e[44m"
# define BMAGENTA "\e[45m"
# define BCYAN "\e[46m"
# define BWHITE "\e[47m"

# define BOLD "\033[1m"
# define ITAL "\033[3m"
# define UNDER "\033[4m"

typedef struct		s_print
{
	int				len;
	char			*str;
	struct s_print	*next;
}					t_print;

typedef struct		s_flag
{
	const char		*c;
	int				state;
}					t_flag;

va_list				g_lst;

extern t_flag		g_on[];

int					g_nb;
int					g_dot;

int					ft_printf(const char *str, ...);
void				ft_magic(const char *str, t_print **head, int beg, int end);
void				ft_on(const char *str, int beg, int end);

void				ft_s(t_print *node);
char				*ft_mitoa(intmax_t n);
void				ft_i_d(t_print *node);
void				ft_c(t_print *node);

void				ft_unicode(t_print *node, wchar_t a);
void				ft_sunicode(t_print *node, wchar_t *w_str);
int					*ft_array(char *mask);
char				*ft_mask_len(t_print *node, int i);

char				*ft_umitoa(uintmax_t n);
void				ft_u(t_print *node);
void				ft_o(t_print *node);
void				ft_x(t_print *node);
void				ft_p(t_print *node);
void				ft_per(t_print *node);

void				ft_sharp(t_print *node);
void				ft_plus(t_print *node);
void				ft_nb(t_print *node);
void				ft_space(t_print *node);
void				ft_dot(t_print *node);

char				*ft_format(const char *str);
void				ft_n(t_print *head);
void				ft_b(t_print *node);

#endif
