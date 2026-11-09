/*
	Fig 7.15 page 142
		Parallel Pi program using tasks.
			Accomplished with the divide and conquer
			pattern by splitting the problem into two 
			subtasks to calculate sum1 and sum2, recursively
			solving each task, and then combining the results.
*/

#include<stdio.h> 
static long num_steps = 1024*1024*1024;
#define MIN_BLK 1024*256
double pi_comp(int Nstart, int Nfinish, double step)
{
	int i, iblk;
	double x, sum = 0.0, sum1, sum2;
	if (Nfinish - Nstart < MIN_BLK){
		for (i = Nstart; i < Nfinish; i++){
			x = (i + 0.5) * step;
			sum += 4.0 / (1.0 + x*x);
		}
	}
    else {
		iblk = Nfinish - Nstart;
	#pragma omp task shared(sum1)
		sum1 = pi_comp(Nstart, Nfinish - iblk/2, step);
	#pragma omp task shared(sum2)
		sum2 = pi_comp(Nfinish - iblk/2, Nfinish, step);
	#pragma omp taskwait
		sum = sum1 + sum2;
	}
return sum;
}

int main()
{
	int i;
	double step, pi, sum;
	step = 1.0 / (double) num_steps;
	#pragma omp  parallel
	{
    #pragma omp parallel
		sum = pi_comp(0, num_steps, step);
	}
	pi = step * sum;
}
