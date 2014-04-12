# K.G
# kgourgou@umass.edu

cc = gcc

flags = -O3 -Wall  

# Add the rest of the objects here

dep = matCompl.h matFunctions.h
objects = main.o test_mat.o matFunctions.o RMSE.o



# Path to objects

obj_dir = obj
OBJ = $(patsubst %, $(obj_dir)/%,$(objects))

a.out : $(OBJ) 
	$(cc) $(flags) $(OBJ) 
        

$(obj_dir)/%.o : %.c $(dep)
	$(cc) $(flags) -c $< -o $@ -lm 
 

clean :
	rm -f $(obj_dir)/*.o *.o
