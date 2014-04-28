/*benchmark function takes in as arguments:
char method, // criteria: 'P' or 'S'
int nrows, int ncols,
int rank,	// criteria: <= min(nrows, ncols)
int ku, // criteria: < nrows*ncols. set to 3 initially
int omega_c[], // set to {0, 5, 7} initially; // places of unknown values.
int maxIter,
double tol,
char* file_out,
double tau, // = 1.5*nrows;
 double delta // = 1.4;
*/




void runBenchmark( char method, int nrows, int ncols, int rank,	int ku, int omega_c[], int kn, int omega[], int numIter, double tol, char* file_out, double tau, double delta, double* Y, double* Z, double* M, double* dummyMatrix, double* dummy2);