/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:22:57 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/15 02:36:08 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS	1
# define FAILURE	0

# include "../includes/libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;

}t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**values;
	int		number_count;
}t_data;

int		input_error(void);
void	input_parse(t_data *data);
t_stack	*fill_stack(t_data *data);
void	stack_iter(t_stack *stack);

#endif
