/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:02:16 by csouita           #+#    #+#             */
/*   Updated: 2024/07/08 19:02:29 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sort(t_list **stack_a, t_list **stack_b, int p)
{
	int	*array;

	array = sort_array(cp_to_array(*stack_a), *stack_a);
	index_of_list(*stack_a, array);
	sort_by_push_ab(stack_a, stack_b, p);
	sort_by_push_ba(stack_a, stack_b);
	free_stacks(stack_a);
	free_stacks(stack_b);
	free(array);
}
