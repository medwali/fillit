/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:59:40 by oelazzou          #+#    #+#             */
/*   Updated: 2019/05/28 12:35:17 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	int			fd;
	char		*buff;
	int			square_size;
	t_tetrimino	*tetriminos;
	int			count;

	if (ac != 2)
	{
		ft_putendl("usage: fillit tetriminos_file");
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_error();
	buff = read_file(fd);
	check_all(buff);
	count = count_tetri(buff);
	tetriminos = parse_tetriminos(buff, count);
	square_size = solve_puzzle(tetriminos, count);
	draw_solution(tetriminos, square_size, count);
	return (0);
}
