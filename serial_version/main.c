/*

  Serial version of matrix completion code. 
	
*/


#include "matCompl.h"

int main(void){ 
 int nrows = 2;
 int ncols = 2;
 int rank = 2;
         

 int numIter = 5;
 int i;
 
 
 double tau = 10.0;
 double delta = 1.9;
 
 int omega[] = {0, 1, 2};
 //int omegac[] = {3};
 int kn = 3;
 
 //double *M = test_mat(rank, nrows, ncols);
 double M[] = {1.0, 2.0, 2.0, 0.0};
 double *Y = alloc_array_z(nrows, ncols);
 double *Z = alloc_array(nrows, ncols);
 double *dummyMatrix = alloc_array_z(nrows, ncols);
 double *MummyDatrix = alloc_array_z(nrows, ncols);
 
 //print_mat(M, nrows, ncols);
 
 for( i = 0; i < numIter; i++){
 	Z = shrink(Y, tau, nrows, ncols);
 	Proj_sub(M, Z, omega, kn, dummyMatrix);
 	ma(Y, ncols, nrows, 1.0, dummyMatrix, ncols, nrows, delta, omega, kn, MummyDatrix);
 	Y = MummyDatrix;
 	print_mat(Y, nrows, ncols);
 }
 
// print_mat(Z, nrows, ncols);
 
printf("\n%f\n", RMSE2(M, Z, omega, kn));





 free_array(Y);
 //free_array(M); 
 free_array(Z);
 free_array(dummyMatrix);
 return 0;
}
 
