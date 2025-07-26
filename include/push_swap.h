/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:34:05 by dansanc3          #+#    #+#             */
/*   Updated: 2025/07/26 18:04:19 by dansanc3         ###   ########.fr       */
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
void	print_stack_forward(t_stack_node *head); //TODO PARA TESTEO, ESTO SE DEJA COMENTADO
#endif
