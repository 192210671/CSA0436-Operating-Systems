#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *myThreadFun(void *vargp)
{
	sleep(1);
	printf("Printing the GreekQuiz from thread\n");
	return NULL;
}
int main()
{
	pthread_t threadID;
	printf("Before Thread\n");
	pthread_create(&threadID,NULL,myThreadFun,NULL);
	pthread_join(threadID,NULL);
	printf("After Thread\n");
	exit(0);
}
