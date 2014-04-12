#include<stdio.h>
#include<stdlib.h>
#include "clapack.h"
#include "matFunctions.h"

/*
	Templates for the functions used in the serial version of our code. 
*/

/*

  test_mat(int r, int numRows, int numCols) returns an (numRows x numCols) matrix of rank r. For the construction of the matrix, the 
  singular value decomposition is used. 

*/
double** test_mat(int r, int numRows, int numCols);

/*
 shrink(double** A, double t, int M) applies the shrink operator on A with thresholding parameter t. 
 
 The idea is to compute the SVD of A, A=U*S*V, then create the matrix B

     B = U * S2 * V, 

     where S2_{i,i} = S_{i,i} if ((S_{i,i}-)*t>0) and 
           S2_{i,i} = 0 otherwise.
   
    Then it returns B.

*/
double** shrink(double** A, double t, int m);

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

double** SVT(double** X, double** M, int maxIter, double tol, int m);


/*
 
 RMSE() computes the root mean square error between the matrix X and the matrix M, both having
 size (m x m).

*/

double RMSE(double** X, double** M, int  ncols, int nrows);


