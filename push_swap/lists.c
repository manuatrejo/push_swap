/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:35:33 by manguita          #+#    #+#             */
/*   Updated: 2024/11/06 16:41:55 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*addnode(t_list *list_head, int n)
{
	t_list	*newnode;
	t_list	*head;
	
	head = list_head;
	newnode = ft_calloc(sizeof(t_list), 1);
	newnode->content = n;
	newnode->next = NULL;
	if (head = NULL)
		return (newnode);
	while (head->next != NULL)
		head = head->next;
	head->next = newnode;
	return (list_head);
}

t_list	make_list(char **string)
{
	char	**str;
	t_list	**head;
	
	head = ft_calloc(sizeof(t_list), 1);
	while (*string)
	{
		str = ft_split(*string, ' ');
		head  = addnode(NULL, ft_atoi(*str++));
		while (*str)
		{
			printf("str: %s\n", *str);
			addnode(*head, ft_atoi(*str++));
		}
		*string++;
	}	
}

int	error_notification(char **string)
{
	char	**str;
	char	*current_char;

	while (*string)
	{
		str = ft_split(*string, ' ');
		while (*str)
		{
			current_char = *str;
			while(*current_char)
			{
				if (*current_char < '0' || *current_char > '9')
				{
					write(1, "Error", 5);
					return (1);
				}
				current_char++;
			}
			str++;
		}
		string++;
	}	
}

int main()
{
	char **arr = malloc(300);
	arr[0] = "cadena1";
	arr[1] = "cadena2";
	make_list(arr);
	return (1);
}