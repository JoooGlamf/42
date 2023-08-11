#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

void	*funcio(void *data)
{
	printf("Thread create %s\n", (char *)data);
	return (0);
}

int main()
{
	pthread_t		thread1;
	pthread_t		thread2;
	pthread_mutex_t	*mutex;
	char			*data = "threaad12";
	
	pthread_create(&thread1, NULL, funcio, (void *)data);
	pthread_create(&thread2, NULL, funcio, (void *)data);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
}
