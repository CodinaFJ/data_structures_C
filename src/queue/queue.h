/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:17:16 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/19 19:18:39 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../../lib/libft/include/libft.h"

# ifndef _E_BOOL
#  define _E_BOOL

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;
# endif

typedef struct s_queue_i
{
	char			id;
	size_t			top;
	size_t			bottom;
	size_t			size;
	size_t			capacity;
	long long		*array;
}	t_queue;

/*									QUEUE BASICS							  */

t_queue		*queue_new(size_t size, char id);
void		queue_free(t_queue *queue);
void		queue_print(t_queue *queue);
void		queue_clear(t_queue *queue);
t_queue		*queue_dup(t_queue *queue);

/*									QUEUE INFO								  */

int			queue_is_full(t_queue *queue);
int			queue_is_empty(t_queue *queue);
long long	queue_top(const t_queue *queue);
size_t		queue_max_indx(const t_queue *queue);
size_t		queue_min_indx(const t_queue *queue);

/*									QUEUE OPERATIONS						  */

int			enqueue(t_queue *queue, long long n);
long long	dequeue(t_queue *queue);
// Operations deprecated, left for stacks
// int			enqueue_front(t_queue *queue, long long n);
// long long	dequeue_bottom(t_queue *queue);

/*									QUEUE ARITHMETIC						  */
/*
 To iterate through a queue:
 
	size_t	i;
	size_t	index_norm;

	i = 0;
	while (i < queue->size)
	{
		index_norm = (queue->bottom + i) % queue->capacity;
		i++
	}

 In general:
 
	index = queue->bottom + i;
	index_norm = (queue->bottom + i) % queue->capacity;
*/

int			queue_find_index(
				t_queue *queue,
				enum e_bool (*cmp)(int winner, int candidate));
void		queue_normalize(t_queue *queue);
t_bool		queue_cmp_str(t_queue *queue, char *str);
size_t		queue_min_proxtonbr(const t_queue *queue, int nbr);
size_t		queue_max_proxtonbr(const t_queue *queue, int nbr);
#endif