/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:41:45 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/02 10:27:12 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTER_H
# define COMPUTER_H
# include "libft.h"

typedef struct				s_unknownValues
{
	int						multiplier;
	int						power;
	char					sign;
	struct s_unknownValues	*parent;
	struct s_unknownValues	*right;
	struct s_unknownValues	*left;
}							t_unknownValues;

t_unknownValues				*createUnknownElement();
void						addElement(t_unknownValues *element,
								t_unknownValues **lst);

#endif
