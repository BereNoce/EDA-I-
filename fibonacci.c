
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int fib( int n ){
    size_t i, j; 
    if( n < 2 ){
        return n;
    } 
    else{
        #pragma omp task
        i = fib( n - 1 );
        
        #pragma omp task
        j = fib( n - 2 );
        
        #pragma omp taskwait
        return i + j;
    }
}

#define TAM 10
int main( ){
    size_t res;
    #pragma omo parallel
    {
        #pragma omp single
        res = fib( TAM );
    }
    
    printf( " Fibo(%d)=%ld\n", TAM, res);
}
