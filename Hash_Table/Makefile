EXECUTABLE := Hashmap

SOURCES := *.cpp

INCLUDES := -I .
EXT := out
CC := g++

# -Wall checks for any warnings
CFLAGS  := -g -Wall

# typing 'make' will invoke the first target entry in the file
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
default: $(EXECUTABLE)

# To create the executable file count we need the object files
# TreeNode.o, BST.o, hashmap.o, and main.o:
$(EXECUTABLE):  TreeNode.o BST.o hashmap.o main.o 
	$(CC) $(CFLAGS) -o $(EXECUTABLE)  hashmap.o TreeNode.o BST.o main.o

# To create the object file hashmap.o, we need the source files
# hashmap.cpp and hashmap.h:
hashmap.o:  hashmap.cpp hashmap.h
	$(CC) $(CFLAGS) -c hashmap.cpp
	
# To create the object file TreeNode.o, we need the source files
# TreeNode.cpp and TreeNode.h:
TreeNode.o:  TreeNode.cpp TreeNode.h
	$(CC) $(CFLAGS) -c TreeNode.cpp

# To create the object file BST.o, we need the source files
# BST.cpp and BST.h:
BST.o:  BST.cpp BST.h
	$(CC) $(CFLAGS) -c BST.cpp

# To create the object file main.o, we need the source files
# main.cpp, TreeNode.cpp, TreeNode.h, BST.cpp, BST.h, hashmap.cpp, and hashmap.h:
main.o: main.cpp TreeNode.cpp TreeNode.h BST.cpp BST.h hashmap.cpp hashmap.h
	$(CC) $(CFLAGS) -c main.cpp

# Removes any files that end in .o to clean the folder
clean:
	rm $(EXECUTABLE) *.o
# this line required by make - don't delete