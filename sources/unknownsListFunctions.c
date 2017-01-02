/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknownsListFunctions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 09:30:19 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/02 10:28:03 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computer.h"

t_unknownValues	*createUnknownElement()
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

void		addElement(t_unknownValues *element, t_unknownValues **lst)
{
	t_unknownValues	*tmp;

	tmp = *lst;
	if (!tmp)
		*lst = element;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = element;
	}
}
