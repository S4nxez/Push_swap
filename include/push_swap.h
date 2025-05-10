/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:34:05 by dansanc3          #+#    #+#             */
/*   Updated: 2025/05/10 01:48:29 by dansanc3         ###   ########.fr       */
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
    int                 value;
    int                 current_position;
    int                 final_index;
    int                 push_price;
    bool                above_median;
    bool                cheapest;
    struct s_stack_node *target_node;
    struct s_stack_node *prev;
    struct s_stack_node *next;
}                   t_stack_node;


#endif