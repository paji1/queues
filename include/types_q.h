/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_q.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:22:52 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/08/20 19:35:31 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TYPES_Q_H
# define TYPES_Q_H
/**
 * @file types.h
 * @brief Contains the types used in the project.
 */

/**
 * @brief node structure
 * @details Contains the data of node
 * @param data The data of the node.
 * @param next The next node.
 * @param prev The previous node.
 */
typedef struct s_node
{
	void *data;
	struct s_node *next;
	struct s_node *prev;
}t_node;

/**
 * @brief queeue structure
 * @note pointed to head and tail. of the queue.
 * @param head pointer to the head of the queue
 * @param tail pointer to the tail of the queue
 * @param size size of the queue
 *
 */
typedef struct s_queue
{
	struct s_node	*head;
	struct s_node	*tail;
	int				size;
}t_queue;
#endif /* !TYPES_H */