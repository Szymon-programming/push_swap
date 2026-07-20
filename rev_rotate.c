/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:20:07 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/20 14:12:41 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack *s)
{
	t_node	*last;

	if (s->size < 2)
		return ;
	last = s->bottom;
	s->bottom = last->prev;
	s->bottom->next = NULL;
	last->prev = NULL;
	last->next = s->top;
	s->top->prev = last;
	s->top = last;
}

void	rra(t_stack *a)
{
	rev_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b)
{
	rev_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
