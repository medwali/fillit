/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:12:01 by oelazzou          #+#    #+#             */
/*   Updated: 2019/05/28 12:50:59 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

int				ft_sqrt(int n);
char			*read_file(int fd);
void			is_invalid_char(char c);
int				count_tetri(char *arr);
void			check_tetri_count(int tetri_count);
void			check_tags_pos(char *arr);
void			check_tags_count(char *arr);
void			check_all(char *arr);
void			exit_error(void);
typedef struct	s_tetrimino
{
	char		c;
	int			width;
	int			height;
	int			is_on_map;
	int			dx;
	int			dy;
	int			x[4];
	int			y[4];
}				t_tetrimino;
t_tetrimino		*get_pos(char *arr, char c);
char			*initialize_map(int size_map);
void			set_tetri(char **map, t_tetrimino **tetri, int map_size);
void			draw_solution(t_tetrimino *tetrimino, int square_size
					, int tetrim_count);
t_tetrimino		*parse_tetriminos(char *tetrimns_buff, int count);
void			calc_width_height(t_tetrimino *tetrimino);
void			parse_tags_coordinates(t_tetrimino *tetrimino, char *buff);
void			remove_top_left_padding(t_tetrimino *tetrimino);
int				ft_sqrt_ciel(int area);
int				solve_puzzle(t_tetrimino *tetrimns_array
					, int tetrimns_count);
#endif
