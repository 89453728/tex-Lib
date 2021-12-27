GCC = g++
FLAGS = -g -Wall
EXEC = main
OFILES = main.o multi.o

all: compile
compile: $(OFILES)
	$(GCC) $(FLAGS) -o $(EXEC) $(OFILES)
%.o: %.cc %.h
	$(GCC) $(FLAGS) -c $<
clean: 
	rm -r *.o 	
