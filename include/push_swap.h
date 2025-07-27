/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:34:05 by dansanc3          #+#    #+#             */
/*   Updated: 2025/07/27 17:55:15 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}				t_stack_node;

t_stack_node	*create_node(int value);
bool			insert_back(t_stack_node **head, t_stack_node *new_node);
void			insert_front(t_stack_node **head, t_stack_node *new_node);
char			**ft_split2(char *input, char separator);
bool			stack_init(t_stack_node **a, char **argv);
long			ft_atol(char *str);
void			free_stack(t_stack_node *head);
void			free_argv(char **argv);
bool			has_reps(t_stack_node *head, int new_val);
bool			validate_number(char *input);
int				get_stack_size(t_stack_node *head);
void			calculate_chunks(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **b, t_stack_node **a);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			return_to_a(t_stack_node **a, t_stack_node **b);
bool			is_sort(t_stack_node *a);
void			sort_short(t_stack_node **a);
void			sa(t_stack_node **a);
void			rra(t_stack_node **a);
void			ra(t_stack_node **a);
int				find_min_pos(t_stack_node *stack);
bool			is_sort(t_stack_node *a);
void			sb(t_stack_node **b);
void			rrb(t_stack_node **b);
void			assign_final_index(t_stack_node *head);
void			rrb(t_stack_node **b);
void			rra(t_stack_node **a);
void			get_first_and_last(t_stack_node *head,
					t_stack_node **first,
					t_stack_node **last);
void			free_stacks(t_stack_node *a, t_stack_node *b);

#endif
