C and Python 
=============

In this folder, I wrote an example of the use of ctypes to use C and python code together.

## HOW-TO

C files have to be compiled as shared libraries as seen in the makefile of this folder. 

Then, they can be called from inside python by using ctypes. 

### Using MPI

If one or more of the C files use MPI, then we must also import **MPI** from **mpi4py** in our python file. If then our code
is called by the python script **test.py**, we can run it over mpi as, 

>> mpirun -np #numofthreads python test.py

where #numofthreads is the number of threads we want to use.

