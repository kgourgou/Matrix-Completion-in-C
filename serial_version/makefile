# K.G
# kgourgou@umass.edu

cc = gcc

flags = -O3 -Wall  

# Add the rest of the objects here

dep = matCompl.h matFunctions.h
objects = main.o  matFunctions.o RMSE.o test_mat.o



# Path to objects

obj_dir = obj
OBJ = $(patsubst %, $(obj_dir)/%,$(objects))

a.out : $(OBJ) 
	$(cc) $(flags) $(OBJ) -lm 
        

$(obj_dir)/%.o : %.c $(dep)
	$(cc) $(flags) -c $< -o $@  
 

clean :
	rm -f $(obj_dir)/*.o *.o
