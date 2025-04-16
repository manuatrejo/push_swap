#include "push_swap.h"

int valid_numbers(char **argv)
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

void num_to_list(t_list **list, int n)
{
	t_list	*new_node;
	t_list	*current;
		
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		exit(1);
	new_node->content = n;
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
	while (av[i])
	{
		numbers = ft_split(av[i++], ' ');
		j = 0;
		while (numbers[j])
		{
			num = ft_atoi(numbers[j++]);//controlar que num esté entre INTMIN-MAX
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
	int		index;
	int		n;

	current = list;
	while (current->next != NULL)
	{
		index = 0;
		n = current->content;
		while (current->next != NULL)
		{
			if (current->content < n)
				index++;
		}
		num_to_list(&new_list, index);
		list = list->next;
	}
	free_list(list);
	return (new_list);
}

int main(char **argv)	
{
	t_list	*stack_a;
	t_list	*stack_b;


	if (!valid_numbers(argv))//manejar argumento vacío también
		exit(0);
	stack_a = make_list(argv);
	index_list(stack_a);
	if (is_sorted(stack_a))
		return (free_list(stack_a), 0);
	algorithm(stack_a, stack_b);
}

