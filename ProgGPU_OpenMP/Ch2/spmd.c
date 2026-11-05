#include<stdio.h> 
#include<omp.h> 

static long num_steps = 1024*1024*1024;
int main()
{
	int numthreads;
	double pi, step, full_sum = 0.0;
	step = 1.0 / (double) num_steps;

	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		double x, partial_sum = 0.0;

	#pragma omp single
		numthreads = omp_get_num_threads();

		for (int i = id; i < num_steps; i += numthreads) {
			x = (i + 0.5) * step;
			partial_sum += 4.0 / (1.0 + x*x);
		}
		#pragma omp critical
			full_sum += partial_sum;
	}

	pi = step * full_sum;
	printf("\n pi is %f with %d threads \n" , pi, numthreads);
}

