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


double* mm(double* A, int arows, int acols, char transA, double* B, int brows, int bcols, char transB){

    /*
     *  
     * matrix multiply A(arows x acols) by B(brows x bcols) with the option to transpose
     * A and/or B before performing the operation  
     *
     * */

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

    /*
     *  
     * creates a diagonal matrix from a vector A.
     *
     * */

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


void ma(double* A, int arows, int acols, double ascalar, double* B, int brows, int bcols, double bscalar, int* omega, int kn, double* dummyMatrix){

	/* 
	 * 
	 * matrix add the omega set of elements of A and B
	* */
	//double* C = alloc_array_z(arows, acols);
	int i;
	
	for( i = 0; i < kn; i++){
		dummyMatrix[omega[i]] = ascalar*A[omega[i]] + bscalar*B[omega[i]];
	}
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


/* takes in SORTED omega_c and ku and outputs SORTED omega and kn */
void create_omega(int* omega_c, int ku, int* omega, int kn, int numElts){
	kn = numElts - ku;
	int iter, c_iter;
	int candidate_index;
 
    c_iter = 0;
    iter = 0;

	for( candidate_index = 0; candidate_index < numElts; candidate_index++){
		if(  c_iter < ku && omega_c[c_iter] == candidate_index){
			c_iter++;
		}
		else{
			omega[iter] = candidate_index;
			iter++;
		}
	}
}
