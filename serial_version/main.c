/*

  Serial version of matrix completion code. 
	
*/

#include<stdio.h>
#include<stdlib.h>

extern double **alloc_array(int rows, int col);

int main(void){ 
 double **A = alloc_array(3,3);


 return 0;

}


double** alloc_array(int nrows, int ncol){

 int i,j;
 double **A = (int**) (malloc(rows* sizeof(*double)));

 for( i = 0; i <  rows; i++){
  *(A[i]) = (malloc(ncol * sizeof(double)));
 }

 return A;
}


void free_array(double** A, int nrows){
 int i;

 for(i = 0; i < nrows; i++){
  free(A[i]);
 }

 free(A);
 return 0;

}
