#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <tchar.h>
#include <string.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

int getInt(int lowBound, int highBound);
void swapLetters(char* str); /*to move the last letter to the beginning of each word*/
void deleteExcessLetters(char* str); /*leave only the first occurrences of each letter in the words*/

int main()
{
	printf("Enter number of lines you want to work with: ");
	int numberOfLines = getInt(1,50);
	printf("Enter maximum length of line you want to work with: ");
	int lineLengths = getInt(2,140);
	lineLengths++;
	char* str = (char*)malloc(lineLengths*sizeof(char));
	if (str == NULL)
	{
		printf("Can't allocate memory\n");
		return 1;
	}
	int i;
	for (i = 0; i < numberOfLines; i++)
	{
		if (gets(str) == NULL)
		{
			printf("Can't get line\n");
			continue;
		}
		str[lineLengths - 1] = '\0'; /*for the case of too long input*/
		printf("Input line: %s\n", str);
		swapLetters(str);
		printf("changed words: %s\n", str);
		deleteExcessLetters(str);
		printf("delete excess letters: %s\n", str);
	}
	printf("Enter anything to end: ");
	getchar();
	free(str);
	return 0;
}


int getInt(int lowBound, int highBound)
{
	int command;
	char ch;
	while (scanf("%d%c", &command, &ch) != 2 || ch != '\n' || command < lowBound || command > highBound)
	{
		printf("Incorrect value, required integer from %d to %d, enter again: ", lowBound, highBound);
		while (getchar() != '\n');
	}
	return command;
}

void swapLetters(char* str)
{ /*to move the last letter to the beginning of each word*/
	char lastLetter;
	int firstLetterPosition;
	int inWord = 0;
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			if (inWord == 0)
			{
				firstLetterPosition = i;
			}
			inWord = 1;
		}
		else {
			if (inWord == 1)
			{
				lastLetter = str[i - 1];
				str[i - 1] = str[firstLetterPosition];
				str[firstLetterPosition] = lastLetter;
			}
			inWord = 0;
		}
	}
	if (inWord)
	{
		lastLetter = str[i - 1];
		str[i - 1] = str[firstLetterPosition];
		str[firstLetterPosition] = lastLetter;
	}
}

void deleteExcessLetters(char* str)
{ /*leave only the first occurrences of each letter in the words*/
	char lastLetter;
	int firstLetterPosition, lastLetterPostion;
	int inWord = 0;
	int i, j;
	int visitedLetters[52];
	int counter = 0; /*represents number of deleted elements*/
	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			if (inWord == 0)
			{
				firstLetterPosition = i;
			}
			inWord = 1;
		}
		else
		{
			if (inWord == 1)
			{
				for (j = 0; j < 52; j++)
				{
					visitedLetters[j] = 0;
				}
				lastLetterPostion = i - 1;
				int shift;
				for (j = firstLetterPosition; j <= lastLetterPostion; j++)
				{
					if (str[j] >= 'A' && str[j] <= 'Z')
					{
						shift = 65;
					}
					else
					{
						shift = 71;
					}
					if (visitedLetters[str[j] - shift] == 0)
					{
						visitedLetters[str[j] - shift] = 1;
						str[j - counter] = str[j];
						if (counter != 0)
						{
							str[j] = ' ';
						}
					}
					else
					{
						str[j] = ' ';
						counter++;
					}
				}
			}
			inWord = 0;
		}
	}
	if (inWord == 1)
	{
		for (j = 0; j < 52; j++)
		{
			visitedLetters[j] = 0;
		}
		lastLetterPostion = i - 1;
		int counter = 0; /*represents number of deleted elements*/
		int shift;
		for (j = firstLetterPosition; j <= lastLetterPostion; j++)
		{
			if (str[j] >= 'A' && str[j] <= 'Z')
			{
				shift = 65;
			}
			else
			{
				shift = 71;
			}
			if (visitedLetters[str[j] - shift] == 0)
			{
				visitedLetters[str[j] - shift] = 1;
				str[j - counter] = str[j];
				if (counter != 0)
				{
					str[j] = ' ';
				}
			}
			else
			{
				str[j] = ' ';
				counter++;
			}
		}
	}
}
