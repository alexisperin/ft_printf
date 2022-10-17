/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:48:30 by aperin            #+#    #+#             */
/*   Updated: 2022/10/17 11:08:24 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse(const char *str, t_config *config);
int		is_conversion(char c);
void	print_config(va_list ap, t_config *config);

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
	config->conversion = 0;
	if (is_conversion(str[1]))
	{
		config->conversion = str[1];
		return (2);
	}
	return (1);
}

int	is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	print_config(va_list ap, t_config *config)
{
	if (config->conversion == 'c')
		config->len += ft_putchar(va_arg(ap, int));
	else if (config->conversion == 's')
		config->len += ft_putstr(va_arg(ap, char *));
	else if (config->conversion == 'p')
	{
		write(1, "0x", 2);
		config->len += 2;
		config->len += ft_putptr(va_arg(ap, unsigned long), 0);
	}
	else if (config->conversion == 'd' || config->conversion == 'i')
		config->len += ft_putnbr_base(va_arg(ap, int), DECIMAL);
	else if (config->conversion == 'u')
		config->len += ft_putnbr_base(va_arg(ap, unsigned), DECIMAL);
	else if (config->conversion == 'x')
		config->len += ft_putnbr_base(va_arg(ap, unsigned), HEXA_LOWER);
	else if (config->conversion == 'X')
		config->len += ft_putnbr_base(va_arg(ap, unsigned), HEXA_UPPER);
	else if (config->conversion == '%')
		config->len += ft_putchar('%');
}
