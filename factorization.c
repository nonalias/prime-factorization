/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 20:05:43 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/01 20:17:45 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	stoi(char *str, int *number)
{
	int		size;
	int		helper;
	long long	result;

	size = 0;
	while (str[size])
		size++;
	result = 0;
	helper = 1;
	while (--size >= 0)
	{
		result += (helper * (str[size] - '0'));
		helper = helper * 10;
	}
	if (result > INT_MAX || result < 2)
		return (0);
	*number = result;
	return (1);
}

int	main(int argc, char *argv[])
{
	int	number;

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
