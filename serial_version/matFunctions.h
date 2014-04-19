int map(int i, int j, int ncols);

double* alloc_array(int nrows, int ncol);
double* alloc_array_z(int nrows, int ncol);

void free_array(double* A);
void print_mat(double* A, int nrows, int ncols);
