/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:37:49 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/29 11:56:30 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_btree	*btree_new(void *content)
{
	t_btree	*btree;

	btree = ft_calloc(1, sizeof(t_btree));
	if (btree == NULL)
		return (NULL);
	btree->content = content;
	btree->left = NULL;
	btree->right = NULL;
	return (btree);	
}

void	btree_free(t_btree **btree, void (*del)(void *content))
{
	if (*btree == NULL)
		return ;
	if ((*btree)->content != NULL)
	{
		del((*btree)->content);
		(*btree)->content = NULL;
	}
	if ((*btree)->left != NULL)
		btree_free(&(*btree)->left, del);
	if ((*btree)->right != NULL)
		btree_free(&(*btree)->right, del);
	free(*btree);
	*btree = NULL;
}

void	btree_print(t_btree *btree, char *level, void (*print)(void *content))
{
    char    *str_aux;

	if (btree == NULL)
		return ;
	ft_printf("[%s] -> ", level);
	if (btree->content == NULL)
		ft_printf("(null)\n");
	else
		print(btree->content);
	ft_printf("\n");
	if (btree->left != NULL)
    {
        str_aux = ft_strjoin(level, "l");
		btree_print(btree->left, str_aux, print);
        free(str_aux);
    }
	if (btree->right != NULL)
    {
        str_aux = ft_strjoin(level, "r");
		btree_print(btree->right, str_aux, print);
        free(str_aux);
    }
}

void	btree_clear(t_btree *btree, void (*del)(void *content))
{
	if (btree == NULL)
		return ;
	if (btree->content != NULL)
	{
		del(btree->content);
		btree->content = NULL;
	}
	if (btree->left != NULL)
	{
		btree_free(&(btree->left), del);
		btree->left = NULL;
	}
	if (btree->right != NULL)
	{
		btree_free(&(btree->right), del);
		btree->right = NULL;
	}
}

t_btree	*btree_dup(t_btree *btree, void *(*dup)(void *content), void (*del)(void *content))
{
	t_btree	*new_btree;
	t_bool	error;

	error = false;
	new_btree = btree_new(dup(btree->content));
	if (new_btree == NULL)
		return (NULL);
	if (btree->left != NULL)
	{
		new_btree->left =  btree_dup(btree->left, dup, del);
		if (new_btree->left == NULL)
			error = true;
	}
	if (btree->right != NULL)
	{
		new_btree->right =  btree_dup(btree->right, dup, del);
		if (new_btree->right == NULL)
			error = true;
	}
	if (error)
		btree_free(&new_btree, del);
	return (new_btree);
}
