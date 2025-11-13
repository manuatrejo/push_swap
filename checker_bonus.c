/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:02:19 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/13 20:54:14 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_instructions(t_lst **stk_a, t_lst **stk_b, char *line)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		push(stk_b, stk_a);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push(stk_a, stk_b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate(stk_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate(stk_b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		(rotate(stk_a), rotate(stk_b));
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		reverse_rotate(stk_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		reverse_rotate(stk_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		(reverse_rotate(stk_a), reverse_rotate(stk_a));
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		swap(stk_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap(stk_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		(swap(stk_a), swap(stk_b));
}

static void	read_instructions(t_lst **stk_a, t_lst **stk_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		execute_instructions(stk_a, stk_b, line);
		free(line);
	}
}

int	main(int ac, char **av)
{
	t_lst	*stk_a;
	t_lst	*stk_b;
	int		i;

	if (ac == 1)
		return (0);
	i = -1;
	while (av[++i])
		if (av[i][0] == '\0' || only_char_str(av[i], ' '))
			return (write(1, "Error\n", 6), 0);
	if (!valid_numbers(av))
		return (0);
	stk_b = make_list(av);
	if (!check_doubles(stk_b))
		return (free_list(&stk_b), write(1, "Error\n", 6), 0);
	stk_a = index_list(stk_b);
	free_list(&stk_b);
	if (!stk_a)
		return (1);
	stk_b = NULL;
	read_instructions(&stk_a, &stk_b);
	if (is_sorted(stk_a) && !stk_b)
		return (free_list(&stk_a), write(1, "OK\n", 3), 0);
	return (write(1, "KO\n", 3), 0);
}
