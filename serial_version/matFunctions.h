int map(int i, int j, int ncols, char transpose);

double* alloc_array(int nrows, int ncol);
double* alloc_array_z(int nrows, int ncol);

void free_array(double* A);
double* mm(double* A, int arows, int acols, char transA ,double* B, int brows, int bcols, char transB);
double* diag(double* A, int arows, int acols);
void print_mat(double* A, int nrows, int ncols);