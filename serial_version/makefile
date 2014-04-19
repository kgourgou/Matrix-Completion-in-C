# K.G
# kgourgou@umass.edu

cc = gcc

flags =  -Wall  

# *.h files
dep = matCompl.h matFunctions.h

# For every *.c file, put the corresponding *.o file here.
objects = main.o  matFunctions.o RMSE.o test_mat.o



# Path to objects
obj_dir = obj
OBJ = $(patsubst %, $(obj_dir)/%,$(objects))

a.out : $(OBJ) 
	$(cc) $(flags) $(OBJ) -lm -llapack 
        

$(obj_dir)/%.o : %.c $(dep)
	$(cc) $(flags) -c $< -o $@  
 

# Clean all object files from everywhere.
clean :
	rm -f $(obj_dir)/*.o *.o



