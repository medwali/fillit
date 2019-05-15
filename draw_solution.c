/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 08:52:40 by mel-idri          #+#    #+#             */
/*   Updated: 2019/05/28 12:48:38 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	draw_solution(t_tetrimino *tetrimino, int square_size, int tetrim_count)
{
	char	*result;
	int		i;
	int		j;

	result = ft_strnew(square_size * square_size + square_size);
	ft_memset((void*)result, '.', square_size * square_size + square_size);
	i = 0;
	while (i < square_size)
		result[i++ * (square_size + 1) + square_size] = '\n';
	i = 0;
	while (i < tetrim_count)
	{
		j = 0;
		if (tetrimino[i].is_on_map)
			while (j < 4)
			{
				result[(tetrimino[i].y[j] + tetrimino[i].dy) * (square_size + 1)
						+ tetrimino[i].x[j]
						+ tetrimino[i].dx] = tetrimino[i].c;
				j++;
			}
		i++;
	}
	ft_putstr(result);
}
