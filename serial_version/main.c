/*

  Serial version of matrix completion code. 
	
*/

#include "matCompl.h"

int main(void){ 
 int nrows = 2;
 int ncols = 2;
 int rank = 1;
         

 int numIter = 5;
 int i;

 double tau = 1.2*nrows;
 double delta = 1.4;
 
 int omega_c[] = {0}; // places of unknown values.
 int omega[] = {1,2,3}; // places of known values.

 int ku = 1; // Number of unknown values.
 int kn = (nrows*ncols)-ku; // Number of known values.

 
 //double *M = test_mat(rank, nrows, ncols);
 double M[] = {1.0, 2.0, 2.0, 0.0};
 double *Y = alloc_array_z(nrows, ncols);
 double *Z = alloc_array(nrows, ncols);
 double *dummyMatrix = alloc_array_z(nrows, ncols);
 double *MummyDatrix = alloc_array_z(nrows, ncols);
 double *Y_saved = alloc_array_z(nrows, ncols); 

 printf("Original matrix = \n");
 print_mat(M, nrows, ncols);
 

 for( i = 0; i < numIter; i++){
 dummyMatrix = alloc_array_z(nrows, ncols);
 MummyDatrix = alloc_array_z(nrows, ncols);

 	Z = shrink(Y, tau, nrows, ncols);
 	Proj_sub(M, Z, omega, kn, dummyMatrix);
 	ma(Y_saved, ncols, nrows, 1.0, dummyMatrix, ncols, nrows, delta, omega, kn, MummyDatrix);
 	Y = MummyDatrix;
 }
 printf("Error = %f\n\n", RMSE2(M, Z, omega_c, ku));


 printf("M =\n ");
 print_mat(M,nrows,ncols);
 
 printf("Z =\n ");
 print_mat(Z,nrows,ncols);

 free_array(Y);
 //free_array(M); 
 free_array(Z);
 free_array(dummyMatrix);
 return 0;
}
 
