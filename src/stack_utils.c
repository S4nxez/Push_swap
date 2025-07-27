/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:56:05 by dansanc3          #+#    #+#             */
/*   Updated: 2025/07/27 17:59:55 by dansanc3         ###   ########.fr       */
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

/**
 * Checks for repeated values in a stack.
 *
 * @return false if there are no repeated values.
 * @return true if there are repeated values.
 */
bool	has_reps(t_stack_node *head, int new_val)
{
	while (head != NULL)
	{
		if (head->value == new_val)
			return (true);
		head = head->next;
	}
	return (false);
}

int	get_stack_size(t_stack_node *head)
{
	int	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

bool	is_sort(t_stack_node *a)
{
	while (a && a->next)
	{
		if (a->next->value < a->value)
			return (false);
		a = a->next;
	}
	return (true);
}
