#include <stdio.h>
#include <stdlib.h>

typedef struct	node
{
	float	value;
	struct node	*next;
}node_t;

typedef node_t	stack;

void	free_stack(stack *s)
{
		stack	*tempNode;
		while (s)
		{
				tempNode = s;
				s = *s -> next;
				free(tempNode);
		}
}

void	push(stack **s, char c)
{
		stack	*tempNode;
		tempNode = malloc(sizeof(stack));
		if (tempNode)
		{
				tempNode -> value = c - '0';
				tempNode -> next = *s;
				*s = tempNode;
		}
}

void	operate(stack **s, char c)
{
		stack *tempNode;

		tempNode = *s;
		if (c == '+')
		{
				*s = (*s) -> next;
				(*s) -> value += tempNode -> value;
				free(tempNode);
		}
		else if (c == '-')
		{
				*s = (*s) -> next;
				(*s) -> value -= tempNode -> value;
				free(tempNode);
		}
		else if (c == '*')
		{
				*s = (*s) -> next;
				(*s) -> value *= tempNode -> value;
				free(tempNode);
		}
		else if (c == '/')
		{
				*s = (*s) -> next;
				(*s) -> value /= tempNode -> value;
				free(tempNode);
		}
}

int	main(void)
{
		stack	*s = NULL;
		int		size;
		char	c;

		scanf("%d", &size);
		for (int i = 0; i < size; i++)
		{
				scanf(" %c", &c);
				if (c >= '0' && c <= '9')
						push(&s, c);
				else if (s && *s -> next && (c == '+' || c == '-' || c == '*' || c == '/'))
						operate(&s, c);
				else
				{
						printf("Error\n");
						free_stack(s);
						return (1);
				}
		}
		if (s && !(*s -> next))
		{
				printf("%.2f\n", s -> value);
				free(s);
		}
		else if (*s -> next)
		{
			printf("Error\n");
			free_stack(s);
		}
		else
				printf("0.00\n");
		return (0);
}