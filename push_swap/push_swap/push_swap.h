/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:18:07 by manguita          #+#    #+#             */
/*   Updated: 2024/11/06 19:34:55 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "librería/libft.h"
#include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;