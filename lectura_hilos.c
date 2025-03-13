
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void funcA( size_t num ){
    for( size_t i = 0; i < num; ++i ){
        printf(" Holi desde el hilo %d\n", omp_get_thread_num());
    }
}

void funcB( size_t num ){
    size_t i = num;
    while( i > 0 ){
        printf( "Hello ");
        printf( "from thread ");
        printf( "%d\n", omp_get_thread_num());
        --i;
    }
}

void funcC(){
    printf( "holaaa( %d )\n", omp_get_thread_num());
}

int main(){
    size_t i = 3; 
    size_t j = 4;
    
    #pragma omp parallel shared( i, j )
    {
        #pragma omp sections
        {
            #pragma omp section
            funcA( i );
            
            #pragma omp section
            funcB( j );
            
            #pragma omp section
            funcC();
            
            #pragma omp section
            {
                for( size_t i = 0; i < 3; ++i ){
                    printf( "HOLA DESDE EL HILO: %d\n", omp_get_thread_num() );
                }
            }
        }
    }
}
