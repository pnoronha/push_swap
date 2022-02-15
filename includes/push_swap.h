/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:22:57 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/15 00:44:36 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../includes/libft/libft.h"

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

#endif
