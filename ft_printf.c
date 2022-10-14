/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:48:30 by aperin            #+#    #+#             */
/*   Updated: 2022/10/14 09:20:32 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			parse(&str[i], ap, &config);
			print_config(config);
			i += config.i;
		}
	}
	va_end(ap);
	return (config.len);
}

void	parse(char *str, va_list ap, t_config *config)
{
	config->i = 1;

	if (str[config->i] == '%')
		config->conversion = '%';
}
