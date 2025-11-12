/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 01:09:45 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/11 21:45:19 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	elm_lwr(t_lst *lst, int cont)
{
	while (lst)
	{
		if (lst->cont < cont)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	elm_bgr(t_lst *lst, int cont)
{
	while (lst)
	{
		if (lst->cont > cont)
			return (1);
		lst = lst->next;
	}
	return (0);
}
