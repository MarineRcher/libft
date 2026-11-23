/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marriche <marriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 15:04:31 by marriche          #+#    #+#             */
/*   Updated: 2026/11/23 17:47:24 by marriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	void	*r;

	temp = lst;
	while (temp->next)
	{
		r = f(temp->content);
		if (r)
		{
			temp->content = r;
		}
		else
		{
			del(temp->content);
			free(temp);
		}
		temp = temp->next;
	}
	return (lst);
}
