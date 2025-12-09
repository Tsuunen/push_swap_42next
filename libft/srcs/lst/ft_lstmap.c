/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <relaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:02:26 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/06 11:32:29 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;
	void	*new_content;

	new = NULL;
	while (lst && del && f)
	{
		new_content = f(lst->content);
		if (!new_content)
		{
			ft_lstclear(&new, del);
			return (new);
		}
		node = ft_lstnew(new_content);
		if (!node)
		{
			del(new_content);
			ft_lstclear(&new, del);
			return (new);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
