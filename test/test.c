#include <stdio.h>
#include <pthread.h>

// 新しいスレッドで実行されるタスク
void *doSomething(void* pArg) {
    int *pVal = (int*) pArg;
    printf("worker thread [%d]\n", *pVal);
    *pVal = 200;
}

// 新しいスレッドで実行されるタスク
void *doSomething2(void* pArg) {
    int *pVal = (int*) pArg;
    printf("worker thread [%d]\n", *pVal);
    *pVal = 200;
}

int main() {
    pthread_t handle;  // Thread handle.
	pthread_t handle2;  // Thread handle.
    int data = 100;
	int i = 0;

	while (i != 4)
	{
    	pthread_create(&handle, NULL, doSomething, &data);
		pthread_create(&handle2, NULL, doSomething2, &data);
    	pthread_join(handle, NULL);
		pthread_join(handle2, NULL);
		i++;
	}

    printf("main thread [%d]\n", data);
}