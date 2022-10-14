/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:48:30 by aperin            #+#    #+#             */
/*   Updated: 2022/10/14 12:45:28 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse(const char *str, t_config *config);
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
			parse(&str[i], &config);
			print_config(ap, &config);
			i += config.i;
		}
	}
	va_end(ap);
	return (config.len);
}

void	parse(const char *str, t_config *config)
{
	config->i = 1;
	if (!str[config->i])
		return ;
	config->conversion = str[config->i];
	config->i++;
}

void	print_config(va_list ap, t_config *config)
{
	if (config->conversion == 'c')
		config->len += ft_putchar(va_arg(ap, int));
	else if (config->conversion == 's')
		config->len += ft_putstr(va_arg(ap, char *));
	else if (config->conversion == 'p')
		return ; // TO DO !!!
	else if (config->conversion == 'd' || config->conversion == 'i')
		config->len += ft_putnbr_base(va_arg(ap, int), DECIMAL);
	else if (config->conversion == 'u')
		config->len += ft_putnbr_base((unsigned) va_arg(ap, int), DECIMAL);
	else if (config->conversion == 'x')
		config->len += ft_putnbr_base(va_arg(ap, int), HEXA_LOWER);
	else if (config->conversion == 'X')
		config->len += ft_putnbr_base(va_arg(ap, int), HEXA_UPPER);
	else if (config->conversion == '%')
		config->len += ft_putchar('%');
}
