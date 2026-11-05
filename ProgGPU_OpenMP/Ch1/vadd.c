/*
 *	Fig 1.3 
 *
 */
#include <stdio.h>
#include <assert.h>
#define N 4000

void init(double *A, double *B, double *C);

int main() {
	
	double A[N], B[N], C[N];

	for (int i=0; i<N; i=i++) {
		  C[ i ] = A[ i ] + B[ i ]; 
          C[i+1] = A[i+1] + B[i+1]; 
          C[i+2] = A[i+2] + B[i+2]; 
          C[i+3] = A[i+3] + B[i+3];
	}

	// test 
	int nerr = 0;
	for (int i=0; i<N; i++) {
		if((int)C[i] !=3*i+1) nerr++;
	}
	printf("Program complete with %d errors",nerr);
}
// initialize arrays 
void init (double *A, double*B,   double *C){

      for (int i=0; i<N; i++) { 
          A[i] = (double)  i; 
          B[i] =  (double) 2*i; 
          C[i] = 1.0; 
       }

}
