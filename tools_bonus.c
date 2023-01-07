/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:04:56 by ybourais          #+#    #+#             */
/*   Updated: 2023/01/06 16:56:37 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
	{
		sign = sign * (-1);
		i++;
	}
	else if (str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

void	ft_putstr(char *s)
{
	size_t	i;
	size_t	l;

	if (!s)
		return ;
	l = ft_strlen(s);
	i = 0;
	while (i < l)
	{
		write(1, &s[i], sizeof(s[i]));
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, sizeof(c));
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		n = n * -1;
		ft_putchar('-');
	}
	if (n >= 0 && n < 10)
	{
		ft_putchar(n + '0');
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
}
