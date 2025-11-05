/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:01:57 by baderwae          #+#    #+#             */
/*   Updated: 2025/10/25 14:47:12 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_abs_itoa(int n)
{
	char			*str;
	int				tmp;
	unsigned int	size;

	tmp = n;
	size = 1;
	while (tmp < -9 || tmp > 9)
	{
		tmp /= 10;
		size++;
	}
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = 0;
	tmp = n;
	while (size > 0)
	{
		str[size - 1] = ft_abs(tmp % 10) + '0';
		tmp /= 10;
		size--;
	}
	return (str);
}

char	*ft_uitoa_base(unsigned int n, unsigned int base_size, char *base)
{
	char			*str;
	unsigned int	tmp;
	unsigned int	size;

	tmp = n;
	size = 1;
	while (tmp > base_size - 1)
	{
		tmp /= base_size;
		size++;
	}
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = 0;
	tmp = n;
	while (size > 0)
	{
		str[size - 1] = base[ft_abs(tmp % base_size)];
		tmp /= base_size;
		size--;
	}
	return (str);
}

char	*ft_lluitoa_base(
	unsigned long long int n, unsigned int base_size, char *base)
{
	char					*str;
	unsigned long long int	tmp;
	unsigned int			size;

	tmp = n;
	size = 1;
	while (tmp > base_size - 1)
	{
		tmp /= base_size;
		size++;
	}
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = 0;
	tmp = n;
	while (size > 0)
	{
		str[size - 1] = base[ft_abs(tmp % base_size)];
		tmp /= base_size;
		size--;
	}
	return (str);
}

/*char	*ft_ptrtoaddr(void *addr, char *hexas)
{
	char					*str;
	unsigned long long		n_addr;
	unsigned int			i;
	unsigned char			hex;

	str = malloc(sizeof(char) * 13);
	if (!str)
		return (NULL);
	n_addr = (unsigned long long)addr;
	i = 0;
	while (i < 6)
	{
		hex = n_addr >> ((5 - i) * 8) & 0xff;
		str[i * 2] = hexas[hex / 16];
		str[i * 2 + 1] = hexas[hex % 16];
		i++;
	}
	str[i * 2] = 0;
	return (str);
}*/
