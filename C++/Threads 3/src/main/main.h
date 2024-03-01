#ifndef MAIN_H
#define MAIN_H

#include <string>

using std::string;

#define THREADS_COUNT 4

typedef struct
{
	int threadNumber;
	string name;
	int time;
} ThreadArguments;

typedef struct
{
} ThreadResults;

int main();
void *thread(void *arg);

#endif
