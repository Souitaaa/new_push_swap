/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:04:13 by csouita           #+#    #+#             */
/*   Updated: 2024/07/09 18:53:07 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	long	res;
	int		i;
	int		sig;

	res = 0;
	i = 0;
	sig = 1;
	while (str[i] == 32 && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sig = -1;
		if (str[i] == '-' || str[i] == '+')
			return (-2147483649);
	}
	while (str[i] == '0')
		i++;
	if ((ft_strlen(&str[i]) > 11))
		return (-2147483649);
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		res = res * 10 + str[i++] - '0';
	if (res * sig > 2147483647 || res * sig < -2147483648)
		return (-2147483649);
	if (str[i] || str[i - 1] == '-' || str[i - 1] == '+')
		return (-2147483649);
	return (sig * res);
}

int	check_spaces(char *av, t_list **stack_a, char **strs)
{
	int	i;

	i = 0;
	while (av[i] == 32)
		i++;
	if (!av[i])
	{
		ft_putstr_fd("Error1\n", 2);
		free_stacks(stack_a);
		free_strs(strs);
		exit(255);
	}
	return (0);
}

void	check_doubles(t_list **stack_a, char **strs, int num)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->content == num)
		{
			free_stacks(stack_a);
			free_strs(strs);
			write(2, "Error\n", 7);
			exit(1);
		}
		tmp = tmp->next;
	}
}

void	is_sorted(t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return ;
		temp = temp->next;
	}
	free_stacks(stack_a);
	exit(0);
}
