/*

  Serial version of matrix completion code. 
	
*/


#include "matCompl.h"

int main(void){ 
 int nrows = 4;
 int ncols = 5;
 int rank = 3;
 double **A = test_mat(rank, nrows, ncols);
 double **B = test_mat(rank, nrows, ncols);
         
 int i,j;

 for(i = 0; i < nrows;i++){
     for(j = 0; j < ncols;j++){
        A[i][j] = i+j;
     }
 }

printf("%i\n",MAP(0,0,4));
 
 free_array(B,nrows);
 free_array(A,nrows); 
 return 0;
}
 
