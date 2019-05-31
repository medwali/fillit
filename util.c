/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:31:25 by mel-idri          #+#    #+#             */
/*   Updated: 2019/05/30 07:30:03 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_sqrt_ciel(int area)
{
	int i;

	i = 0;
	if (area < 0)
		return (0);
	while (i * i < area)
		i++;
	return (i);
}
