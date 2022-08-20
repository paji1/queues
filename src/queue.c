/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:38:56 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/08/20 06:29:36 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

/**
 * @brief allocate to a new node
 * 
 * @param data to put into the new node
 * @return allocate adress of the new node
 */

t_node	*new_node(void *data)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return NULL;
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

/**
 * @brief allocate for queue structure
 * @param none
 * 
 * @return allocate address for queue structure
 */
t_queue *new_queue()
{
	t_queue *queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
 		return (NULL);
	queue->head = NULL;
	queue->tail = NULL;
	queue->size = 0;
	return (queue);
}

/**
 * @brief put to the front of the queue
 * 
 * @param queue 
 * @param new_node
 */

void	qput(t_queue *queue, t_node *new)
{
	if (!(queue->head))
	{
		queue->head = new;
		queue->tail = new;
	}
	else
	{
		queue->head->prev = new;
		new->next = queue->head;
		queue->head = new;
	}
	queue->size += 1;
}

/**
 * @brief get from the back of the queue
 * 
 * @param queue
 * @return node that take form back of the queue
 */

t_node	*qget(t_queue *queue)
{
	t_node *tail;
	if (queue->head == NULL)
		return NULL;
	queue->size -= 1;
	tail = queue->tail;
	if (!(queue->size))
		return (queue->head = NULL, queue->tail = NULL, tail);
	queue->tail = queue->tail->prev;
	queue->tail->next = NULL;
	return tail;
}