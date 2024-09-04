#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *file;
	char filename[100],ch;
	printf("Enter the filename:\n");
	scanf("%s",filename);
	file=fopen(filename,"r");
	if(file==NULL)
	{
		printf("Cannot Open File:");
		exit(0);
	}
	printf("File Contents\n");

	while((ch=fgetc(file))!=EOF)
	{
		putchar(ch);
	}
	fclose(file);
	return 0;
}
