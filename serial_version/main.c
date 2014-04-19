/*

  Serial version of matrix completion code. 
	
*/


#include "matCompl.h"

int main(void){ 
 int nrows = 4;
 int ncols = 4;
 int rank = 3;
 double *A = test_mat(rank, nrows, ncols);
 double *B = alloc_array_z(nrows, ncols);
 //double *B = test_mat(rank, nrows, ncols);

         
 int i,j;

 for(i = 0; i < nrows;i++){
     for(j = 0; j < ncols;j++){
     	if(i == j){
     		B[map(i,j,ncols, 'n')] = 20.0;
     	}
     }
 }
 
 //A[0] = 2.0;
 //A[1] = 1.0;
 //A[4] = 1.0;
 

 print_mat(B, nrows, ncols);
 //print_mat(mm(B, nrows, ncols, A, nrows, ncols),nrows, ncols);
 
 //print_mat(A, nrows, ncols);

 
 B = shrink(B, 0.0, nrows, ncols);
 
 print_mat(B, nrows, ncols);
 

 free_array(B);
 free_array(A); 
 return 0;
}
 
