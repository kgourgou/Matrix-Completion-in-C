#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



int map(int i, int j, int ncols, char transpose){
	if( transpose == 't' ){
		return j*ncols + i;
	}	
	else
	{
		return i*ncols + j;
	}
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

/*
int main(void) 
 {
	const int M=4, N=4, P=4;
	int A[M][N], int B[N][P], int C[M][P];
	for (int i = 0; i != M; ++i) 
	{
 		for (int j = 0; j != N; ++j)
		{
			int sum = 0;
			for (int k = 0; k != P; ++k)
			{
				sum += A[i][k] * B[k][j];
			}
			C[i][j] = sum;
		}
	}
	return 0;
 }
*/



double* mm(double* A, int arows, int acols, char transA, double* B, int brows, int bcols, char transB){
	double* C  = alloc_array(arows, bcols);
	double sum;
	int i;
	int j;
	int k;
	
	for( i = 0; i < arows; i++ ){
		for( j = 0; j < brows; j++ ){
			sum = 0;
			for( k = 0; k < bcols; k++ ){
				sum = sum + A[map(i, k, acols, transA)] * B[map(k, j, bcols, transB)];
			}	
			C[map(i, j, bcols, 'n')] = sum;
		}
	}
	return C;
}

double* diag(double* A, int arows, int acols){
	double* C  = alloc_array_z(arows, acols);
	int i;
	int j;
	
	for( i = 0; i < arows; i++){
		for( j = 0; j < acols; j++){
			if( i == j ){
				C[map(i, j, acols, 'n')] = A[i];
			}
		}
	}
	return C;
}


double* ma(double* A, int arows, int acols, double ascalar, double* B, int brows, int bcols, double bscalar, int* omega, int kn){
	double* C = alloc_array_z(arows, acols);
	int i;
	
	for( i = 0; i < kn; i++){
		C[omega[i]] = ascalar*A[omega[i]] + bscalar*B[omega[i]];
	}
	return C;
}







void print_mat(double* A, int nrows, int ncols){
/*
 * Prints an nrows x ncols array as a matrix.
 *
 * */
int i,j;

 for(i = 0;i < nrows;i++){
   for(j = 0;j < ncols;j++){
     printf("%1.5f ",A[map(i,j,ncols, 'n')]);
   }
   printf("\n");
 }
   printf("\n");
}
