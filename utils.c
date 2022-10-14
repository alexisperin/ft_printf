/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:34:18 by aperin            #+#    #+#             */
/*   Updated: 2022/10/14 12:29:33 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

void	ft_putnbr_base_recursive(long nbr, char *base, int base_len, int *ret)
{
	if (nbr >= base_len)
		ft_putnbr_base_recursive(nbr / base_len, base, base_len, ret);
	write(1, &base[nbr % base_len], 1);
	(*ret)++;
}

int	ft_putnbr_base(long nbr, char *base)
{
	int	base_len;
	int	ret;

	base_len = 0;
	ret = 0;
	while (base[base_len])
		base_len++;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		ret++;
	}
	ft_putnbr_base_recursive(nbr, base, base_len, &ret);
	return (ret);
}
