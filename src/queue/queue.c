/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:24:17 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/19 18:06:24 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_print(t_queue *queue)
{
	size_t	i;
	size_t	size;

	size = queue->size;
	i = queue->top;
	ft_printf("\nPRINT QUEUE %c\n----------\n", queue->id);
	if (size == 0)
		ft_printf("queue empty\n");
	else
	{
		while (size > 0)
		{
			ft_printf("%d\n", queue->array[i]);
			size--;
			if (i == 0)
				i = queue->capacity - 1;
			else
				i--;
		}
	}
	ft_printf("----------\n");
}

t_queue	*queue_new(size_t capacity, char id)
{
	t_queue	*queue;

	queue = malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->capacity = capacity;
	queue->array = malloc(sizeof(long long) * capacity);
	if (queue->array == NULL)
	{
		free(queue);
		return (NULL);
	}
	ft_bzero(queue->array, sizeof(long long) * capacity);
	queue->id = id;
	queue->size = 0;
	queue->top = 0;
	queue->bottom = 0;
	return (queue);
}

t_queue	*queue_dup(t_queue *queue)
{
	t_queue	*queue_dup;
	size_t		i;

	i = 0;
	queue_dup = queue_new(queue->capacity, queue->id);
	if (queue_dup == NULL)
		return (NULL);
	queue_dup->bottom = queue->bottom;
	queue_dup->top = queue->top;
	queue_dup->size = queue->size;
	while (i < queue->capacity)
	{
		queue_dup->array[i] = queue->array[i];
		i++;
	}
	return (queue_dup);
}

void	queue_free(t_queue *queue)
{
	if (queue == NULL)
		return ;
	if (queue->array != NULL)
		free(queue->array);
	free(queue);
}
