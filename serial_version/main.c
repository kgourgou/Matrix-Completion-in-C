/*

  Serial version of matrix completion code. 
	
*/


#include "matCompl.h"

int main(void){ 
 int nrows = 2;
 int ncols = 2;
 int rank = 3;
 double *A = test_mat(rank, nrows, ncols);
 double *B = alloc_array_z(nrows, ncols);
 //double *B = test_mat(rank, nrows, ncols);

         
 int i,j;

 /*for(i = 0; i < nrows;i++){
     for(j = 0; j < ncols;j++){
     	if(i == j){
     		B[map(i,j,ncols, 'n')] = 20.0;
     	}
     }
 }
 
 A[1] = 2.0;
 */

 B[map(0,0,2,'n')] = 1;
 B[map(0,1,2,'n')] = 0;
 
 print_mat(mm(A, nrows, ncols, A, nrows, ncols),nrows, ncols);
 

 //print_mat(B, nrows, ncols);
 //print_mat(mm(B, nrows, ncols, A, nrows, ncols),nrows, ncols);
 
 //print_mat(A, nrows, ncols);

 
 B = shrink(B, 0.0, nrows, ncols);
 
 print_mat(B, nrows, ncols);
 

 free_array(B);
 free_array(A); 
 return 0;
}
 
