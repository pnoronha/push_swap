/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:01:22 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/18 18:16:18 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dblst	*sorting(t_dblst **stack_a)
{
	
	if (!*stack_a || (*stack_a)->next == NULL)
		return (NULL);
	*stack_a = save_index(*stack_a);
	ft_putstr("teste sorting >> ");
	stack_iter(stack_a);
	return (*stack_a);
}
