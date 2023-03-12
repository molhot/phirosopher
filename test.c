#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("%ld %u\n", tv.tv_sec, tv.tv_usec);
}