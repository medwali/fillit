/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:00:36 by oelazzou          #+#    #+#             */
/*   Updated: 2019/06/15 22:32:41 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_tetri_count(int tetri_count)
{
	if (!(1 <= tetri_count && tetri_count <= 26))
		exit_error();
}

void	check_tags_count(char *arr)
{
	int newlines;
	int tags;
	int dots;
	int len;

	dots = 0;
	tags = 0;
	len = 0;
	newlines = 0;
	if (arr == NULL)
		exit_error();
	while (arr[len] != '\0' && len <= 19)
	{
		if (arr[len] == '#')
			tags++;
		if (arr[len] == '\n' && (len % 5) == 4)
			newlines++;
		if (arr[len] == '.')
			dots++;
		len++;
	}
	if (tags != 4 || newlines != 4 || dots != 12)
		exit_error();
}

void	check_tags_pos(char *arr)
{
	int j;
	int touch;

	j = 0;
	touch = 0;
	while (arr[j])
	{
		if (arr[j] == '#')
		{
			if (j + 1 < 20 && arr[j + 1] == '#')
				touch++;
			if (j - 1 >= 0 && arr[j - 1] == '#')
				touch++;
			if (j - 5 >= 0 && arr[j - 5] == '#')
				touch++;
			if (j + 5 < 20 && arr[j + 5] == '#')
				touch++;
		}
		j++;
	}
	if (touch == 6 || touch == 8)
		return ;
	exit_error();
}

void	check_all(char *arr)
{
	int		add21;
	char	*tmp;

	tmp = NULL;
	check_tetri_count(count_tetri(arr));
	add21 = 0;
	while (add21 == 0 || arr[add21 - 1] == '\n')
	{
		if (!(tmp = ft_strsub(arr, add21, 20)))
			exit_error();
		check_tags_count(tmp);
		check_tags_pos(tmp);
		ft_strdel(&tmp);
		add21 += 21;
	}
	if (arr[add21 - 1] != '\0')
		exit_error();
}
