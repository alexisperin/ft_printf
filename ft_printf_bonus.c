/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:48:30 by aperin            #+#    #+#             */
/*   Updated: 2022/10/17 09:13:50 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		parse(const char *str, t_config *config);
void	print_config(va_list ap, t_config *config);
int		is_flag(char c);

int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		ap;
	t_config	config;

	i = 0;
	config.len = 0;
	va_start(ap, str);
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			write(1, &str[i], 1);
			config.len++;
			i++;
		}
		if (str[i] == '%')
		{
			i += parse(&str[i], &config);
			print_config(ap, &config);
		}
	}
	va_end(ap);
	return (config.len);
}

int	parse(const char *str, t_config *config)
{
	int	i;

	i = 1;
	config->hashtag = 0;
	config->space = 0;
	config->plus = 0;
	if (!str[i])
		return (i);
	while (is_flag(str[i]))
	{
		if (str[i] == '#')
			config->hashtag = 1;
		else if (str[i] == ' ')
			config->space = 1;
		else if (str[i] == '+')
			config->plus = 1;
		i++;
	}
	config->conversion = str[i];
	i++;
	return (i);
}

int	is_flag(char c)
{
	if (c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

void	print_config(va_list ap, t_config *config)
{
	if (config->conversion == 'c')
		ft_putchar(va_arg(ap, int), config);
	else if (config->conversion == 's')
		ft_putstr(va_arg(ap, char *), config);
	else if (config->conversion == 'p')
	{
		ft_put_hexa_prefix(config);
		ft_putptr(va_arg(ap, unsigned long), config);
	}
	else if (config->conversion == 'd' || config->conversion == 'i')
		ft_putnbr_base(va_arg(ap, int), DECIMAL, config);
	else if (config->conversion == 'u')
		ft_putnbr_base(va_arg(ap, unsigned), DECIMAL, config);
	else if (config->conversion == 'x')
		ft_putnbr_base(va_arg(ap, unsigned), HEXA_LOWER, config);
	else if (config->conversion == 'X')
		ft_putnbr_base(va_arg(ap, unsigned), HEXA_UPPER, config);
	else if (config->conversion == '%')
		ft_putchar('%', config);
}
