/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:22:57 by pnoronha          #+#    #+#             */
/*   Updated: 2022/03/01 12:47:08 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS	1
# define FAILURE	0

# include "../includes/libft/libft.h"
# include <stdio.h>

typedef struct s_lst
{
	int				value;
	int				index;
	struct s_lst	*next;
}t_lst;

typedef struct s_data
{
	char	**values;
	int		max;
	int		min;
	int		number_count;
}t_data;

int		input_error(void);
void	input_parse(t_data *data);
void	invert_sorted(t_data *data);

t_lst	*fill_stack(t_data *data);
void	lst_delete(t_lst **lst);
void	stack_iter(t_lst *stack, int flag);
int		list_size(t_lst *stack);

void	sorting(t_lst **stack_a, t_data *data);
t_lst	*save_index(t_lst **stack_a, t_lst *sorted);
t_lst	*insertion_sort(t_lst *stack_a);

void	push(t_lst **pusher, t_lst **receiver);
void	swap(t_lst **head);
void	rotate(t_lst **head);
void	reverse_rotate(t_lst **head);

void	small_sort(t_lst **a, t_lst **b, t_data *data);
void	big_sort(t_lst **a, t_lst **b, t_data *data, int chunks);
int		get_position(t_lst *a, int value);
int		get_moves(t_lst *lst, int lsize);

void	sa(t_lst **a);
void	sb(t_lst **b);
void	ss(t_lst **a, t_lst **b);
void	pa(t_lst **a, t_lst **b);
void	pb(t_lst **b, t_lst **a);
void	ra(t_lst **a);
void	rb(t_lst **b);
void	rr(t_lst **a, t_lst **b);
void	rra(t_lst **a);
void	rrb(t_lst **a);
void	rrr(t_lst **a, t_lst **b);

#endif
