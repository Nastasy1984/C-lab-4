#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "task4.h"

#define SIZE1 50

int main()
{
	char arr[SIZE1][SIZE1] = { 0 };
	char *str[SIZE1];
	FILE *fp = NULL;
	fp = fopen("text4.txt", "r+");
	if (fp == 0)//cheking of the file
	{
		printf("File error!\n");
		return 1;
	}
	int i = 0;
	while(!feof(fp))
	{
		fgets(arr[i], SIZE1, fp);
		if (arr[i][strlen(arr[i]) - 1] == '\n')//deleting \n in the end of the string
			arr[i][strlen(arr[i]) - 1] = '\0';
		str[i] = &arr[i][0];
		i++;
	}


	lineSort(str, i);


	printLinesToFile(str, i, fp);
	fclose(fp);
	return 0;
}