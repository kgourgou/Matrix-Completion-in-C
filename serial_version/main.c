/*

  Serial version of matrix completion code. 
	
*/


#include "matCompl.h"

int main(void){ 
 int nrows = 4;
 int ncols = 4;
 int rank = 3;
 double *A = alloc_array_z(nrows, ncols);
 double *B = test_mat(rank, nrows, ncols);
         
 int i,j;

 for(i = 0; i < nrows;i++){
     for(j = 0; j < ncols;j++){
     	if(i == j){
     		A[map(i,j,ncols)] = 1;
     	}
     }
 }
 
 A[1] = 2.0;
 
 print_mat(mm(A, nrows, ncols, A, nrows, ncols),nrows, ncols);
 


 print_mat(A, nrows, ncols);
 
 A = shrink(A, 0.0, nrows, ncols);
 
 print_mat(A, nrows, ncols);
 

 free_array(B);
 free_array(A); 
 return 0;
}
 
