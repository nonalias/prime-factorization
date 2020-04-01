/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 20:05:43 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/01 20:44:52 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	validation(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] < '0' || str[count] > '9')
			return (-1);
		count++;
	}
	return (count);
}

int	stoi(char *str, unsigned int *number)
{
	int		size;
	long long 	helper;
	long long	result;

	if ((size = validation(str)) == -1 || size > 10)
	{
		printf("hello\n");
		return (0);
	}
	result = 0;
	helper = 1;
	while (--size >= 0)
	{
		result += (helper * (str[size] - '0'));
		helper = helper * 10;
	}
	if (result > UINT_MAX || result < 2)
		return (0);
	*number = result;
	return (1);
}

int	main(int argc, char *argv[])
{
	unsigned int	number;

	if (argc != 2)
	{
		printf("Input number is WRONG\n");
		return (1);
	}
	if (!stoi(argv[1], &number))
	{
		printf("Input number is out of range\n");
		return (1);
	}
}
