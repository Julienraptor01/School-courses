#ifndef MAIN_H
#define MAIN_H

#define NUMBER_OF_THREADS 1

#include <string>

using std::string;

typedef struct
{
	const string fileToSearch;
	const string wordToSearch;
	int position;
	int count;
	bool eof;
} FileInformations;

typedef struct
{
	FileInformations *fileInformations;
	int threadNumber;
} ThreadArguments;

int main();
void *searchWordInFile(void *arg);

#endif
