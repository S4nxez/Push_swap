/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:05:24 by dansanc3          #+#    #+#             */
/*   Updated: 2025/07/27 13:15:12 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Count how many rotations are needed to bring a node to the top
 */
int	count_rotations_to_top(t_stack_node *stack, t_stack_node *target)
{
	int	rotations;

	if (!stack || !target)
		return (0);
	rotations = 0;
	while (stack && stack != target)
	{
		stack = stack->next;
		rotations++;
	}
	return (rotations);
}

void	return_to_a_else(t_stack_node **b, int *rotations)
{
	*rotations = get_stack_size(*b) - *rotations;
	while ((*rotations)-- > 0)
		rrb(b);
}

/**
 * Move all elements from stack B back to stack A in ascending order
 */
void	return_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*max_node;
	t_stack_node	*tmp;
	int				rotations;

	while (*b)
	{
		max_node = *b;
		tmp = *b;
		while (tmp)
		{
			if (tmp->value > max_node->value)
				max_node = tmp;
			tmp = tmp->next;
		}
		rotations = count_rotations_to_top(*b, max_node);
		if (rotations <= get_stack_size(*b) / 2)
			while (rotations-- > 0)
				rb(b);
		else
			return_to_a_else(b, &rotations);
		pa(b, a);
	}
}

/**
 * Find the position (0-based) of the minimum value in a stack
 */
int	find_min_pos(t_stack_node *stack)
{
	int				pos;
	int				min_pos;
	int				min_value;
	t_stack_node	*tmp;

	if (!stack)
		return (-1);
	pos = 0;
	min_pos = 0;
	min_value = stack->value;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value < min_value)
		{
			min_value = tmp->value;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_pos);
}

void	assign_final_index(t_stack_node *head)
{
	t_stack_node	*current;
	t_stack_node	*compare;
	int				index;

	current = head;
	while (current)
	{
		index = 0;
		compare = head;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->final_index = index;
		current = current->next;
	}
}
