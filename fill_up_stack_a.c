/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_up_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:53:33 by csouita           #+#    #+#             */
/*   Updated: 2024/07/09 17:56:08 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	filling(long num, t_list **stack_a, char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		num = ft_atoi(strs[i++]);
		if (num == -2147483649)
		{
			ft_putstr_fd("Error\n", 2);
			free_stacks(stack_a);
			free_strs(strs);
			exit(1);
		}
		check_doubles(stack_a, strs, (int)num);
		ft_lstadd_back(stack_a, ft_lstnew((int)num));
	}
	// t_list *temp = *stack_a;
	// while(temp)
	// {
	// 	printf("temp === %d\n" ,temp->content);
	// 	temp = temp->next;
	// }
}

void	fill_up_stack_a(int ac, char **av, t_list **stack_a)
{
	int		i;
	char	*str;
	char	**strs;
	long	num;

	num = 0;
	i = 1;
	str = NULL;
	strs = NULL; 
	while (ac > i)
	{
		check_spaces(av[i], stack_a, strs);
		str = ft_strjoin(str, av[i++]);
	}
	strs = ft_split(str, ' ');
	free(str);
	filling(num, stack_a, strs);
	free_strs(strs);
}
