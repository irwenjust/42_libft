/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:17:19 by likong            #+#    #+#             */
/*   Updated: 2024/04/17 21:17:21 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space_or_not(char c)
{
	return (c == ' ' || c == '\t'
		|| c == '\n' || c == '\r'
		|| c == '\v' || c == '\f');
}

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sig;

	i = 0;
	num = 0;
	sig = 1;
	while (is_space_or_not(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i++] - '0';
		if (num < 0 && sig == 1)
			return (-1);
		if (num < 0 && sig == -1)
			return (0);
	}
	return (sig * num);
}

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	printf("original number: %d\n", atoi("-21474836481111111111"));
	printf("original number: %d\n", ft_atoi("-21474836481111111111"));
	return (0);
}
