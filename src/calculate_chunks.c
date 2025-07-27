/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_chunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:13:51 by dansanc3          #+#    #+#             */
/*   Updated: 2025/07/27 01:15:49 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_chunk_count(int size)
{
	if (size <= 100)
		return (5);
	else
		return (11);
}

int	count_chunk_elements(t_stack_node *a, int start, int end)
{
	int	count;

	count = 0;
	while (a)
	{
		if (a->final_index >= start && a->final_index <= end)
			count++;
		a = a->next;
	}
	return (count);
}

void	push_chunk_to_b(t_stack_node **a,
						t_stack_node **b,
						int chunk_start,
						int chunk_end)
{
	int	to_push;

	to_push = count_chunk_elements(*a, chunk_start, chunk_end);
	while (to_push > 0)
	{
		if (*a && (*a)->final_index >= chunk_start
			&& (*a)->final_index <= chunk_end)
		{
			pb(a, b);
			to_push--;
		}
		else
			ra(a);
	}
}

void	k_sort(t_stack_node **a, t_stack_node **b, int size, int chunks_count)
{
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;
	int	i;

	chunk_size = size / chunks_count;
	i = 0;
	while (i < chunks_count)
	{
		chunk_start = i * chunk_size;
		if (i == chunks_count - 1)
			chunk_end = size - 1;
		else
			chunk_end = chunk_start + chunk_size - 1;
		push_chunk_to_b(a, b, chunk_start, chunk_end);
		i++;
	}
}

void	calculate_chunks(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	chunks_count;

	size = get_stack_size(*a);
	if (size <= 5)
	{
		sort_short(a);
		return ;
	}
	assign_final_index(*a);
	chunks_count = get_chunk_count(size);
	k_sort(a, b, size, chunks_count);
	return_to_a(a, b);
}
