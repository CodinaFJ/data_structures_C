/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:56:27 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/19 18:09:42 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

// Operation deprecated, left for stacks
int	enqueue_front(t_queue *queue, long long n)
{
	if (queue->size == queue->capacity)
	{
		ft_printf("[ERROR] Stack overflow\n");
		return (1);
	}
	if (queue->size > 0)
		queue->top = (queue->top + 1) % queue->capacity;
	queue->array[queue->top] = n;
	queue->size++;
	return (0);
}

int	enqueue(t_queue *queue, long long n)
{
	if (queue->size == queue->capacity)
	{
		ft_printf("[ERROR] Stack overflow\n");
		return (1);
	}
	if (queue->bottom == 0 && queue->size > 0)
		queue->bottom = queue->capacity - 1;
	else if (queue-> size > 0)
		queue->bottom--;
	queue->array[queue->bottom] = n;
	queue->size++;
	return (0);
}

long long	dequeue(t_queue *queue)
{
	long long	value;

	if (queue->size == 0)
	{
		ft_printf("[ERROR] Stack underflow\n");
		return (INT_MIN);
	}
	value = queue->array[queue->top];
	if (queue->top == 0)
		queue->top = queue->capacity - 1;
	else
		queue->top--;
	queue->size--;
	return (value);
}

// Operation deprecated, left for stacks
long long	dequeue_bottom(t_queue *queue)
{
	long long	value;

	if (queue->size == 0)
	{
		ft_printf("[ERROR] Stack underflow\n");
		return (INT_MIN);
	}
	value = queue->array[queue->bottom];
	queue->bottom = (queue->bottom + 1) % queue->capacity;
	queue->size--;
	return (value);
}

void	queue_clear(t_queue *queue)
{
	queue->top = 0;
	queue->bottom = 0;
	queue->size = 0;
}
