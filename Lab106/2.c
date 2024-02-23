#include <stdio.h>
#include <stdlib.h>

typedef struct	tempNode
{
	int			data;
	struct tempNode	*next;
} tempNode_t;

typedef tempNode_t queue_t;

queue_t *rear = NULL ; 

queue_t *enqueue(queue_t *q , int value ){
	queue_t *tempNode = malloc(sizeof(queue_t));
		if (tempNode == NULL){
		    return (q);
		}
		// prepare data to data = value then next = null
		tempNode -> data = value;
		tempNode -> next = NULL;
		// if queue 
		if (!q)
		{
			q = tempNode;
			rear = tempNode;
		}
		else
		{
			rear -> next = tempNode;
			rear = tempNode;
		}
		return (q); 
}

queue_t *dequeue (queue_t *q){
		queue_t	*tempNode;

		tempNode = q;

		if (tempNode == NULL)
				printf("Queue is empty.\n");
		else
		{
				printf("%d\n", q -> data);
				q = q -> next;
				free(tempNode);
		}
		return (q);

}

void show(queue_t *q){
	if (q==NULL){
		printf("Queue is empty.\n");
	}
	else {
		printf("%d",q->data) ; 
		while (q->next!=NULL){
			printf("%d",q->next) ; 
			q = q->next ; 
		}
	}
}

void empty(queue_t *q){
	if (q){
		printf("Queue is not empty.\n");
	}
	else {
		printf("Queue is empty.\n");

	}
}

void size(queue_t *q){
	int		size = 0 ;
	while (q)
	{
		q = q -> next;
		size++;
	}
	printf("%d\n", size);
}

int	main(void)
{
	queue_t	*q = NULL;
	int 	n, i, command, value;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		{
			scanf("%d", &command);
			switch(command)
			{
				case 1:
					scanf("%d", &value);
					q = enqueue(q, value); break;
				case 2: q = dequeue(q); break;
				case 3: show(q); break;
				case 4: empty(q); break;
				case 5: size(q); break;
			}
	}
	return 0;
}

/*
 *		1 :	enqueue()
 *		2 :	dequeue()
 *		3 :	show()
 *		4 :	empty()
 *		5 :	size()
 */