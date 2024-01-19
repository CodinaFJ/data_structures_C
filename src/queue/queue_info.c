/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:37:50 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/19 18:06:16 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

size_t	queue_min_indx(const t_queue *queue)
{
	size_t		i;
	size_t		index_norm;
	size_t		min_index;
	long long	min;

	i = 0;
	min = LONG_MAX;
	while (i < queue->size)
	{
		index_norm = (queue->bottom + i) % queue->capacity;
		if (queue->array[index_norm] < min)
		{
			min = queue->array[index_norm];
			min_index = queue->bottom + i;
		}
		i++;
	}
	return (min_index);
}

size_t	queue_max_indx(const t_queue *queue)
{
	size_t		i;
	size_t		index_norm;
	size_t		max_index;
	long long	max;

	i = 0;
	max = -1;
	while (i < queue->size)
	{
		index_norm = (queue->bottom + i) % queue->capacity;
		if (queue->array[index_norm] > max)
		{
			max = queue->array[index_norm];
			max_index = queue->bottom + i;
		}
		i++;
	}
	return (max_index);
}

long long	queue_top(const t_queue *queue)
{
	size_t	index;

	index = (queue->bottom + queue->size - 1) % queue->capacity;
	return (queue->array[index]);
}

int	queue_is_empty(t_queue *queue)
{
	return (queue->size == 0);
}

int	queue_is_full(t_queue *queue)
{
	return (queue->size == queue->capacity);
}
