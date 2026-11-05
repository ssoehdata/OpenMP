#include<stdio.h>
#include<omp.h>
static long num_steps = 100000000;
int main( )
{
    double x, pi, step, sum = 0.0;
    int numthreads;
    step = 1.0 / (double) num_steps;

	#pragma omp parallel
    {
        #pragma omp single
            numthreads = omp_get_num_threads();
        
        #pragma omp for private(x) reduction(+:sum)
            for (int i = 0; i < num_steps; i++) {
                x = (i + 0.5) * step;
                sum = sum + 4.0 / (1.0 + x*x);
        }
    }
    
    pi = step * sum;
    printf("\n pi is %f with %d threads\n", pi, numthreads);
    
}

