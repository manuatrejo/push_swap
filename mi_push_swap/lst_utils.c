#include "push_swap.h"

int lst_size(t_list *list)
{
	int	i;

	i = 1;
	if (!list)
		return (0);
	while (list->next != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int	find_index(t_list *list, int index)
{
	int	i;

	i = 0;
	while (list->next != NULL)
	{
		i++;
		if (list->content == index)
			break ;
	}
	if (lst_size(list) / 2 >= i - 1)
		return (i);
	return (i - lst_size(list) - 1);
}

void	free_list(t_list **list)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *list;
	while (temp)
	{
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
	free(list);
}