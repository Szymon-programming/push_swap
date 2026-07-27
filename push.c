/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:23:36 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/27 16:40:23 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *dest, t_stack *src)
{
	t_node	*node;

	if (!src || !src->top)
		return ;
	node = src->top;
	src->top = node->next;
	if (src->top != NULL)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	src->size--;
	node->next = dest->top;
	node->prev = NULL;
	if (dest->top != NULL)
		dest->top->prev = node;
	else
		dest->bottom = node;
	dest->top = node;
	dest->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}
