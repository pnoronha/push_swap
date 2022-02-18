/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:22:57 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/18 18:08:06 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS	1
# define FAILURE	0

# include "../includes/libft/libft.h"
# include <stdio.h>

typedef struct s_dblst
{
	int				value;
	int				index;
	struct s_dblst	*next;
	struct s_dblst	*prev;
}t_dblst;

typedef struct s_data
{
	char	**values;
	int		number_count;
}t_data;

int		input_error(void);
void	input_parse(t_data *data);

t_dblst	*fill_stack(t_data *data);
t_dblst	*new_node(int value, t_dblst *prev);
void	stack_iter(t_dblst **stack);
int	list_size(t_dblst *stack);

t_dblst	*sorting(t_dblst **stack_a);
t_dblst	*save_index(t_dblst *stack_a);
t_dblst *insertion_sort(t_dblst *stack_a);

void	push(t_dblst **pusher, t_dblst **receiver);
void	swap(t_dblst **head);
void	rotate(t_dblst **head);
void	reverse_rotate(t_dblst **head);

#endif
