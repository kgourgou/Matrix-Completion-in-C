#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*
 *
 *
 * */

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


/*
 *
 * Don't really need this now.
 *
 * */

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
    printf("%1.3f ",A[i]);
   }
   printf("\n");
 }

}
