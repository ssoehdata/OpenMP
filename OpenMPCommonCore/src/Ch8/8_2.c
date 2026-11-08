/* 	
 *  Fig. 8.2  page 148
 *	 A program with a race condition - A relaxed memory model permits
 *	 the assertionto fail i.e., the thread with id == 1 can observe
 *	 values in memory such that r == 1 while x is still 0.  
 */ 

#include<omp.h>
#include<assert.h>
#include<stdlib.h>

int main()
{
	int x = 0, y = 0, r = 0;
	omp_set_num_threads(2); 	// request two threads
    #pragma omp parallel
	{	
		int id = omp_get_thread_num();
		#pragma omp single
		{
			int nthrds = omp_get_num_threads();

		// verify that we have at least two threads
	   	   if (nthrds < 2) exit(1);
		} // end of single region
			
	    if (id == 0) {
		 x = 1;
		 r = x;
	 }	 
	 else if (id == 1) {
		 if (r == 1) {
			 y=x;
			 assert (y == 1); // Assertion will occasionally fall;
         }							  // i.e., r == 1 while x == 0
	 }
   } // end of parallel regions
	
}





