/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_puzzle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:31:49 by mel-idri          #+#    #+#             */
/*   Updated: 2019/05/28 12:31:56 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetrimino *g_tetrimns;
static int			g_count;
static int			g_square_size;
static char			**g_map;

void				remove_tetrimino(int index)
{
	int i;

	i = 0;
	while (i < 4)
	{
		g_map[(g_tetrimns[index].y[i] + g_tetrimns[index].dy)]
			[g_tetrimns[index].x[i] + g_tetrimns[index].dx] = 0;
		++i;
	}
	g_tetrimns[index].is_on_map = 0;
}

int					move_tetrimino(int index)
{
	int i;

	remove_tetrimino(index);
	while (g_tetrimns[index].dy + g_tetrimns[index].height <= g_square_size)
	{
		while (++g_tetrimns[index].dx + g_tetrimns[index].width
				<= g_square_size)
		{
			i = 0;
			while (i < 4 && g_map[(g_tetrimns[index].y[i] +
	g_tetrimns[index].dy)][g_tetrimns[index].x[i] + g_tetrimns[index].dx] == 0)
				++i;
			if (--i == 3)
				while (i >= 0 &&
						(g_map[(g_tetrimns[index].y[i] + g_tetrimns[index].dy)]
						[g_tetrimns[index].x[i] + g_tetrimns[index].dx] = 1))
					--i;
			else
				continue ;
			return ((g_tetrimns[index].is_on_map = 1));
		}
		g_tetrimns[index].dx = -1;
		++g_tetrimns[index].dy;
	}
	return (0);
}

int					put_tetrimino(int index)
{
	int i;

	g_tetrimns[index].dy = -1;
	while (++g_tetrimns[index].dy + g_tetrimns[index].height <= g_square_size)
	{
		g_tetrimns[index].dx = -1;
		while (++g_tetrimns[index].dx +
				g_tetrimns[index].width <= g_square_size)
		{
			i = 0;
			while (i < 4 && g_map
					[(g_tetrimns[index].y[i] + g_tetrimns[index].dy)]
					[g_tetrimns[index].x[i] + g_tetrimns[index].dx] == 0)
				++i;
			if (--i == 3)
				while (i >= 0 && (g_map[(g_tetrimns[index].y[i]
					+ g_tetrimns[index].dy)][g_tetrimns[index].x[i]
					+ g_tetrimns[index].dx] = 1))
					--i;
			else
				continue ;
			return ((g_tetrimns[index].is_on_map = 1));
		}
	}
	return (0);
}

int					solve_tetrimino(int index)
{
	int ret;

	if (index == g_count)
		return (1);
	if (put_tetrimino(index) == 0)
		return (0);
	while ((ret = solve_tetrimino(index + 1)) == 0)
		if (move_tetrimino(index) == 0)
			break ;
	return (ret);
}

int					solve_puzzle(t_tetrimino *tetrimns_array
									, int tetrimns_count)
{
	int i;

	g_tetrimns = tetrimns_array;
	g_count = tetrimns_count;
	g_square_size = ft_sqrt_ciel(g_count * 4);
	while (1)
	{
		i = 0;
		g_map = (char **)ft_memalloc(g_square_size * sizeof(char *));
		while (i < g_square_size)
			g_map[i++] = (char *)ft_memalloc(g_square_size);
		if (solve_tetrimino(0) == 1)
			break ;
		i = 0;
		while (i < g_square_size)
			free(g_map[i++]);
		free(g_map);
		++g_square_size;
	}
	return (g_square_size);
}
