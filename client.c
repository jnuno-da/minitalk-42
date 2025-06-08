/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:29:01 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/06/09 00:40:16 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_deliver(int pid, char *str)
{
	int	bit;

	bit = 0;
	while(bit < 8)
	{
		if (*str & (0b1000000 << bit))
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

int	main (int argc, char **argv)
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
		while(argv[2][i] != '\0')
		{
			if(!ft_isprint)
				return(0);
			i++;
		}
		signal_deliver(ft_atoi(argv[1]), argv[2]);
	}
}