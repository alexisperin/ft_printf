/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:42:05 by aperin            #+#    #+#             */
/*   Updated: 2022/10/16 16:08:25 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	n;
	int	*p;

	n = ft_printf("Hello, %c\n", 'A');
	printf("%d\n", n);
	n = ft_printf("Hello, %s\n", "world");
	printf("%d\n", n);
	n = ft_printf("%d\n", -10);
	printf("%d\n", n);
	n = ft_printf("%u\n", -135435435);
	printf("%d\n", n);
	n = ft_printf("%x\n", 10);
	printf("%d\n", n);
	n = ft_printf("%X\n", 10);
	printf("%d\n", n);
	p = &n;
	printf("%p\n", p);
	ft_printf("%p\n", p);
	printf("%p\n", NULL);
	ft_printf("%p\n", NULL);
}
