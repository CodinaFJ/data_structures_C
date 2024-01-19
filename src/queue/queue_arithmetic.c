/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_arithmetic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:59:16 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/19 18:06:10 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

size_t	queue_min_proxtonbr(const t_queue *queue, int nbr)
{
	size_t		i;
	size_t		index_norm;
	size_t		min_index;
	long long	min;

	i = 0;
	min_index = queue_max_indx(queue);
	min = queue->array[min_index % queue->capacity];
	while (i < queue->size)
	{
		index_norm = (queue->bottom + i) % queue->capacity;
		if (queue->array[index_norm] < nbr
			&& (queue->array[index_norm] > min || (min > nbr)))
		{
			min_index = queue->bottom + i;
			min = queue->array[index_norm];
		}
		i++;
	}
	return (min_index - queue->bottom);
}

size_t	queue_max_proxtonbr(const t_queue *queue, int nbr)
{
	size_t		i;
	size_t		index_norm;
	size_t		max_index;
	long long	max;

	i = 0;
	max_index = queue_min_indx(queue);
	max = queue->array[max_index % queue->capacity];
	while (i < queue->size)
	{
		index_norm = (queue->bottom + i) % queue->capacity;
		if (queue->array[index_norm] > nbr
			&& (queue->array[index_norm] < max || (max < nbr)))
		{
			max_index = queue->bottom + i;
			max = queue->array[index_norm];
		}
		i++;
	}
	return (max_index - queue->bottom);
}

t_bool	queue_cmp_str(t_queue *queue, char *str)
{
	char	**strs;
	size_t	i;
	size_t	index_norm;

	i = 0;
	strs = ft_split(str, ' ');
	if (strs == NULL)
		return (false);
	while (i < queue->size && strs[i] != NULL)
	{
		index_norm = (queue->bottom + queue->size - i - 1) % queue->capacity;
		if (queue->array[index_norm] != strs[i][0] - '0')
		{
			ft_strs_free(strs);
			return (false);
		}
		i++;
	}
	ft_strs_free(strs);
	return (true);
}

static int	how_many_lower(t_queue *queue, long long value)
{
	size_t		i;
	size_t		index_norm;
	long long	n;

	n = 0;
	i = 0;
	while (i < queue->size)
	{
		index_norm = (queue->bottom + i) % queue->capacity;
		if (queue->array[index_norm] < value)
			n++;
		i++;
	}
	return (n);
}

void	queue_normalize(t_queue *queue)
{
	size_t		i;
	size_t		index_norm;
	long long	*norm_array;

	norm_array = ft_calloc(queue->capacity, sizeof(long long));
	if (norm_array == NULL)
		return ;
	ft_bzero(norm_array, queue->capacity * sizeof(long long));
	i = 0;
	while (i < queue->size)
	{
		index_norm = (queue->bottom + i) % queue->capacity;
		norm_array[index_norm] = how_many_lower(
				queue,
				queue->array[index_norm]);
		i++;
	}
	free(queue->array);
	queue->array = norm_array;
}
