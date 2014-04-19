#include "matCompl.h"

/*
 shrink(double** A, double t, int M) applies the shrink operator on A with thresholding parameter t. 
 
 The idea is to compute the SVD of A, A=U*S*V, then create the matrix B

     B = U * S2 * V, 

     where S2_{i,i} = S_{i,i} if ((S_{i,i}-)*t>0) and 
           S2_{i,i} = 0 otherwise.
   
    Then it returns B.

*/
double* shrink(double* A, double tau, int nrows, int ncols){
	
	
	
	
}