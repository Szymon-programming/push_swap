/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:01:33 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/23 17:25:37 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct s_options
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}	t_options;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total_operations;
}	t_bench;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	float	disorder;
}	t_data;

t_stack	*stack_new(void);
void	stack_push(t_stack *s, int value);
int		stack_pop(t_stack *s);
int		stack_size(const t_stack *s);
int		stack_is_empty(const t_stack *s);
int		stack_peek(const t_stack *s);
int		stack_is_sorted(const t_stack *s);
void	stack_clear(t_stack *s);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// algorytmy
void	radix_sort(t_data *data);
//void	bubble_sort(t_stack *a, t_stack *b);
void	index_stack(t_data *data);
void	selection_sort_with_index(t_data *data);
void	chank_sort(t_data *data);
void	adaptive_sort(t_data *data);

//funkcje parsera
int		init_and_check(int argc, char *argv[], t_options *options);
int		set_specific_flag(char *argv, t_options *options);
int		ft_strcmp(const char *s1, const char *s2);
int		is_flag(char *str);
int		check_flags(int argc, char *argv[], t_options *options);
int		*parser(int argc, char *argv[], int n);
int		*get_parsed_numbers(int argc, char *argv[], int i, int *size);
void	exit_error(void);
int		stack_operations_controller(int *numbers, int size, t_options *options, t_data *data);

//funkcje benchmoda
void	print_bench(t_data *data, t_options *options);
float	compute_disorder(const t_stack *a);
void	do_operation(t_data *data, char *operation);

#endif