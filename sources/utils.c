/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 09:22:58 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/03 09:29:13 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"

static int	count_split(char *str, char *c)

static int	is_split_character(char character, char *split_characters)
{
	int	i;

	i = -1;
	while (split_characters[++i])
		if (character == split_characters[i])
			return 1;
	return 0;
}

char	**ft_strcsplit(char *str, char *c)
{
	int	i;

	i = -1;
	while ()
}
