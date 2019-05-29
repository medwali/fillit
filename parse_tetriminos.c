/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:37:37 by mel-idri          #+#    #+#             */
/*   Updated: 2019/05/28 02:09:51 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		remove_top_left_padding(t_tetrimino *tetrimino)
{
	while (tetrimino->x[0] && tetrimino->x[1]
			&& tetrimino->x[2] && tetrimino->x[3])
	{
		tetrimino->x[0]--;
		tetrimino->x[1]--;
		tetrimino->x[2]--;
		tetrimino->x[3]--;
	}
	while (tetrimino->y[0] && tetrimino->y[1]
			&& tetrimino->y[2] && tetrimino->y[3])
	{
		tetrimino->y[0]--;
		tetrimino->y[1]--;
		tetrimino->y[2]--;
		tetrimino->y[3]--;
	}
}

void		parse_tags_coordinates(t_tetrimino *tetrimino, char *buff)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= 19 && j < 4)
	{
		if (buff[i] == '#')
		{
			tetrimino->x[j] = i % 5;
			tetrimino->y[j] = i / 5;
			j++;
		}
		i++;
	}
}

void		calc_width_height(t_tetrimino *tetrimino)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tetrimino->x[i] > tetrimino->width)
			tetrimino->width = tetrimino->x[i];
		if (tetrimino->y[i] > tetrimino->height)
			tetrimino->height = tetrimino->y[i];
		i++;
	}
	tetrimino->width++;
	tetrimino->height++;
}

t_tetrimino	*parse_tetriminos(char *tetrimns_buff, int count)
{
	t_tetrimino	*tetriminos_array;
	int			i;
	char		unique_char;

	if ((tetriminos_array = ft_memalloc(sizeof(t_tetrimino) * count)) == NULL)
		exit_error();
	i = 0;
	unique_char = 'A';
	while (i < count)
	{
		parse_tags_coordinates(tetriminos_array + i, tetrimns_buff);
		remove_top_left_padding(tetriminos_array + i);
		calc_width_height(tetriminos_array + i);
		tetriminos_array[i].c = unique_char++;
		tetrimns_buff += 21;
		i++;
	}
	return (tetriminos_array);
}
