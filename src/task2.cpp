#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "task2.h"

char * reverseWords(char * in, char *out)

{
	if (in[strlen(in) - 1] == '\n')//deleting \n in the end of the string
		in[strlen(in) - 1] = '\0';
	char * pointers[SIZE] = { 0 };
	int count = 0;
	int inWord = 0;

	for (int i = 0; in[i] != '\0'; i++)
	{
		if (in[i] == ' ')// cheking if we are in the word
			inWord = 0;//we are not in the word!
		else
		{
			if (!inWord)//if we were not in the word previously
			{
				inWord = 1;//now we in the word
				pointers[count] = &(in[i]);//the pointer point to the first symbol of the word
				count++;//counter of pointers is increasing
			}
		}
	}


	int k = 0;
	for (int i = count - 1; i >= 0; i--)
	{
		int j = 0;
		for (int j = 0; j < (strlen(pointers[i])); j++)
			if (pointers[i][j] == ' ')
				break;
			else
			{
				out[k] = pointers[i][j];
				k++;
			}
		out[k] = ' ';
		k++;
	}
	
	out[strlen(in)] = '\0';
}