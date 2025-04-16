#include "push_swap.h"

int	is_sorted(t_list *list)
{
	while (list->next != NULL)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}