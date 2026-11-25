/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marriche <marriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 15:04:31 by marriche          #+#    #+#             */
/*   Updated: 2026/11/25 17:49:23 by marriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final;
	t_list	*list;
	void	*content;

	list = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		final = ft_lstnew(content);
		if (!final)
		{
			del(content);
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, final);
		lst = lst->next;
	}
	return (list);
}
