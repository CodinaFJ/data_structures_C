/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:59:56 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/02 12:18:18 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_insert(t_btree *btree ,t_btree *node, t_leaf leaf_side, void (*del)(void *content))
{
	if (leaf_side == LEFT)
	{
		if (btree->left != NULL)
			btree_free(&(btree->left), del);
		btree->left = node;
	}
	else if (leaf_side == RIGHT)
	{
		if (btree->right != NULL)
			btree_free(&(btree->left), del);
		btree->right = node;
	}
}
