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
	FileInformations fileInformations = {"./assets/data.txt", "printf", 0, 0, false};
	ThreadArguments threadArguments[NUMBER_OF_THREADS] = {{&fileInformations, 1}};
	pthread_t thread[NUMBER_OF_THREADS];
	for (int i = 0; fileInformations.eof == false; i++)
	{
		pthread_create(&thread[0], NULL, searchWordInFile, &threadArguments[0]);
		pthread_join(thread[0], NULL);
	}
	cout << "The word \"" << fileInformations.wordToSearch << "\" appears " << fileInformations.count << " times in the file \"" << fileInformations.fileToSearch << "\" which is " << fileInformations.position << " lines long." << endl;
	return fileInformations.count;
}

void *searchWordInFile(void *arg)
{
	ThreadArguments *threadArguments = (ThreadArguments *)arg;
	int file = open(threadArguments->fileInformations->fileToSearch.c_str(), O_RDONLY);
	if (file == -1)
	{
		cout << "Error opening the file" << endl;
		threadArguments->fileInformations->eof = true;
		threadArguments->fileInformations->count = -1;
		pthread_exit(NULL);
	}
	lseek(file, threadArguments->fileInformations->position++ * (threadArguments->fileInformations->wordToSearch.size() + 1), SEEK_SET);
	char buffer[threadArguments->fileInformations->wordToSearch.size() + 1];
	int bytesRead = read(file, buffer, threadArguments->fileInformations->wordToSearch.size());
	close(file);
	string out = "";
	out.append("\t", threadArguments->threadNumber).append(to_string(threadArguments->threadNumber)).append("\t", (NUMBER_OF_THREADS + 1) - threadArguments->threadNumber);
	switch (bytesRead)
	{
	case -1:
		cout << out.append("Error reading the file\n") << flush;
		threadArguments->fileInformations->eof = true;
		threadArguments->fileInformations->position--;
		break;
	case 6:
		cout << out.append(threadArguments->fileInformations->wordToSearch.compare(buffer) == 0 ? threadArguments->fileInformations->count++, "\033[32m" : "\033[31m").append(buffer).append("\033[0m\n") << flush;
		break;
	default:
		threadArguments->fileInformations->eof = true;
		cout << out.append("\033[31m").append(buffer, bytesRead).append("\033[34mEOF\033[0m\n") << flush;
		break;
	}
	pthread_exit(NULL);
}
