#include <stdio.h>
#include <string.h>

#define MAX_FNAME_SIZE 128
#define LINE_LENGTH 1024
#define	LINES 3072
#define MAX_QUERY_SIZE 32

char fname[MAX_FNAME_SIZE];
char buffer[MAX_QUERY_SIZE];

int main(int argc, char* argv[])
{
	// read file
	if (argc <= 1) 
	{
		printf("too few arguments\n");
		printf("expected file name as first argument\n");
		return 1;
	}
	strcpy(fname, argv[1]);
	FILE* fp;
	fp = fopen(fname, "r");
	if (fp == NULL) 
	{
		printf("Could not open file\n");
		return 1;
	}
	char file_c[LINES][LINE_LENGTH];
	int i=0;
	while (fgets(*file_c + i * LINE_LENGTH, LINE_LENGTH, fp))
	{
	//	printf("%d| %s",i + 1, file_c[i]);
		i++;
	}
	char* sent;
	int j;
	while (1){
		printf("\e[1;1H\e[2J");
		// get query string
		printf("Enter string to search:\n");
		fgets(buffer, MAX_QUERY_SIZE, stdin);
		*((char *) strstr(buffer, "\n")) = 0;
		j = 0;
		while(j < i)
		{
		// search for string
			sent = *file_c + j * LINE_LENGTH;
			if (strstr(sent, buffer) != 0)
			{
				printf("(%d) %s", j + 1, file_c[j]);
			}
			j++;
		}
		printf("Press <ENTER> to try again...\n");
        getchar();
	}
}
