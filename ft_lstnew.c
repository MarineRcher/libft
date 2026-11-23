/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marriche <marriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:10:08 by marriche          #+#    #+#             */
/*   Updated: 2026/11/16 14:52:24 by marriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_s_list;

	new_s_list = malloc(sizeof(t_list));
	if (new_s_list == NULL)
		return (NULL);
	new_s_list->content = content;
	new_s_list->next = NULL;
	return (new_s_list);
}
