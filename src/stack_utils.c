/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:56:05 by dansanc3          #+#    #+#             */
/*   Updated: 2025/05/10 16:24:08 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack_node	*create_node(int value)
{
	t_stack_node	*ret;

	ret = malloc(sizeof(t_stack_node));
	if (!ret)
		return (NULL);
	ret->value = value;
	ret->next = NULL;
	return (ret);
}

