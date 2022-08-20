/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:45:02 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/08/20 19:42:33 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	t_queue *queue = new_queue();
	qput(queue, new_node((void *)"hello world"));
	qput(queue, new_node((void *)"hello world1"));
	qput(queue, new_node((void *)"hello world2"));
	qput(queue, new_node((void *)"hello world3"));
	qput(queue, new_node((void *)"hello world4"));
	free(qget(queue));
	// printf("%s\n\n",(char *)qget(queue)->data);
	free_queue(queue);
	// t_node *temp;

	// temp = queue->head;
	// while (temp)
	// {
	// 	printf("%s\n",(char *)temp->data);
	// 	temp = temp->next;
	// }
	return 0;
}

