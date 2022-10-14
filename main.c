/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:42:05 by aperin            #+#    #+#             */
/*   Updated: 2022/10/14 12:40:49 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	n;

	n = ft_printf("Hello, %c\n", 'A');
	printf("%d\n", n);
	n = ft_printf("Hello, %s\n", "world");
	printf("%d\n", n);
	n = ft_printf("%d\n", -135435435);
	printf("%d\n", n);
	n = ft_printf("%u\n", -135435435);
	printf("%d\n", n);
	n = ft_printf("%x\n", 10);
	printf("%d\n", n);
	n = ft_printf("%X\n", 10);
	printf("%d\n", n);
}
