/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:13:56 by ybourais          #+#    #+#             */
/*   Updated: 2023/01/07 15:23:45 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_bin(int a)
{
	static char	bin[9];
	int			i;

	i = 7;
	while (a != 0 && i >= 0)
	{
		bin[i] = (a % 2) + '0';
		a = a / 2;
		i--;
	}
	bin[8] = '\0';
	while (i >= 0)
	{
		bin[i] = '0';
		i--;
	}
	return (bin);
}

void	ft_send_signal(char *pid, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '0')
			kill(ft_atoi(pid), SIGUSR1);
		else if (s[i] == '1')
			kill(ft_atoi(pid), SIGUSR2);
		usleep(150);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (argc != 3)
		exit(1);
	str = (char *)malloc((ft_strlen(argv[2]) * 8) + 1);
	i = 0;
	k = 0;
	while (argv[2][i] != '\0')
	{
		j = 0;
		while (j < 8)
		{
			str[k] = ft_bin(argv[2][i])[j];
			j++;
			k++;
		}
		i++;
	}
	str[k] = '\0';
	ft_send_signal(argv[1], str);
	return (0);
}
