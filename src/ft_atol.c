/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:04:04 by dansanc3          #+#    #+#             */
/*   Updated: 2025/05/10 15:00:48 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pow(int base, int exp)
{
	int	ret;

	ret = 1;
	while (exp > 0)
	{
		ret *= base;
		exp--;
	}
	return (ret);
}

long	ft_atol(char *str)
{
	long	ret;
	int		size;
	int		is_negative;

	is_negative = 1;
	if (*str == '-')
	{
		str++;
		is_negative = -1;
	}
	ret = 0;
	size = 0;
	while (*str)
	{
		str++;
		size++;
	}
	str -= size;
	while (*str)
	{
		ret += ft_pow(10, size - 1) * (*str - '0');
		str++;
		size--;
	}
	return (ret * is_negative);
}

/**
 * tester ft_atol

int	main(void)
{
	ft_printf("%i\n", ft_atol("2147483647"));
	ft_printf("%i\n", ft_atol("09210"));
	ft_printf("%i\n", ft_atol("-2147483648"));
}
*/
