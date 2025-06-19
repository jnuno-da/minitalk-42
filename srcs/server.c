/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:29:11 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/06/19 10:50:36 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_buffer	g_data = {NULL, 0, 0};

void	print_blocks(void)
{
	int	i;
	int	bytes;

	i = 0;
	while (i <= g_data.block_index)
	{
		if (i == g_data.block_index)
			bytes = g_data.char_index;
		else
			bytes = BLOCK_SIZE;
		write(1, g_data.blocks[i], bytes);
		free(g_data.blocks[i]);
		i++;
	}
	free(g_data.blocks);
	write(1, "\n", 1);
	g_data.blocks = NULL;
	g_data.block_index = 0;
	g_data.char_index = 0;
}

int	allocate_blocks(void)
{
	if (g_data.blocks == NULL)
	{
		g_data.blocks = malloc(sizeof(char *) * MAX_BLOCKS);
		if (!g_data.blocks)
			return (0);
	}
	if (g_data.block_index >= MAX_BLOCKS)
		return (0);
	g_data.blocks[g_data.block_index] = malloc(BLOCK_SIZE);
	if (!g_data.blocks[g_data.block_index])
		return (0);
	return (1);
}

void	signal_receiver(int sig)
{
	static int	bit = 0;
	static char	c = 0;

	if (g_data.blocks == NULL && !allocate_blocks())
		return ;
	c = c << 1;
	if (sig == SIGUSR1)
		c |= 1;
	bit++;
	if (bit == 8)
	{
		g_data.blocks[g_data.block_index][g_data.char_index] = c;
		g_data.char_index++;
		if (c == '\0')
			print_blocks();
		else if (g_data.block_index >= BLOCK_SIZE)
		{
			g_data.block_index++;
			g_data.char_index = 0;
			if (!allocate_blocks())
				exit(1);
		}
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf ("SERVER PID = %d\n", getpid());
	signal (SIGUSR1, signal_receiver);
	signal (SIGUSR2, signal_receiver);
	while (1)
		pause ();
	return (0);
}
