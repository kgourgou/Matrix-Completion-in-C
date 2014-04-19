#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int map(int i, int j, int ncols){
	return i*ncols + j;
}

double* alloc_array(int nrows, int ncol){

    /*
     *  
     * Allocates an nrows x ncols matrix.  
     *
     * */

  double* A = NULL;
  A =  (double*) (malloc(nrows * ncol * sizeof(double*)));
  assert(A);

  return A;

}


double* alloc_array_z(int nrows, int ncol){

    /*
     *  
     * Allocates an nrows x ncols matrix with 0.  
     *
     * */

  double* A = NULL;
  int i;

  A =  (double*) (malloc(nrows * ncol * sizeof(double*)));
  assert(A);
  
  for(i=0;i < ncol*nrows;i++){
    A[i] = 0.0;
  }


  return A;

}

void free_array(double* A){
/*
 * Frees an array created by alloc_array.
 *
 * */
    
 free(A);
}

void print_mat(double* A, int nrows, int ncols){
/*
 * Prints an nrows x ncols array as a matrix.
 *
 * */
int i,j;

 for(i = 0;i < nrows;i++){
   for(j = 0;j < ncols;j++){
     printf("%1.3f ",A[map(i,j,ncols)]);
   }
   printf("\n");
 }

}
