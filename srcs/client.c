/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:29:01 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/06/11 22:49:22 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_deliver(int pid, char *str)
{
	int	bit;
	int	c;

	bit = 0;
	c = 0;
	while (*str)
	{
		c = *str;
		bit = 0;
		while (bit < 8)
		{
			if ((c >> (7 - bit)) & 1)
				kill (pid, SIGUSR1);
			else
				kill (pid, SIGUSR2);
			bit++;
			usleep(100);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Usage = ./client <PID> \"Message\"\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		while (argv[2][i] != '\0')
		{
			if (!ft_isprint(argv[2][i]))
				return (0);
			i++;
		}
		signal_deliver(ft_atoi(argv[1]), argv[2]);
	}
}
