/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:38:17 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/02 10:09:46 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"

static void	printUnknownsValues(t_unknownValues *unknowns)
{
	while (unknowns)
	{
		ft_printf("%c %d * X^%d\n", unknowns->sign,
			unknowns->multiplier,
			unknowns->power);
		unknowns = unknowns->next;
	}
}

static void	initUnknownsTab(t_unknownValues **unknowns, char **operationSplit)
{
	int				i;
	t_unknownValues	*tmp;

	i = -1;
	tmp = *unknowns;
	while (operationSplit[++i])
		if ((operationSplit[i][0] == '+'
				|| operationSplit[i][0] == '-'
				|| operationSplit[i][0] == '=')
			&& ft_strlen(operationSplit[i]) == 1)
		{
			tmp->sign = operationSplit[i][0];
		}
		else if (operationSplit[i][0] == '*')
			continue;
		else if (ft_toupper(operationSplit[i][0]) == 'X')
			tmp->power = operationSplit[i][2];
		else
		{
			addElement(createUnknownElement(), &tmp);
			if (tmp->next)
				tmp = tmp->next;
			else
				*unknowns = tmp;
			tmp->multiplier = ft_atoi(operationSplit[i]);
		}
}

int	main(int argc, char **argv)
{
	char			**operationSplit;
	t_unknownValues	*unknowns;

	if (argc != 2)
		return (0);
	unknowns = NULL;
	operationSplit = ft_strsplit(argv[1], ' ');
	initUnknownsTab(&unknowns, operationSplit);
	printUnknownsValues(unknowns);
	return (0);
}
