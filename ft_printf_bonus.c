/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:48:30 by aperin            #+#    #+#             */
/*   Updated: 2022/10/14 17:33:54 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	parse(const char *str, t_config *config);
void	print_config(va_list ap, t_config *config);
int		conversion_type(char c);

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
	config->hashtag = 0;
	config->space = 0;
	config->plus = 0;
	if (!str[config->i])
		return ;
	while (str[config->i] && !conversion_type(str[config->i]))
	{
		if (str[config->i] == '#')
			config->hashtag = 1;
		else if (str[config->i] == ' ')
			config->space = 1;
		else if (str[config->i] == '+')
			config->plus = 1;
		config->i++;
	}
	config->conversion = str[config->i];
	config->i++;
}

int	conversion_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'x' || c == 'X' || c == '%')
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
		ft_put_hexa_prefix(1, 0, config);
		ft_putptr(va_arg(ap, unsigned long), config);
	}
	else if (config->conversion == 'd' || config->conversion == 'i')
		ft_putnbr_base(va_arg(ap, int), DECIMAL, config);
	else if (config->conversion == 'u')
		ft_putnbr_base(va_arg(ap, unsigned), DECIMAL, config);
	else if (config->conversion == 'x')
	{
		ft_put_hexa_prefix(config->hashtag, 0, config);
		ft_putnbr_base(va_arg(ap, unsigned), HEXA_LOWER, config);
	}
	else if (config->conversion == 'X')
	{
		ft_put_hexa_prefix(config->hashtag, 1, config);
		ft_putnbr_base(va_arg(ap, unsigned), HEXA_UPPER, config);
	}
	else if (config->conversion == '%')
		ft_putchar('%', config);
}
