#include <stdio.h>
#include <stdlib.h>

typedef struct node {   
    int data;
    struct node *next;
} node_t;
typedef node_t Stack;

Stack *push(Stack *s, int value) {
    Stack *tempNode ; 
    tempNode = malloc(sizeof(Stack)) ;
    if (tempNode == NULL) { 
        return s ; 
    }
    tempNode->data = value ; 
    tempNode->next = s ; 
    s = tempNode ; 
    return s ;
}

void *top(Stack *s){
    if (s!=NULL) {
        printf("%d\n",s->data) ;
    }else {
        printf("Stack is empty.\n") ; 
    }

}

Stack *pop(Stack *s){
    Stack *tempNode  ;
	if (!(tempNode = s))
		return (NULL);

    s = s -> next ; 
    free(tempNode) ; 
    return s ; 
}


void empty(node_t *s) {
    if (s == NULL) {
        
        printf("Stack is empty.\n");
    }
    else {
        printf("Stack is not empty.\n");
    }
}

void size(node_t *s) {
    int count = 0;
    while (s) {
        s = s->next;
        count++;
    }
    printf("%d\n",count); 
}

int	main(void)
{
		Stack	*s = NULL;
		int		n, i, command, value;
		
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
				scanf("%d", &command);
				switch(command)
                {
					case 1: scanf("%d", &value); s = push(s, value); break;
					case 2: top(s); break;
					case 3: s = pop(s); break;
					case 4: empty(s); break;
					case 5: size(s); break;
				}
		}
		return 0;
}
