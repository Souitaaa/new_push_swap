/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:06:48 by csouita           #+#    #+#             */
/*   Updated: 2024/07/10 02:44:51 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void is_it_sorted(t_list *stack_a,t_list *stack_b)
{
    t_list *tmp ;
    tmp = stack_a;
    while(tmp && tmp->next)
    {
        if(tmp->content > tmp->next->content)
        {
            ft_putstr_fd("KO\n",2);
            exit(1);
        }
        tmp = tmp->next;
    }
    if(ft_lstsize(stack_a) == 0)
    {
        ft_putstr_fd("KO\n",2);
        exit(1);
    }
    else if(ft_lstsize(stack_b) > 0)
    {
        ft_putstr_fd("KO\n",2);
        exit(1);
    }
    else    
        ft_putstr_fd("OK\n",1);
}

void the_move(char *line, t_list **stack_a, t_list **stack_b)
{
    if(ft_strcmp(line,"sa\n") == 0)
        sa(stack_a);
    else if (ft_strcmp(line,"sb\n") == 0)
        sb(stack_b);
    else if (ft_strcmp(line,"ss\n") == 0)
        ss(stack_a,stack_b);
    else if (ft_strcmp(line,"pa\n") == 0)
        pa(stack_b,stack_a);
    else if (ft_strcmp(line,"pb\n") == 0)
        pb(stack_a,stack_b);
    else if (ft_strcmp(line,"ra\n") == 0)
        ra(stack_a);
    else if (ft_strcmp(line,"rb\n") == 0)
       rb(stack_b);
    else if (ft_strcmp(line,"rr\n") == 0)
        rr(stack_a,stack_b);
    else if (ft_strcmp(line,"rra\n") == 0)
        rra(stack_a);
    else if (ft_strcmp(line,"rrb\n") == 0)
        rrb(stack_b);
    else if (ft_strcmp(line,"rrr\n") == 0)
        rrr(stack_a,stack_b);
    else
        {
            // free_stacks(stack_a);
            // free_stacks(stack_b);
            // free(line);
            ft_putstr_fd("Error\n",1);
            exit(1);
        }
}

void what_move(t_list **stack_a, t_list **stack_b)
{
    char *line ;
    line = get_next_line(0);
    while(line)
    {
        the_move(line,stack_a,stack_b);
        free(line);
        line = get_next_line(0);
    }
}

int main(int ac ,char *av[])
{
    t_list *stack_a;
    t_list *stack_b;
    
    stack_a = NULL;
    stack_b = NULL;
    if (ac == 1)
        exit(0);
    fill_up_stack_a(ac,av,&stack_a);
    what_move(&stack_a,&stack_b);
    is_it_sorted(stack_a,stack_b);
}
