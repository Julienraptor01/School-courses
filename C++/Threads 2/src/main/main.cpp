#include "main.h"

#include <csignal>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::flush;
using std::string;
using std::to_string;

void handlerSIGINT(int i)
{
	string out = "SIGINT handler : thread id ";
	cout << out.append(to_string(pthread_self())).append(" - Received signal ").append(to_string(i)).append("\n") << flush;
	kill(getpid(), SIGUSR1);
}

void handlerSIGUSR1(int i)
{
	string out = "SIGUSR1 handler : thread id ";
	cout << out.append(to_string(pthread_self())).append(" - Received signal ").append(to_string(i)).append("\n") << flush;
}

int main()
{
	ThreadArguments threadArguments[NUMBER_OF_THREADS] = {{0}, {1}, {2}, {3}};
	pthread_t slaveThread[NUMBER_OF_THREADS], masterThread;

	struct sigaction action;
	sigset_t mask;
	action.sa_flags = 0;
	sigemptyset(&action.sa_mask);
	action.sa_handler = handlerSIGINT;
	sigaction(SIGINT, &action, NULL);
	action.sa_handler = handlerSIGUSR1;
	sigaction(SIGUSR1, &action, NULL);

	sigemptyset(&mask);
	sigaddset(&mask, SIGINT | SIGUSR1);
	sigprocmask(SIG_BLOCK, &mask, NULL);

	pthread_create(&masterThread, NULL, master, NULL);
	for (int i = 0; i < NUMBER_OF_THREADS; i++)
	{
		pthread_create(&slaveThread[i], NULL, slave, &threadArguments[i]);
	}

	string out = "main : thread id ";
	cout << out.append(to_string(pthread_self())).append(" - Waiting for signal\n") << flush;

	for (int i = 0; i < NUMBER_OF_THREADS; i++)
	{
		pthread_join(slaveThread[i], NULL);
	}

	pthread_cancel(masterThread);
	pthread_join(masterThread, NULL);

	out = "main : thread id ";
	cout << out.append(to_string(pthread_self())).append(" - Exiting\n") << flush;

	return 0;
}

void *master(void *arg)
{
	(void)arg; // avoid unused parameter warning
	pthread_cleanup_push([](void *arg)
						 {
							(void)arg;/* avoid unused parameter warning */
							string out = "master : thread id ";
							cout << out.append(to_string(pthread_self())).append(" - Exiting\n") << flush; },
						 NULL);
	sigset_t mask;
	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);
	sigprocmask(SIG_UNBLOCK, &mask, NULL);
	string out = "master : thread id ";
	cout << out.append(to_string(pthread_self())).append(" - Waiting for signal\n") << flush;
	while (1)
	{
		pause();
	}
	pthread_cleanup_pop(1);
	pthread_exit(0);
}

void *slave(void *arg)
{
	ThreadArguments *threadArguments = (ThreadArguments *)arg;
	sigset_t mask;
	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
	sigprocmask(SIG_UNBLOCK, &mask, NULL);
	string out = "slave ";
	cout << out.append(to_string(threadArguments->threadNumber)).append(" : thread id ").append(to_string(pthread_self())).append(" - Waiting for signal\n") << flush;
	pause();
	pthread_exit(0);
}
