/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:12:10 by dansanc3          #+#    #+#             */
/*   Updated: 2025/07/27 19:33:43 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_init(t_stack_node **a, char **argv)
{
	int	val;

	if (!a || !argv)
		return (false);
	*a = NULL;
	while (*argv)
	{
		if (!validate_number(*argv))
		{
			ft_putstr_fd("Error\n", 2);
			return (false);
		}
		val = ft_atol(*argv);
		if (has_reps(*a, val))
		{
			ft_putstr_fd("Error\n", 2);
			return (false);
		}
		if (!insert_back(a, create_node(val)) && *a != NULL)
			free_stack(*a);
		argv++;
	}
	return (true);
}

void	insert_front(t_stack_node **head, t_stack_node *new_node)
{
	if (head == NULL || new_node == NULL)
		return ;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}

bool	insert_back(t_stack_node **head, t_stack_node *new_node)
{
	t_stack_node	*temp;

	if (head == NULL || new_node == NULL)
		return (false);
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (true);
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
	return (true);
}

void	get_first_and_last(t_stack_node *head,
								t_stack_node **first,
								t_stack_node **last
								)
{
	if (!head)
		return ;
	*first = head;
	while (head->next)
		head = head->next;
	*last = head;
}
