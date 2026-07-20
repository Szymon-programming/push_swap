/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasiuda <jasiuda@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:12:27 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/20 10:34:26 by jasiuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_new(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
	return (s);
}

void	stack_push(t_stack *s, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->value = value;
	node->index = 0;
	node->prev = NULL;
	node->next = s->top;
	if (s->top != NULL)
		s->top->prev = node;
	s->top = node;
	if (s->bottom == NULL)
		s->bottom = node;
	s->size++;
}

int	stack_pop(t_stack *s)
{
	t_node	*node;
	int		value;

	node = s->top;
	value = node->value;
	s->top = node->next;
	if (s->top)
		s->top->prev = NULL;
	s->size--;
	free(node);
	return (value);
}
