/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:33:04 by dansanc3          #+#    #+#             */
/*   Updated: 2025/05/10 13:33:07 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	validate_number(char *input)
{
	int	i;

	i = 0;
	if (input[i] == '+' || input[i] == '-')
	{
		if (!(input[i + 1] >= '0' && input[i + 1] <= '9'))
			return (1);
		i++;
	}
	else if (!(input[i] >= '0' && input[i] <= '9'))
		return (1);
	while (input[i])
	{
		if (input[i] < '0' || input[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
