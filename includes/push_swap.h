/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:22:57 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/16 00:49:21 by pnoronha         ###   ########.fr       */
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
	struct s_dblst	*next;
	struct s_dblst	*prev;
}t_dblst;

typedef struct s_data
{
	t_dblst	*stack_a;
	t_dblst *stack_b;
	char	**values;
	int		number_count;
}t_data;

int		input_error(void);
void	input_parse(t_data *data);
t_dblst	*fill_stack(t_data *data);
void	stack_iter(t_dblst *stack);
t_dblst	*swap(t_dblst *stack);

#endif
