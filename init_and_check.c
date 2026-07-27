/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:02:13 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/27 17:15:21 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_options(t_options *options)
{
	options->bench = 0;
	options->simple = 0;
	options->medium = 0;
	options->complex = 0;
	options->adaptive = 0;
}

int	check_flags(int argc, char *argv[], t_options *options)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			if (set_specific_flag(argv[i], options) == -1)
				return (-1);
		}
		else
			break ;
		i++;
	}
	return (i);
}

int	is_flag(char *str)
{
	if (str[0] == '-' && str[1] == '-')
		return (1);
	return (0);
}

int	init_and_check(int argc, char *argv[], t_options *options)
{
	int	i;

	i = 0;
	if (argc < 2)
		return (-1);
	init_options(options);
	i = check_flags(argc, argv, options);
	if (i >= argc)
		return (-1);
	return (i);
}
