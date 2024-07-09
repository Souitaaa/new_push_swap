/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:48:42 by csouita           #+#    #+#             */
/*   Updated: 2024/07/07 20:35:39 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minimum(t_list *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	index_of_min(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->content == minimum(stack))
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}

int	max_index(t_list *stack_a, int max)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->content == max)
			break ;
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}
