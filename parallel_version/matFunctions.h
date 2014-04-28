int map(int i, int j, int ncols, char transpose);

double* alloc_array(int nrows, int ncol);
double* alloc_array_z(int nrows, int ncol);

void free_array(double* A);
double* mm(double* A, int arows, int acols, char transA ,double* B, int brows, int bcols, char transB);
double* diag(double* A, int arows, int acols);
void print_mat(double* A, int nrows, int ncols);

void Proj(double *A, int* Omega, int kn, double* Z);
void Proj_sub(double *A, double *B, int* Omega, int kn, double* Z);

void ma(double* A, int arows, int acols, double ascalar, double* B, int brows, 
int bcols, double bscalar, int* omega, int kn, double* dummyMatrix);

void create_omega(int* omega_c, int ku, int* omega, int kn, int numElts);