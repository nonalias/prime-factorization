/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 20:05:43 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/03 00:14:22 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

// str이 숫자로만 이루어져있는지 확인, 반환값은 str의 총 길이
int	validation(char *str)
{
	int		count;

	count = 0;
	while (str[count])
	{
		if (str[count] < '0' || str[count] > '9')
			return (-1);
		count++;
	}
	return (count);
}

// string 을 integer로 바꾸어주는 함수
// 잘못된 숫자형식일 경우 -1반환, 범위오류일경우 0반환
// 정상 변환되면 1 반환
int	stoi(char *str, unsigned int *number)
{
	int		size;
	long long 	helper;
	long long	result;

	// 숫자로만 이루어지지 않을 때
	if ((size = validation(str)) == -1)
		return (-1);
	// 10자리 수가 넘어가면
	if (size > 10)
		return (0);
	// string을 integer로 바꾸어주는 작업
	result = 0;
	helper = 1;
	while (--size >= 0)
	{
		result += (helper * (str[size] - '0'));
		helper = helper * 10;
	}
	// 지시된 범위를 벗어났을 때
	if (result > UINT_MAX || result < 2)
		return (0);
	*number = result;
	return (1);
}

// 제곱근의 근사 값을 구해주는 함수
int	get_near_sqrt(unsigned int number)
{
	unsigned int	output;

	output = 1;
	while (output <= number / output)
		output++;
	return ((int)(output - 1));
}

// 소수 판별 함수, 1이면 소수, 0이면 소수가 아님
int	is_prime(unsigned int number)
{
	int		i;

	i = 2;
	while (i <= get_near_sqrt(number))
	{
		if (number % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	unsigned int	number;
	unsigned int	i;
	int		temp;

	// 입력 인자 갯수 오류 출력
	if (argc != 2)
	{
		printf("The count of inputs is incorrect\n");
		return (1);
	}
	// 오류 코드에 따라 메시지 출력
	if ((temp = stoi(argv[1], &number)) <= 0)
	{
		if (temp == 0)
			printf("Your input number is out of range\n");
		else if (temp == -1)
			printf("Your input number is WRONG\n");
		return (1);
	}
	// 약수이면서 소수이면 출력
	i = 2;
	while (i <= number)
	{
		if (number % i == 0 && is_prime(i))
			printf("%d ", i);
		i++;
	}
	printf("\n");
	return (0);
}
