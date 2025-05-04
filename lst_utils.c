/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:06:05 by manguita          #+#    #+#             */
/*   Updated: 2025/05/04 19:58:23 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_size(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int	f_in(t_list *list, int index)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		if (list->cont == index)
			break ;
		list = list->next;
	}
	if (lst_size(list) / 2 >= i - 1)
		return (i);
	return (i - lst_size(list) - 1);
}

void	free_list(t_list **list)
{
	t_list	*temp;

	while (*list)
	{
		temp = (*list)->next;
		free(*list);
		*list = temp;
	}
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%d\n", list->cont);
		list = list->next;
	}
	printf("\n");
}
