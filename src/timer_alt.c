#include <time.h>
#include <sys/resource.h>

double get_time()
{
    struct timeval t;
    struct timezone tzp;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&t, &tzp);
    return t.tv_sec + t.tv_usec*1e-6;
}
