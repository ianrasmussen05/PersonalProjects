EXECUTABLE := generate

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
# Student.o, CSV_Reader.o, Randomize.o, and main.o:
$(EXECUTABLE):  Student.o CSV_Reader.o Randomize.o main.o 
	$(CC) $(CFLAGS) -o $(EXECUTABLE) Student.o CSV_Reader.o Randomize.o main.o

# To create the object file Student.o, we need the source files
# Student.cpp and Student.h:
Student.o:  Student.cpp Student.h
	$(CC) $(CFLAGS) -c Student.cpp

# To create the object file CSV_Reader.o, we need the source files
# CSV_Reader.cpp and CSV_Reader.h:
CSV_Reader.o: CSV_Reader.cpp CSV_Reader.h
	$(CC) $(CFLAGS) -c CSV_Reader.cpp

# To create the object file Randomize.o, we need the source files
# Randomize.cpp and Randomize.h:
Randomize.o:  Randomize.cpp Randomize.h
	$(CC) $(CFLAGS) -c Randomize.cpp

# To create the object file main.o, we need the source files
# main.cpp, Student.cpp, Student.h, CSV_Reader.cpp, CSV_Reader.h, Randomize.cpp, and Randomize.h:
main.o: main.cpp Student.cpp Student.h CSV_Reader.cpp CSV_Reader.h Randomize.cpp Randomize.h
	$(CC) $(CFLAGS) -c main.cpp

# Removes any files that end in .o to clean the folder
clean:
	rm $(EXECUTABLE) *.o
# this line required by make - don't delete