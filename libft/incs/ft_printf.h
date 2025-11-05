/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:17:26 by baderwae          #+#    #+#             */
/*   Updated: 2025/11/04 17:53:05 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_wildcard
{
	char	*flags;
	char	type;
	int		width;
	int		precision;
	int		is_null_char;
}	t_wildcard;

int			ft_printf(const char *str, ...);

int			ft_c_in_str(char c, char *str);
char		*ft_get_flags(const char **str);
int			ft_get_number(const char **str);

void		ft_init_wildcard(t_wildcard *wild);
void		ft_free_wildcard(t_wildcard *wild);
t_wildcard	*ft_get_next_wildcard(const char **str);
char		*ft_exec_wildcard(va_list *args, t_wildcard *wild);

char		*ft_get_int(int n, t_wildcard *wild);
char		*ft_get_uint(unsigned int n, t_wildcard *wild);
char		*ft_get_uchar(unsigned char c, t_wildcard *wild);
char		*ft_get_str(char *str, t_wildcard *wild);
char		*ft_get_addr(void *addr);

char		*ft_abs_itoa(int n);
char		*ft_uitoa_base(unsigned int n, unsigned int base_size, char *base);
char		*ft_lluitoa_base(
				unsigned long long int n, unsigned int base_size, char *base);
char		*ft_ptrtoaddr(void *addr, char *hexas);

char		*ft_add_prefix(char *str, char *prefix);
char		*ft_prefix_by_c(char *str, char c, size_t n, char type);
char		*ft_suffix_by_c(char *str, char c, size_t n, char type);
char		*ft_add_padding(char *print_value, t_wildcard *wild);

#endif
