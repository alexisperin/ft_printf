/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:58:38 by aperin            #+#    #+#             */
/*   Updated: 2022/10/21 09:06:36 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_put_hexa_prefix(t_config *config)
{
	if (config->conversion == 'x' || config->conversion == 'p')
	{
		write(1, "0x", 2);
		config->len += 2;
	}
	else if (config->conversion == 'X')
	{
		write(1, "0X", 2);
		config->len += 2;
	}
}

void	ft_put_space_or_plus(t_config *config)
{
	if (config->plus)
	{
		write(1, "+", 1);
		config->len++;
	}
	else if (config->space)
	{
		write(1, " ", 1);
		config->len++;
	}
}
