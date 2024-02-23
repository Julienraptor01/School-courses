#include "main.h"

#include <cstring>
#include <iostream>

using std::cout;
using std::endl;
using std::flush;

ThreadArguments partage = {0, "", 0};

int main()
{
	ThreadArguments threadArguments[THREADS_COUNT] = {
		{1, "Matagne", 15},
		{2, "Wilvers", 10},
		{3, "Wagner", 17},
		{4, "Quettier", 8}};
	pthread_t threads[THREADS_COUNT];
	for (int i = 0; i < THREADS_COUNT; i++)
	{
		partage = threadArguments[i];
		pthread_create(&threads[i], NULL, thread, &partage);
	}
	for (int i = 0; i < THREADS_COUNT; i++)
	{
		pthread_join(threads[i], NULL);
	}
	return 0;
}

void *thread(void *arg)
{
	ThreadArguments *threadArguments = (ThreadArguments *)arg;
	cout << "Thread " << threadArguments->threadNumber << " : " << threadArguments->name << " (" << threadArguments->time << "s) started\n" << flush;
	const struct timespec time = {threadArguments->time, 0};
	nanosleep(&time, NULL);
	cout << "Thread " << threadArguments->threadNumber << " : " << threadArguments->name << " (" << threadArguments->time << "s) done\n" << flush;
	pthread_exit(NULL);
}
