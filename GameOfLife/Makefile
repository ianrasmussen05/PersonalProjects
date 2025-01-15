EXECUTABLE := GameOfLife

SOURCES := *.cpp

INCLUDES := -I .
EXT := out
CC := g++

# -Wall checks for any warnings
CFLAGS  := -O2 -Wall

# typing 'make' will invoke the first target entry in the file
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
default: $(EXECUTABLE)

# To create the executable file count we need the object files
# UserInput.o, and main.o:
$(EXECUTABLE):  FileInput.o FileOutput.o Helper.o ClassicMode.o DoughnutMode.o MirrorMode.o UserInput.o main.o 
	$(CC) $(CFLAGS) -o $(EXECUTABLE) FileInput.o FileOutput.o Helper.o ClassicMode.o DoughnutMode.o MirrorMode.o UserInput.o main.o

FileInput.o: FileInput.cpp FileInput.h 
	$(CC) $(CFLAGS) -c FileInput.cpp

FileOutput.o: FileOutput.cpp FileOutput.h
	$(CC) $(CFLAGS) -c FileOutput.cpp

Helper.o: Helper.cpp Helper.h
	$(CC) $(CFLAGS) -c Helper.cpp

ClassicMode.o: ClassicMode.cpp ClassicMode.h
	$(CC) $(CFLAGS) -c ClassicMode.cpp

DoughnutMode.o: DoughnutMode.cpp DoughnutMode.h
	$(CC) $(CFLAGS) -c DoughnutMode.cpp

MirrorMode.o: MirrorMode.cpp MirrorMode.h
	$(CC) $(CFLAGS) -c MirrorMode.cpp

# To create the object file hashmap.o, we need the source files
# UserInput.cpp UserInput.h:
UserInput.o:  UserInput.cpp UserInput.h
	$(CC) $(CFLAGS) -c UserInput.cpp

# To create the object file main.o, we need the source files
# main.cpp, UserInput.cpp, UserInput.h:
main.o: main.cpp FileInput.cpp FileInput.h FileOutput.cpp FileOutput.h Helper.cpp Helper.h ClassicMode.cpp ClassicMode.h DoughnutMode.cpp DoughnutMode.h MirrorMode.cpp MirrorMode.h UserInput.cpp UserInput.h
	$(CC) $(CFLAGS) -c main.cpp

# Removes any files that end in .o to clean the folder
clean:
	rm $(EXECUTABLE) *.o
# this line required by make - don't delete