/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasiuda <jasiuda@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 10:45:41 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/20 11:13:06 by jasiuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	swap(t_stack *s)
{
	t_node	*first;
	t_node	*sec;

	if (s->size < 2)
		return ;
	first = s->top;
	sec = s->top->next;
	first->next = sec->next;
	if (sec->next)
		sec->next->prev = first;
	first->prev = sec;
	sec->prev = NULL;
	s->top = sec;
	if (s->size == 2)
		s->bottom = first;
}

void	sa(t_stack *a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
