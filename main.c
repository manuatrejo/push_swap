/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:36:11 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/12 05:33:57 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	t_lst	*temp;
	int		i;

	i = -1;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	while (argv[++i])
		if (argv[i][0] == '\0' || only_char_str(argv[i], ' '))
			return (write(1, "Error\n", 6), 0);
	if (!valid_numbers(argv))
		return (write(1, "Error\n", 6), 0);
	temp = make_list(argv);
	if (!temp)
		return (1);
	if (!check_doubles(temp))
		return (free_list(&temp), write(1, "Error\n", 6), 0);
	stack_a = index_list(temp);
	free_list(&temp);
	if (!stack_a)
		return (1);
	return (algorithm(&stack_a, &stack_b), free_list(&stack_a), 0);
}
