/*

*/

#include <stdio.h>

void	read_loop(void)
{
	char	*line;
	size_t	len;
	ssize_t	ret;

	line = NULL;
	while (1)
	{
		printf("> ");
		ret = getline(&line, &len, stdin); // this is weard 
		putchar('\n');
		printf("line = %s\n", line);
	}
}
