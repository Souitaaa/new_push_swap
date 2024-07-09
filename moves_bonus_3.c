/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:38:13 by csouita           #+#    #+#             */
/*   Updated: 2024/07/09 19:38:44 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap_bonus.h"
void	ra(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) > 1)
	{
		rotate(stack_a);
	}
}

void	rb(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) > 1)
	{
		rotate(stack_b);
	}
}

void	sa(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) > 1)
	{
		swap(stack_a);
	}
}
void rrr(t_list **stack_a ,t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

void ss(t_list **stack_a,t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
