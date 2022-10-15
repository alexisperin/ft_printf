/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:58:38 by aperin            #+#    #+#             */
/*   Updated: 2022/10/15 13:45:01 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_put_hexa_prefix(int to_print, int upper, t_config *config)
{
	if (!to_print)
		return ;
	if (upper)
		write(1, "0X", 2);
	else
		write(1, "0x", 2);
	config->len += 2;
}