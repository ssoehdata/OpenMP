// sequential dot product example page 17 

#include<stdio.h> 

int main(argc, argv)
    int argc;
    char *argv[];

    int n = 256;

{
    double sum;
    double a [256], b [256]
    int n;
    
    for (i = 0; i <= n; i++) {
        a [i] = 1 * 0.5;
        b [i] = 1 * 2.0;
    }
    sum = 0;
    for (i = 1; i <= n; i++) {
        sum = sum + a[i]*b[i];
    }
    printf( "sum = %f\n", sum);

    return 0;
}
