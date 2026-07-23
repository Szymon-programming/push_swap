/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:27:25 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/23 15:03:30 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// funkcja sprawdzająca poprawność znaków, gdy mamy poprawne znaki zwraca 0
// w przypadku braku poprawności (argument nie jest liczbą) zwraca -1;
static int	ft_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (-1);
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0') && (str[i] <= '9')))
			return (-1);
		i++;
	}
	return (0);
}

// funkcja odpowiedzialna za przetowrzenie stringa argumentu na int i
// wpisanie go do tablicy, która będzie przechowywać wszystkie liczby,
// które później trafią do stosu A.
static int	ft_atoi_owerflow(const char *str, int *error)
{
	const unsigned char	*n;
	int					sign;
	long long			result;

	n = (const unsigned char *)str;
	sign = 1;
	result = 0;
	while ((*n >= '\t' && *n <= '\r') || (*n == ' '))
		n++;
	if (*n == '-' || *n == '+')
	{
		if (*n == '-')
			sign = -1;
		n++;
	}
	while (*n >= '0' && *n <= '9')
	{
		result *= 10;
		result += *n - '0';
		if (((result * sign) > INT_MAX) || ((result * sign) < INT_MIN))
			return (*error = -1, 0);
		n++;
	}
	return (*error = 0, (int)(result * sign));
}

// sprawdza, czy liczba która wchodzi do tablicy ma już tam swój duplikat
static int	has_duplicate(int number, int *numbers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (numbers[i] == number)
			return (-1);
		i++;
	}
	return (0);
}

// funkcja odpowiedzialna za zażądzanie logiką pobierania liczb,
// argumentów po flagach
int	*parser(int argc, char *argv[], int n)
{
	int	current_number;
	int	i;
	int	j;
	int	*numbers;
	int	error_flag;

	i = n;
	j = 0;
	numbers = malloc(sizeof(int) * (argc - n));
	if (numbers == NULL)
		return (NULL);
	while (i < argc)
	{
		current_number = ft_atoi_owerflow(argv[i], &error_flag);
		if ((ft_is_numeric(argv[i]) == -1) || (error_flag == -1)
			|| (has_duplicate(current_number, numbers, j) == -1))
			break ;
		numbers[j++] = current_number;
		i++;
	}
	if (i < argc)
		return (free(numbers), NULL);
	return (numbers);
}
