#include "matCompl.h"

/*
 
 RMSE() computes the root mean square error between the matrix X and the matrix M, both having
 size (ncols x nrows).

*/



double RMSE(double* X, double* M, int  ncols, int nrows){
/*
  General version of RMSE. 

  Note that this version is terribly inefficient for what we want to do. 

*/

 int i,j;
 double error = 0.0;

 for(i = 0; i < nrows; i++){
  for(j = 0;j < ncols; j++){
   
   error += pow((X[map(i,j,ncols, 'n')]-M[map(i,j,ncols, 'n')]),2.0); 

  }
 }	

 return sqrt(error/(nrows*ncols));
	
}

/*
 *
 * Another version of RMSE should be added here that calculates the RMSE for only the 
 * unknown elements.
 *
 * A possible definition could be : 
 *
 * double RMSE2(double* X, double *M, int * omega, int kn)
 *
 * * */

double RMSE2(double* X, double* M, int* omega, int kn){
  /*
   * Root mean square error over the unknown elements of M. 
   * omega has the indices of the unknown elements.
   * kn is the number of unknown elements.
   *
   * */
     
    int i;
	 double error = 0.0;

 	for(i = 0; i < kn; i++){   
   		error += pow((X[omega[i]]-M[omega[i]]),2.0); 
 	}	

 return sqrt(error/kn);
}







