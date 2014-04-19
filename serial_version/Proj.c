
#include<stdio.h>
#include<assert.h>

/*
 *
 *  Projection operators for matrix completion.
 *
 *
 * */


void Proj(double *A, int* Omega, int kn, double* Z){

    /*
     * Proj applies a projection on the space of known elements of A. 
     *
     * If Z = Proj(A,Omega), then Z(i,j)=A(i,j) for any (i,j) in Omega and 
     * Z(i,j) = 0 otherwise.
     *
     * Arguments
     * =========
     *  * A : (double*) array that represents a 2D matrix of size n x m. 
     *  
     *  * Omega : (int*) array of the known indices of A. Note that those
     *  are linear indices that need to be mapped before using. In other words, 
     *  (i,j) <-> i*nrows + j 
     *  
     *  * N : (int) Number of known values, size of Omega.
     *
     *
     *  * Z : (double*) Carries the result of the projection. Should have same size with A
     *  and be initialized with ZEROS.
     *  * 
     * */

    assert(Z);

     int i;
     for(i = 0;i < kn;i++){
        Z[Omega[i]] = A[Omega[i]];
     }

}

void Proj_sub(double *A, double *B, int* Omega, int kn, double* Z){

    /*
     * Calculates Z <- A-B over Omega.
     *  
     *  Z is assumed to be initialized with zeros and must be allocated outside Z
     * */

    assert(Z);
    
    int i;
    for(i = 0; i < kn; i++){
        Z[Omega[i]] = A[Omega[i]] - B[Omega[i]];
    }

}

