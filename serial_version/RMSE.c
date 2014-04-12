#include "matCompl.h"
#include <math.h>

/*
 
 RMSE() computes the root mean square error between the matrix X and the matrix M, both having
 size (ncols x nrows).

*/

double RMSE(double** X, double** M, int  ncols, int nrows){
/*
  General version of RMSE. 
*/

 int i,j;
 double error = 0.0;

 for(i = 0; i < nrows; i++){
  for(j = 0;j < ncols; j++){
   
#   error += pow((X[i][j]-M[i][j]),2); 
  }
 }	

 return sqrt(error/(nrows*ncols));
	
}
