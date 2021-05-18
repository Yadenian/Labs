#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif
 void searchWords(FILE* words, char** dictionary, int dictionSize, int* output);

int main()
{
	const char* Dictionary_FILENAME = "dictionary.txt";
	FILE* dictionary = fopen("dictionary.txt", "r");
	if (dictionary == NULL) {
		printf("Can't access dictionary\n");
		return 1;
	}
	int numberOfDictionaryWords;
	if (fscanf(dictionary, "%d", &numberOfDictionaryWords) != 1) {
		printf("Can't read number of lines in dictionary\n");
		return 1;
	}
	getc(dictionary); /*enter after number*/
	char** dictionaryWords = (char**)malloc(numberOfDictionaryWords * sizeof(char*));
	if (dictionaryWords == NULL) {
		printf("Can't allocate memory\n");
		return 1;
	}
	int i;
	for (i = 0; i < numberOfDictionaryWords; i++) {
		dictionaryWords[i] = (char*)malloc(256 * sizeof(char)); /*can't be bigger than 256*/
		if (dictionaryWords[i] == NULL) {
			printf("Can't allocate memory\n");
			i--;
			for (; i >= 0; i--) {
				free(dictionaryWords[i]);
			}
			free(dictionaryWords);
		}
		fgets(dictionaryWords[i], 255, dictionary);
		dictionaryWords[i][255] = '\0';
	}
	fclose(dictionary);
	int* dictionaryWordsCounter = (int*)malloc(numberOfDictionaryWords * sizeof(int));
	for (i = 0; i < numberOfDictionaryWords; i++) {
		dictionaryWordsCounter[i] = 0;
	}
	printf("Enter name of txt file whit .txt on the end: ");
	char nameOfFile[100];
	gets(nameOfFile);
	FILE* textFile = fopen(nameOfFile, "r");
	if (textFile == NULL) {
		printf("Can't open txt file\n");
		return 1;
	}
	searchWords(textFile, dictionaryWords, numberOfDictionaryWords, dictionaryWordsCounter);
	fclose(textFile);
	printf("dictionary words:\n");
	for (i = 0; i < numberOfDictionaryWords; i++) {
		printf(dictionaryWords[i]);
		printf("%d\n", dictionaryWordsCounter[i]);
	}
	for (i = 0; i < numberOfDictionaryWords; i++) {
		free(dictionaryWords[i]);
	}
	free(dictionaryWords);
	getchar();
	return 0;
}


void searchWords(FILE* words, char** dictionary, int dictionSize, int* output)
{
 char wordLine[556];
	while (fgets(wordLine, 554, words) != NULL)
	{
		int i,j,g, isword;
		for (i = 0; i < dictionSize; i++)
		{
			for (j = 0; wordLine[j] != '\0'; j++)
			{
				if ((wordLine[j] >= 'A' && wordLine[j] <= 'Z') || (wordLine[j] >= 'a' && wordLine[j] <= 'z'))
				{
					isword = 1;
					g = 0;
					while ((dictionary[i][g] >= 'A' && dictionary[i][g] <= 'Z') || (dictionary[i][g] >= 'a' && dictionary[i][g] <= 'z'))
					{
						if (dictionary[i][g] != wordLine[j])
						{
							isword = 0;
						}
						g++;
						j++;
					}
					if (isword)
					{
						output[i]++;
					}
				}
			}
		}
	}

}
