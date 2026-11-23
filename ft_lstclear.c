/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marriche <marriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:57:09 by marriche          #+#    #+#             */
/*   Updated: 2026/11/20 17:05:25 by marriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (*lst == NULL)
		return ;
	temp = *lst;
	// if ((*lst)->next == NULL)
	// {
	// 	del((*lst)->content);
	// 	free((*lst));
	// 	return ;
	// }
	while ((*lst)->next)
	{
		(*lst) = temp->next;
		del((*lst));
	}
	free(lst);
}
