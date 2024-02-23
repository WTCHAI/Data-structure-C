#include <stdio.h>
#include <stdlib.h>
#define True 1
#define	False 0

int	traverseMaze(char **mazeData, int size, int row, int col);

char	**create_maze(int size)
{
	char	**mazeData;
	char	c;
	int	j;

	mazeData = (char **)malloc(sizeof(char *) * size) ;
	if (!mazeData)
		return (NULL);
	for (int i = 0; i < size; i++)
	{
		mazeData[i] = (char *)malloc(sizeof(char) * (size + 1));
		if (!mazeData[i])
			return (NULL);
		j = 0;
		while ((c = getchar()) != '\n')
			mazeData[i][j++] = c;
		mazeData[i][size] = 0;
	}
	return (mazeData);
}

int	find_row_char(char **mazeData, int size, char c)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (mazeData[i][j] == c)
				return (i);
	return (-1);
}

int	find_col_char(char **mazeData, int size, char c)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (mazeData[i][j] == c)
				return (j);
	return (-1);
}

int	is_can_walk(char **mazeData, int size, int row, int col)
{
	if (row < 0 || col < 0 || row == size || col == size)
	       return (False);
	if (mazeData[row][col] == ' ')
	{
		mazeData[row][col] = '.';
		return (True);
	}
	else if (mazeData[row][col] == 'G')
		return (traverseMaze(mazeData, size, row, col));
	return (False);
}

int	is_finish(char **mazeData, int row, int col)
{
	if (mazeData[row][col] == 'G')
		return (True);
	return (False);
}

int	traverseMaze(char **mazeData, int size, int row, int col)
{
	while (!is_finish(mazeData, row, col))
	{
		if (is_can_walk(mazeData, size, row, col + 1))
			if (traverseMaze(mazeData, size, row, col + 1))
				return (True);
		if (is_can_walk(mazeData, size, row - 1, col))
			if (traverseMaze(mazeData, size, row - 1, col))
				return (True);
		if (is_can_walk(mazeData, size, row, col - 1))
			if (traverseMaze(mazeData, size, row, col - 1))
				return (True);
		if (is_can_walk(mazeData, size, row + 1, col))
			if (traverseMaze(mazeData, size, row + 1, col))
				return (True);
		mazeData[row][col] = ' ';
		if (mazeData[row][col] == ' ')
			return (False);
	}
	return (True);
}

void	print_maze(char **maze, int size)
{
	for (int i = 0; i < size; i++)
		printf("%s\n", maze[i]);
}

int	main(void)
{
	char	**maze;
	int	size;

	scanf("%d\n", &size);
	maze = create_maze(size);
	//printf("==========================\n");
	if (find_row_char(maze, size, 'S') < 0 || find_col_char(maze, size, 'S') < 0)
		printf("There is no 'S' position.\n");
	else if (find_row_char(maze, size, 'G') < 0 || find_col_char(maze, size, 'G') < 0)
		printf("There is no 'G' position.\n");
	else if (traverseMaze(maze, size, find_row_char(maze, size, 'S'), find_col_char(maze, size, 'S')))
	{
		print_maze(maze, size);
		//printf("There is the way to walk from S(%d, %d) to G(%d, %d) (^-^)\n", \
			find_row_char(maze, size, 'S'), find_col_char(maze, size, 'S'), \
			find_row_char(maze, size, 'G'), find_col_char(maze, size, 'G'));
	}
	else
		printf("There is no path to walk to 'G' position (;-;)\n");
	for (int i = 0; i < size; i++)
		free(maze[i]);
	free(maze);
	return (0);
}