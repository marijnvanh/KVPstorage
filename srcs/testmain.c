#include <stdio.h>

int	main(void)
{
	FILE *test = fopen("testfile", "a");

	fwrite("12\0\0 678\0\0", 1, 10, test);
}