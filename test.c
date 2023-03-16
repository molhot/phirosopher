# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>
# include <sys/types.h>
# include <stddef.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

int	num;
pthread_mutex_t		hoge;
pthread_mutex_t		huga;

void	*sum(void *p)
{
	int i;

	i = 0;
	while (i != 10000)
	{
		pthread_mutex_lock(&hoge);
		num++;
		pthread_mutex_unlock(&hoge);
		i++;
	}
	return (NULL);
}

int main()
{
	num = 0;
	size_t		i;
	size_t		j;
	pthread_t	threads;

	i = 0;
	j = 0;
	pthread_mutex_init(&(hoge), NULL);
	pthread_mutex_init(&(huga), NULL);
	while (i != 10000)
	{
		pthread_create(&threads, NULL, &sum, NULL);
		while (j != 10000)
		{
			j++;
			pthread_mutex_lock(&hoge);
			num++;
			pthread_mutex_unlock(&hoge);
		}
		pthread_join(threads, NULL);
		j = 0;
		i++;
	}
	printf("%d\n", num);
}

// #include <stdio.h>

// void swap(const int *a, const int *b)
// {
//     int tmp = *(int *)a;
//     *(int *)a = *b;
//     *(int *)b = tmp;
// }

// int main()
// {
//     const int a = 1;
//     const int b = 2;

//     printf("%d %d\n", a, b);
//     swap(&a, &b);
//     printf("%d %d\n", a, b);
//     printf("%d %d\n", *(&a), *(&b));
// }

// #include <stdio.h>

// int sum(int a, int b) { return a + b; }

// int fff(int a, int b, int c, int d, int e, int f) { f = 0; return a + b + c + d + e + f; }

// int main(void) {
//   int (*f)(int, int);

//   {
//     f = sum;
//     int ret = f(1, 2);
//     printf("ret %d\n", ret);
//   }
//   {
//     f = (void*)fff;
// 	long l = 0;
//     int ret = f(1, 2);
//     printf("ret %d\n", ret);
//   }
// }