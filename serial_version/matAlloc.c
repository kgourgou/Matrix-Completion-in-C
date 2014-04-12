#include<stdio.h>
#include<stdlib.h>

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

