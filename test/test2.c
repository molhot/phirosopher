#include <stdio.h>
#include <pthread.h>
#include "philosophers.h"

void* thread_function(test_t *test)
{
	test->test = test->test + 1;
  	printf("%c\n", test->test);
  	return NULL;
}

int main(void)
{
  pthread_t threads[3];
  pthread_attr_t attr;
  int i = 0;
  test_t *tester;
  int ret;
  void (*testfunc)(test_t);

  tester = (test_t *)malloc(sizeof(test_t)*1);
  testfunc = thread_function(tester);
  tester->test = 97;
  ret = pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
  while (i < 3)
  {
    // スレッドを立てる
    if (pthread_create(&threads[i], NULL, &testfunc, tester) != 0) {
      break ;
    }

    i++;
  }

  i = 0;
  while (i < 3) {
    // スレッドが終了するのを待つ
    pthread_join(threads[i], NULL);
	usleep(1000);
    i++;
  }

  return 0;
}