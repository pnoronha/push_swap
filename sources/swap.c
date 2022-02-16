/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:09:05 by pnoronha          #+#    #+#             */
/*   Updated: 2022/02/16 00:13:10 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dblst	*swap(t_dblst *stack)
{
	t_dblst	*first;
	t_dblst	*second;

	first = (t_dblst *)malloc(sizeof(t_dblst));
	if (!first)
		return (NULL);
	first = stack->next;
	second = stack;
	second->next = first->next;
	first->next = second;
	first->prev = NULL;
	second->prev = first;
	stack = first;
	free(first);
	return (stack);
}
