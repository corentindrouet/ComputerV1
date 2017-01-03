/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknownsListFunctions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 09:30:19 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/03 09:18:21 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"

t_unknownValues	*create_unknown_element()
{
	t_unknownValues	*unknownElement;

	unknownElement = NULL;
	unknownElement = (t_unknownValues*)malloc(sizeof(t_unknownValues));
	if (unknownElement)
	{
		unknownElement->parent = NULL;
		unknownElement->right = NULL;
		unknownElement->left = NULL;
	}
	return (unknownElement);
}

void		add_element(t_unknownValues *element, t_unknownValues **lst, char side)
{
	t_unknownValues	*tmp;

	tmp = *lst;
	if (!tmp)
		*lst = element;
	else
	{
		element->parent = *lst;
		if (side == 'l')
			tmp->left = element;
		else
			tmp->right = element;
	}
}
