#include <iostream>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 3

void* PrintHi(void* id)
{
	long td;
	td = (long)id;
	cout << "ThreadID: " << id << endl;
	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[NUM_THREADS];
	int rc;
	
	for(int i = 0; i < NUM_THREADS; ++i)
	{
		cout << "Creating thread #" << i << endl;
		rc = pthread_create(&threads[i], NULL, PrintHi, (void*)i);
		
		if(rc)
		{
			cout << "Cannot create the thread" << endl;
			return -1;
		}
	}
	
	pthread_exit(NULL);
	return 0;
}