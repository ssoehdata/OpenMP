#include<stdio.h>
#include<omp.h> 
static long num_steps = 1024*1024*1024;

int main() 
{
	double x, pi, step, sum = 0.0;
	step = 1.0 / (double) num_steps;
	
	for (int i; i < num_steps; i++) {

		x = (i + 0.5) * step;
		sum += 4.0 / (1.0 + x * x);
	}
	
	pi = step * sum;
	printf("pi = %lf , with ld steps\n ", pi, num_steps);
}

