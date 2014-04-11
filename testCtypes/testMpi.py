# Testing running C  files parallelized with mpi from python

# To use, write 
# >> mpirun -np 4 python testMpi.py

from ctypes import cdll
from mpi4py import MPI

lib = cdll.LoadLibrary('./libhello.so');

lib.manyMatrixSuchMultiply();
