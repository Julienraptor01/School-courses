#ifndef MAIN_H
#define MAIN_H

#define NUMBER_OF_THREADS 4
#define FILE_TO_SEARCH "./assets/data.txt"

#include <string>

using std::string;

typedef struct
{
	const string fileToSearch;
	const string wordToSearch;
	int threadNumber;
} ThreadArguments;

typedef struct
{
	int position;
	int count;
} ThreadResults;

int main();
void *searchWordInFile(void *arg);

#endif
