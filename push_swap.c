/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:18:37 by csouita           #+#    #+#             */
/*   Updated: 2024/07/09 17:45:09 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (ac == 1)
		exit(0);
	fill_up_stack_a(ac, av, &stack_a);
	i = ft_lstsize(stack_a);
	if (i == 1)
		(free_stacks(&stack_a)), exit(0);
	is_sorted(&stack_a);
	mini_sort(&stack_a, &stack_b, i);
	return (0);
}
