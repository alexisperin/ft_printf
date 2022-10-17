/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:34:18 by aperin            #+#    #+#             */
/*   Updated: 2022/10/16 19:22:39 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putchar(char c, t_config *config)
{
	write(1, &c, 1);
	config->len++;
}

void	ft_putstr(char *str, t_config *config)
{
	int	len;

	if (!str)
		str = "(null)";
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	config->len += len;
}

static void	ft_putnbr_base_rec(long nbr, char *base, int len, t_config *config)
{
	if (nbr >= len)
		ft_putnbr_base_rec(nbr / len, base, len, config);
	write(1, &base[nbr % len], 1);
	config->len++;
}

void	ft_putnbr_base(long nbr, char *base, t_config *config)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		config->len++;
	}
	else if (config->conversion == 'd' || config->conversion == 'i')
		ft_put_space_or_plus(config);
	else if (config->hashtag && nbr != 0)
		ft_put_hexa_prefix(config);
	ft_putnbr_base_rec(nbr, base, len, config);
}

void	ft_putptr(unsigned long ptr, t_config *config)
{
	if (ptr >= 16)
		ft_putptr(ptr / 16, config);
	write(1, &HEXA_LOWER[ptr % 16], 1);
	config->len++;
}
