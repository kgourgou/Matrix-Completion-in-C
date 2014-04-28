#include "matCompl.h"

/*

 SVT() uses the shrink operator to complete the matrix of numbers M.
 The format of the arguments is now described. 

 Arguments
 ---------
 X : (double**) X is the matrix which will at the end hold the completion of the matrix M. It should
     have zeros in the places of the unknown elements and should be equal to the test matrix
     M everywhere else. 
 M : (double**) The test matrix. Should be completed and used as a benchmark so that we can assess
     convergence of the algorithm. 
 
 maxIter : (int)  Maximum number of steps the iterative method should do. This is the worst case scenario 
           for the algorithm. 
 
 tol : (double) Tolerance under which the method should stop. Controls the relative error during the run.

 M : Size of the matrices (assumed square for now). 

*/

double* SVT(double* X, double* M, int maxIter, double tol, int M){
	
	
	
	
}