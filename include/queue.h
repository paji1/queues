#ifndef QUEEUE_H
# define QUEEUE_H
/** 
 * @file queue.h
 * @brief Contains the functions used in the project.
 */

// ---------------------------------
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


// ---------include_path ------------
#include "types_q.h"

t_queue	*new_queue();
void	qput(t_queue *queue, t_node *new);
t_node	*new_node(void *data);
t_node	*qget(t_queue *queue);
void	free_queue(t_queue *queue);
#endif /* !QUEEUE_H */