//This program has a buffer overflow vulnerability
//The task is to exploit this vulnerability
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int bof(char *str)
{
	char buffer[64];
	strcpy(buffer,str);
	printf("%s \n",buffer);
	return 1;
}
int main(int argc, char **argv)
{
	bof(argv[1]);
	printf("Returned Properly\n");
	return 1;
}
