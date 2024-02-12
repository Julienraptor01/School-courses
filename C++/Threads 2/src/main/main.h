#ifndef MAIN_H
#define MAIN_H

#define NUMBER_OF_THREADS 4

typedef struct
{
	int threadNumber;
} ThreadArguments;

typedef struct
{
} ThreadResults;

void handlerSIGINT(int);
void handlerSIGUSR1(int);

int main();
void *master(void *arg);
void *slave(void *arg);

#endif
