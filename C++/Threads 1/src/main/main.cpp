#include "main.h"

#include <fcntl.h>
#include <iostream>
#include <unistd.h>

using std::cout;
using std::endl;
using std::flush;
using std::to_string;

int main()
{
	ThreadArguments threadArguments[NUMBER_OF_THREADS] = {
		{FILE_TO_SEARCH, "cout", 1},
		{FILE_TO_SEARCH, "NULL", 2},
		{FILE_TO_SEARCH, "void", 3},
		{FILE_TO_SEARCH, "endl", 4}};
	ThreadResults *threadResults[NUMBER_OF_THREADS];
	pthread_t thread[NUMBER_OF_THREADS];
	for (int i = 0; i < NUMBER_OF_THREADS; i++)
		pthread_create(&thread[i], NULL, searchWordInFile, &threadArguments[i]);
	for (int i = 0; i < NUMBER_OF_THREADS; i++)
		pthread_join(thread[i], (void **)&threadResults[i]);
	for (int i = 0; i < NUMBER_OF_THREADS; i++)
	{
		cout << "The word \"" << threadArguments[i].wordToSearch << "\" appears " << threadResults[i]->count << " times in the file \"" << threadArguments[i].fileToSearch << "\" which is " << threadResults[i]->position << " lines long." << endl;
		free(threadResults[i]);
	}
	return 0;
}

void *searchWordInFile(void *arg)
{
	ThreadArguments *threadArguments = (ThreadArguments *)arg;
	ThreadResults *threadResults = (ThreadResults *)malloc(sizeof(ThreadResults));
	bool eof = false;
	int file = open(threadArguments->fileToSearch.c_str(), O_RDONLY);
	if (file == -1)
	{
		cout << "Error opening the file" << endl;
		eof = true;
		threadResults->count = -1;
		threadResults->position = -1;
		pthread_exit(threadResults);
	}
	close(file);
	int wordSize = threadArguments->wordToSearch.size();
	while (!eof)
	{
		file = open(threadArguments->fileToSearch.c_str(), O_RDONLY);
		lseek(file, threadResults->position++ * (wordSize + 1), SEEK_SET);
		char buffer[wordSize + 1] = {0};
		int bytesRead = read(file, buffer, wordSize);
		close(file);
		string out = "";
		for (int i = 0; i < threadArguments->threadNumber; i++)
			out.append("\t");
		out.append(to_string(threadArguments->threadNumber));
		for (int i = 0; i < (NUMBER_OF_THREADS + 1) - threadArguments->threadNumber; i++)
			out.append("\t");
		if (bytesRead == -1)
		{
			cout << out.append("Error reading the file\n") << flush;
			eof = true;
			threadResults->position--;
		}
		else if (bytesRead == wordSize)
		{
			cout << out.append(threadArguments->wordToSearch.compare(buffer) == 0 ? threadResults->count++, "\033[32m" : "\033[31m").append(buffer).append("\033[0m\n") << flush;
		}
		else
		{
			eof = true;
			cout << out.append("\033[31m").append(buffer, bytesRead).append("\033[34mEOF\033[0m\n") << flush;
		}
	}
	pthread_exit(threadResults);
}
