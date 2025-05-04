/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:08:33 by manguita          #+#    #+#             */
/*   Updated: 2025/05/02 04:09:55 by manguita         ###   ########.fr       */
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
			if (arg_split[j][0] == '+' || arg_split[j][0] == '-')
				k++;
			while (arg_split[j][k])
			{
				if (!(arg_split[j][k] >= '0' && arg_split[j][k++] <= '9'))
					return (free_array(arg_split), write(1, "Error\n", 6), 0);
			}
			j++;
		}
		free_array(arg_split);
	}
	return (1);
}

void	num_to_list(t_list **list, int n)
{
	t_list	*new_node;
	t_list	*current;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		exit(1);
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

t_list	*make_list(char **av)
{
	char	**numbers;
	t_list	*list;
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
			num_to_list(&list, num);
		}
		free_array(numbers);
	}
	return (list);
}

t_list	*index_list(t_list *list)
{
	t_list	*new_list;
	t_list	*current;
	t_list	*temp;
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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp;
	int		i;

	i = 0;
	stack_b = NULL;
	if (argc < 2)
		return (write(1, "Error\n", 6), 0);
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (write(1, "Error\n", 6), 0);
		i++;
	}
	if (!valid_numbers(argv))
		exit(0);
	temp = make_list(argv);
	stack_a = index_list(temp);
	free_list(&temp);
	if (is_sorted(stack_a))
		return (free_list(&stack_a), 0);
	algorithm(&stack_a, &stack_b);
	free_list(&stack_a);
}
