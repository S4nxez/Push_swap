/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:13:51 by dansanc3          #+#    #+#             */
/*   Updated: 2025/07/27 10:03:41 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	//ft_printf("%d, %d, %d\n", first, second, third);
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_four(t_stack_node **a)
{
	t_stack_node	*b = NULL;
	int				min_pos;
	int				i;

	min_pos = find_min_pos(*a);
	i = 0;
	while (i < min_pos)
	{
		ra(a);
		i++;
	}
	pb(a, &b);
	sort_three(a);
	pa(a, &b);
}

void	sort_five(t_stack_node **a)
{
	t_stack_node	*b;
	int				min_pos;

	b = NULL;
	min_pos = find_min_pos(*a);
	while (min_pos--)
		ra(a);
	pb(a, &b);
	min_pos = find_min_pos(*a);
	while (min_pos--)
		ra(a);
	pb(a, &b);
	sort_three(a);
	if (b->value < b->next->value)
		sb(&b);
	pa(a, &b);
	pa(a, &b);
}

void	sort_short(t_stack_node **a)
{
	int	size;

	if (is_sort(*a))
		return ;
	size = get_stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a);
	else if (size == 5)
		sort_five(a);
}
