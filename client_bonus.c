/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:51:57 by ybourais          #+#    #+#             */
/*   Updated: 2023/01/07 15:23:32 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	ft_hand(int sig)
{
	if (sig == SIGUSR1)
		write(1, "message rah wssal kaml\n", 23);
}

void	ft_sender(char *p, char *string)
{
	ft_send_signal(p, string);
	ft_send_signal(p, ft_bin('\0'));
	signal(SIGUSR1, ft_hand);
	while (1)
		;
	pause();
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
	k = 0;
	i = 0;
	while ((unsigned char)argv[2][i] != '\0')
	{
		j = 0;
		while (j < 8)
			str[k++] = ft_bin((unsigned char)argv[2][i])[j++];
		i++;
	}
	str[k] = '\0';
	ft_sender(argv[1], str);
	free(str);
	return (0);
}
