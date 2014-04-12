#include<stdio.h>
#include<stdlib.h>

double** alloc_array(int nrows, int ncol){

 int i;
 double** A = (double**) (malloc(nrows* sizeof(double*)));

 for( i = 0; i <  nrows; i++){
  *(A+i) = ((double*) malloc(ncol * sizeof(double)));
 }

 return A;
}


void free_array(double** A, int nrows){
 int i;

 for(i = 0; i < nrows; i++){
  free(A[i]);
 }

 free(A);
}

void print_mat(double** A, int nrows, int ncols){

int i,j;

 for(i = 0;i < nrows;i++){
   for(j = 0;j < ncols;j++){
    printf("%1.3f ",A[i][j]);
   }
   printf("\n");
 }

}
