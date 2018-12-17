CC := gcc
EXEC := pi mighty dealer hand pitboss signal b2 b3
SRC := pi.c
CFLAG := -Wall
#GSL header file and library
INC := -I ~/src/include
LIB := -L ~/src/lib -lgsl -lgslcblas
$(EXEC):
	$(CC) $(CFLAG) -o pi $(SRC) -lm $(INC) $(LIB)
	$(CC) $(CFLAG) -o mighty mighty.c
	$(CC) $(CFLAG) -o dealer dealer.c -lm $(INC) $(LIB)
	$(CC) $(CFLAG) -o hand hand.c -lm $(INC) $(LIB)
	$(CC) $(CFLAG) -o pitboss pitboss.c
	$(CC) $(CFLAG) -o signal signal.c $(INC) $(LIB)
	$(CC) $(CFLAG) -o b2 b2.c
	$(CC) $(CFLAG) -o b3 b3.c
clean:
	rm -f $(EXEC)
	rm -f bar.txt
