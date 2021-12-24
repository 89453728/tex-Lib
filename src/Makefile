GCC = g++
CFLAGS = -g -std=c++11 -Wall 
MAIN = main
CMAIN := $(MAIN).cc
OFILES = parse.o
TEST = ../test/

all: move

%.o: %.cc %.h
	$(GCC) $(CFLAGS) -c $<
move: %.o
	@echo "making a copy of .o files at test directory"
	@cp *.o ../test/
test: move
	$(GCC) $(CFLAGS) -c $(TEST)$(CMAIN)-o $(TEST)$(MAIN).o
	$(GCC) $(CFLAGS) -o $(TEST)$(MAIN) $(TEST)$(MAIN).o $(TEST)$(OFILES)
run: test
	@echo "running main test file"
	./$(TEST)$(MAIN)
clean: 
	rm *.o $(TEST)/*.o
	@echo "all .o files cleaned"

