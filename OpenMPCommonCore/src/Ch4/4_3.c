/* 
 *	Fig. 4.3 page 55
 *	Library routines to manage threads
 *		- this program shows how to set the default number of
 *		  threads to request in parallel regions, query the number
 *		  of threads in a team, and set a unique thread ID.
 *		  N.B.: Note the care takent to avoid a data race when
 *		  assigning to size_of_team
 */

#include<stdio.h> 
#include<omp.h> 

int main() 
{
	omp_set_num_threads(4);
	int size_of_team;
	#pragma omp parallel
	{
		int ID = omp_get_thread_num();
		int NThrds = omp_get_num_threads();
	} // end of parallel region
	printf("We just did the join on a team of size \%d", size_of_team);
}


