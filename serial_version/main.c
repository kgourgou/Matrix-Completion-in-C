/*

  Serial version of matrix completion code. 
	
*/

#include "matCompl.h"

int main(void){ 
 int nrows = 4;
 int ncols = 4;
 int rank = 2;
         

 int numIter = 100;
 int i,j;
 double tau = 1.5*nrows;
 double delta = 1.4;
 
 int omega_c[] = {0}; // places of unknown values.
 int omega[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; // places of known values.

 int ku = 1; // Number of unknown values.
 int kn = (nrows*ncols)-ku; // Number of known values.
 
 double *M = test_mat(rank, nrows, ncols);
 double *Y = alloc_array_z(nrows, ncols);
 double *Z = alloc_array(nrows, ncols);
 double *dummyMatrix = alloc_array_z(nrows, ncols);
 double *dummy2 = alloc_array_z(nrows,ncols);


 for( i = 0; i < numIter; i++){
 
    for(j=0; j <  ncols*nrows;j++){
        dummy2[j] = Y[j];
    }

    Z = shrink(dummy2, tau, nrows, ncols);

    Proj_sub(M, Z, omega, kn, dummyMatrix);

 	Y = ma(Y, ncols, nrows, 1.0, dummyMatrix, ncols, nrows, delta, omega, kn);
 }
 
 printf("Error = %f\n\n", RMSE2(M, Z, omega_c, ku));
 printf("Known value = %f\n", M[0]);
 printf("Approximation = %f\n", Z[0]);

 free_array(Y);
 free_array(M); 
 free_array(dummy2);
 free_array(Z);
 free_array(dummyMatrix);
 return 0;
}
 

