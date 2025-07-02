/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:33:04 by dansanc3          #+#    #+#             */
/*   Updated: 2025/06/30 20:16:50 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	validate_number(char *input)
{
	int	i;

	i = 0;
	if (input[i] == '+' || input[i] == '-')
	{
		if (!(input[i + 1] >= '0' && input[i + 1] <= '9'))
			return (false);
		i++;
	}
	else if (!(input[i] >= '0' && input[i] <= '9'))
		return (false);
	while (input[i])
	{
		if (input[i] < '0' || input[i] > '9')
			return (false);
		i++;
	}
	return (true);
}
