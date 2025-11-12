/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 02:00:12 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/12 05:27:43 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_numbers(char **argv)
{
	char	**arg_split;
	int		i;
	int		j;
	int		k;

	i = 1;
	while (argv[i])
	{
		arg_split = ft_split(argv[i++], ' ');
		j = 0;
		while (arg_split[j])
		{
			k = 0;
			if ((arg_split[j][0] == '+' || arg_split[j][0] == '-')
				&& arg_split[j][1] >= '0' && arg_split[j][1] <= '9')
				k++;
			while (arg_split[j][k])
				if (!(arg_split[j][k] >= '0' && arg_split[j][k++] <= '9') ||
					ft_atoi(arg_split[j]) == 2147483648)
					return (free_array(arg_split), write(1, "Error\n", 6), 0);
			j++;
		}
		free_array(arg_split);
	}
	return (1);
}

static void	*num_to_list(t_lst **list, int n)
{
	t_lst	*new_node;
	t_lst	*current;

	new_node = malloc(sizeof(t_lst));
	if (!new_node)
		return (NULL);
	new_node->flag = 0;
	new_node->cont = n;
	new_node->next = NULL;
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	current = *list;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

t_lst	*make_list(char **av)
{
	char	**numbers;
	t_lst	*list;
	int		num;
	int		i;
	int		j;

	i = 1;
	list = NULL;
	while (av[i])
	{
		numbers = ft_split(av[i++], ' ');
		j = 0;
		while (numbers[j])
		{
			num = ft_atoi(numbers[j++]);
			if (!num_to_list(&list, num))
				return (free_array(numbers), free_list(&list), NULL);
		}
		free_array(numbers);
	}
	return (list);
}

t_lst	*index_list(t_lst *list)
{
	t_lst	*new_list;
	t_lst	*current;
	t_lst	*temp;
	int		index;
	int		n;

	temp = list;
	new_list = NULL;
	while (list)
	{
		current = temp;
		index = 0;
		n = list->cont;
		while (current)
		{
			if (current->cont < n)
				index++;
			current = current->next;
		}
		num_to_list(&new_list, index);
		list = list->next;
	}
	return (new_list);
}

int	check_doubles(t_lst *stack)
{
	t_lst	*tmp;

	tmp = NULL;
	while (stack)
	{
		if (stack->next)
			tmp = stack->next;
		while (tmp)
		{
			if (tmp->cont == stack->cont)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}
