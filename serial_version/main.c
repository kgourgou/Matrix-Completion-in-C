/*

  Serial version of matrix completion code. 
	
*/


#include "matCompl.h"

int main(void){ 
 int nrows = 4;
 int ncols = 4;
 int rank = 3;
 double *A = test_mat(rank, nrows, ncols);
 double *B = test_mat(rank, nrows, ncols);
         
 int i,j;

 for(i = 0; i < nrows;i++){
     for(j = 0; j < ncols;j++){
        A[map(i,j,ncols)] = i+j;
     }
 }
 


 free_array(B);
 free_array(A); 
 return 0;
}
 
