#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node_t;
// Write your code here
// ...

int *append(node_t *startNode){
    node_t *temp , *node ; 
    temp = malloc(sizeof(node_t)) ;
    if (!temp) {
        // this mean falied
        return NULL ; 
    }
    // get number for new node 
    scanf("%d",&temp -> data ) ; 
    // set next node pointer to null 
    temp -> next = NULL; 
    // check is startNode is 
	if (!startNode){
		startNode = temp;
    }
    // null case which mean we add new elemnet here 
	else
	{   
        // find the last node in link list 
		node = startNode;
		while (node -> next){
			node = node -> next;
        }
        // add new node to the end of list 
		node -> next = temp;
	}
	return (startNode);
}

void get(node_t *startNode) {
    node_t *node;
    int index;
    node = startNode;
    scanf("%d", &index);
    for (int i = 0; i < index; i++) {
        node = node->next;
        if (node == NULL) {
            break;
        }
    }
    if (node && index >= 0) {
        printf("%d\n", node->data);
    } else {
        printf("Out of range.\n");
    }
}

int *show (node_t *startNode){
    node_t *node ; 
    node = startNode ;
    while (node!=NULL){
		printf("%d", node -> data);
		node = node -> next;
		if (node)
			printf(" ");
    }
	printf("\n");
}

int *reverse(node_t *startNode){
	node_t	*newNode, *node, *temp1, *temp2;
	int	size;

	newNode = NULL;
	node = startNode;
	size = 0;
	while (node!=NULL){
		node = node -> next;
		size++;
	}
	for (int i = size; i > 0; i--)
	{
		temp1 = startNode;
		for (int j = 0; j < i - 1; j++)
			temp1 = temp1 -> next;
		temp2 = (node_t *)malloc(sizeof(node_t));
		if (!temp2){
			return (startNode);
        }
		temp2 -> data = temp1 -> data;
		temp2 -> next = NULL;
		if (!newNode)
			newNode = temp2;
		else{
			node = newNode;
			while (node -> next)
				node = node -> next;
			node -> next = temp2;
		}
			
	}
	return (newNode);
}

int *cut(node_t *startNode){
{
	node_t	*newNode, *node, *tmp1, *tmp2;
	int	start, end, size;

	scanf("%d %d", &start, &end);
	node = startNode;
	size = 0;
	while (node)
	{
		node = node -> next;
		size++;
	}
	if (start < 0 || start >= size || end < 0 || end >= size)
	{
		printf("Out of range.\n");
		return (startNode);
	}
	if (start > end)
	{
		start = start + end;
		end = start - end;
		start = start - end;
	}
	newNode = NULL;
	tmp1 = startNode;
	for (int i = 0; i < start; i++)
		tmp1 = tmp1 -> next;
	for (int i = start; i <= end; i++)
	{
		tmp2 = (node_t *)malloc(sizeof(node_t));
		if (!tmp2)
			return (startNode);
		tmp2 -> data = tmp1 -> data;
		tmp2 -> next = NULL;
		if (!newNode)
			newNode = tmp2;
		else
		{
			node = newNode;
			while (node -> next)
				node = node -> next;
			node -> next = tmp2;
		}
		tmp1 = tmp1 -> next;
	}
	return (newNode);
}

}

int main(void) {
    node_t *startNode;
    int n,i;
    char command;
    startNode = NULL;
    scanf("%d", &n);
        for (i=0; i<n; i++) {
            scanf(" %c", &command);
            switch (command) {
                case 'A':
                    startNode = append(startNode);
                    break;
                case 'G':
                    get(startNode);
                    break;
                case 'S':
                    show(startNode);
                    break;
                case 'R':
                    startNode = reverse(startNode);
                    break;
                case 'C':
                    startNode = cut(startNode);
                    break;
                default:
                    break;  
    }
    }
return 0;
}