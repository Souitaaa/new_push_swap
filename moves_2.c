/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:26:08 by csouita           #+#    #+#             */
/*   Updated: 2024/07/08 17:12:32 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) > 1)
	{
		reverse_rotate(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) > 1)
	{
		reverse_rotate(stack_b);
		ft_putstr_fd("rrb\n", 1);
	}
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;

	if (ft_lstsize(*stack_a))
	{
		tmp_a = *stack_a;
		*stack_a = tmp_a->next;
		ft_lstadd_front(stack_b, tmp_a);
		ft_putstr_fd("pb\n", 1);
	}
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp_b;

	if (ft_lstsize(*stack_b))
	{
		tmp_b = *stack_b;
		*stack_b = tmp_b->next;
		ft_lstadd_front(stack_a, tmp_b);
		ft_putstr_fd("pa\n", 1);
	}
}

void	sb(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) > 1)
	{
		swap(stack_b);
		ft_putstr_fd("sb\n", 1);
	}
}
