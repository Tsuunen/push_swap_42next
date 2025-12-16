/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahecre <nahecre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:53:44 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/16 10:06:29 by nahecre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*aux;

	if (!del || !lst || !*lst)
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
