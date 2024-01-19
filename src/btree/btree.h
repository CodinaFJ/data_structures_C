/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:17:16 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/19 18:22:56 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
# define BINARY_TREE_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../../lib/libft/includes/libft.h"

# ifndef _E_BOOL
#  define _E_BOOL

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;
# endif

typedef enum e_leaf
{
	LEFT,
	RIGHT
}	t_leaf;

typedef struct s_btree
{
	char			*content;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

/*									BTREE BASICS							  */

t_btree	*btree_new(char *content);
void	btree_free(t_btree **btree);
void	btree_print(t_btree *btree, char *level);
void	btree_clear(t_btree *btree);
t_btree	*btree_dup(t_btree *btree);

/*									BTREE INFO								  */

t_bool	btree_is_empty(t_btree *btree);

/*									BTREE OPERATIONS						  */

void	btree_insert(t_btree *btree ,t_btree *node, t_leaf leaf_side);

#endif