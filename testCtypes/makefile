# Makefile for the libhello library
# Short demo for connecting python with C
# KG

libhello.so: hello.c makefile
	mpicc -c -fPIC hello.c -o hello.o
	mpicc -shared -o libhello.so hello.o

