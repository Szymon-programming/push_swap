/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:02:13 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/20 14:36:53 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// inicjalizuje flagi do struktury odpowiedzialnej za wywołanie programu
// dobiera, czy program został wywołany z --simple, --bench, etc.
static void	init_options(t_options *options)
{
	options->bench = 0;
	options->simple = 0;
	options->medium = 0;
	options->complex = 0;
	options->adaptive = 0;
}

// sprawdza flagi, wykonuje się dopóki trafia na flagi, jeśli trafi na coś innego zwraca wskażnik na indeks
// na którym konczą się flagi
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

// sprawdza czy dana wartość z argv[i] jest flagą
int	is_flag(char *str)
{
	if (str[0] == '-' && str[1] == '-')
		return (1);
	return (0);
}

// wywołuje go main, jest odpowiedzialny za inicjalizację flag i sprawdzenie co weszło do programu, oraz
// czy to co weszło było prawidłowymi argumentami
int	init_and_check(int argc, char *argv[], t_options *options)
{
	int	i;

	i = 0;
	if (argc < 2)
		return (-1);
	init_options(options);
	i = check_flags(argc, argv, options);
	return (i);
}
