/*

  Serial version of matrix completion code. 
	
*/


#include "matCompl.h"

int main(void){ 
 int nrows = 4;
 int ncols = 4;
 int rank = 2;
 double *A = test_mat(rank, nrows, ncols);
 double *B = alloc_array_z(nrows, ncols);
         
 //int i,j;

 /*for(i = 0; i < nrows;i++){
     for(j = 0; j < ncols;j++){
     	if(i == j){
     		A[map(i,j,ncols, 'n')] = 20.0;
     	}
     }
 }*/
 
print_mat(A,nrows, ncols);

 

 free_array(B);
 free_array(A); 
 return 0;
}
 
