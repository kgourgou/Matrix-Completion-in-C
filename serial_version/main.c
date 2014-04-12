/*

  Serial version of matrix completion code. 
	
*/


#include "matCompl.h"

int main(void){ 
 double **A = alloc_array(3,3);
 int i,j;
 
 for(i = 0;i < 3; i++){
  for(j = 0;j<3; j++){
    A[i][j] = (i+j);
  }
 }

 for(i = 0;i < 3;i++){
  for(j = 0;j < 3;j++){
   printf("%f ",A[i][j]);
  }
  printf("\n");
 }

 
 free_array(A,3); 
 return 0;

}
