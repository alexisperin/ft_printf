/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:42:05 by aperin            #+#    #+#             */
/*   Updated: 2022/10/20 18:25:51 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf(" -> %d\n", ft_printf("%s %x", "srgrrzgrzg", -25442542));
	printf(" -> %d\n", printf("%s %x", "srgrrzgrzg", -25442542));
	printf((void *)0);
}