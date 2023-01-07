/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:53:06 by ybourais          #+#    #+#             */
/*   Updated: 2023/01/06 19:32:00 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
char	*ft_bin(int a);
void	ft_send_signal(char *pid, char *s);
int		ft_power(unsigned int a, unsigned int b);
int		bin_ascii(char *str);
void	ft_handler(int sig, siginfo_t *info, void *context);
void	ft_hand(int sig);
void	ft_putchar(char c);
int		ft_print(int i, int k, char *string);
void	ft_sender(char *p, char *string);

#endif
