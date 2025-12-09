/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <relaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:53:44 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/06 11:32:06 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*aux;

	if (!del)
		return ;
	curr = *lst;
	while (curr)
	{
		aux = curr;
		curr = curr->next;
		ft_lstdelone(aux, del);
	}
	*lst = NULL;
}
